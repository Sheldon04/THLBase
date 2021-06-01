#include "datavisualize.h"
#include "ui_datavisualize.h"

DataVisualize::DataVisualize(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataVisualize)
{
    ui->setupUi(this);
    populateThemeBox();
    ui->tabWidget->addTab(generateTotalChart(), "总览");

    QPalette pal = qApp->palette();
    pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
    pal.setColor(QPalette::WindowText, QRgb(0x404044));
    qApp->setPalette(pal);

    on_themeComboBox_currentIndexChanged(0);
}

DataVisualize::~DataVisualize()
{
    delete ui;
}

void DataVisualize::populateThemeBox()
{
    // add items to theme combobox
    ui->themeComboBox->addItem("Light", QChart::ChartThemeLight);
    ui->themeComboBox->addItem("Blue Cerulean", QChart::ChartThemeBlueCerulean);
    ui->themeComboBox->addItem("Dark", QChart::ChartThemeDark);
    ui->themeComboBox->addItem("Brown Sand", QChart::ChartThemeBrownSand);
    ui->themeComboBox->addItem("Blue NCS", QChart::ChartThemeBlueNcs);
    ui->themeComboBox->addItem("High Contrast", QChart::ChartThemeHighContrast);
    ui->themeComboBox->addItem("Blue Icy", QChart::ChartThemeBlueIcy);
    ui->themeComboBox->addItem("Qt", QChart::ChartThemeQt);
}

QWidget *DataVisualize::generateTotalChart()
{
    std::map<int, int> lens, type, level;
    DataBaseManager::getSummary(lens, type, level);
    QWidget *page = new QWidget();
    QGridLayout *grid = new QGridLayout();
    page->setLayout(grid);

    QChartView *chartView;
    chartView = generateLensChart(lens);
    grid->addWidget(chartView, 0, 0, 1, 2);
    this->charts << chartView;

    chartView = generateTypeChart(type);
    grid->addWidget(chartView, 1, 0);
    this->charts << chartView;

    chartView = generateLevelChart(level);
    grid->addWidget(chartView, 1, 1);
    this->charts << chartView;

    return page;
}

QChartView *DataVisualize::generateLensChart(std::map<int, int> lens)
{
//    DataBaseManager::countLens(lens);
    int max = -1, min = 100, vmax = -1, vmin = INF;

    for (auto item : lens)
    {
        if (item.first > max) max = item.first;
        if (item.first < min) min = item.first;
    }

    QBarSeries *series = new QBarSeries();
    QStringList categories;

    QBarSet *set = new QBarSet("Length");
    for (int i = min; i <= max; i++)
    {
        vmax = lens[i] > vmax ? lens[i] : vmax;
        vmin = lens[i] < vmin ? lens[i] : vmin;
        *set << lens[i];
        categories << QString::number(i);
        series->append(set);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("The length distribution of the miRNA");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,vmax + 10);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}

QChartView *DataVisualize::generateTypeChart(std::map<int, int> type)
{
    QPieSeries *series = new QPieSeries();
    series->append("3'", type[0]);
    series->append("5'", type[1]);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("The type of the miRNA");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    connect(series->slices().at(0), &QPieSlice::hovered, this, &DataVisualize::showHightLight);
    connect(series->slices().at(1), &QPieSlice::hovered, this, &DataVisualize::showHightLight);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    return chartView;
}

QChartView *DataVisualize::generateLevelChart(std::map<int, int> Level)
{
    QPieSeries *series = new QPieSeries();
    series->append("low", Level[0]);
    series->append("middle", Level[1]);
    series->append("high", Level[1]);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("The expression level of the miRNA");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    connect(series->slices().at(0), &QPieSlice::hovered, this, &DataVisualize::showHightLight);
    connect(series->slices().at(1), &QPieSlice::hovered, this, &DataVisualize::showHightLight);
    connect(series->slices().at(2), &QPieSlice::hovered, this, &DataVisualize::showHightLight);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    return chartView;
}

void DataVisualize::showHightLight(bool show)
{
    QPieSlice *slice = qobject_cast<QPieSlice*>(sender());
    slice->setExploded(show);
}

void DataVisualize::updateUI()
{
    qDebug() << "here" << endl;
    QChart::ChartTheme theme = static_cast<QChart::ChartTheme>(
                ui->themeComboBox->itemData(ui->themeComboBox->currentIndex()).toInt());

    const auto charts = this->charts;
    if (charts.isEmpty())
        qDebug() << "???" << endl;
    if (!charts.isEmpty() && charts.at(0)->chart()->theme() != theme) {
        for (QChartView *chartView : charts) {
            qDebug() << "here" << endl;
            chartView->chart()->setTheme(theme);
        }
//        // Set palette colors based on selected theme
//        QPalette pal = window()->palette();
//        if (theme == QChart::ChartThemeLight) {
//            pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
//            pal.setColor(QPalette::WindowText, QRgb(0x404044));
//        //![8]
//        } else if (theme == QChart::ChartThemeDark) {
//            pal.setColor(QPalette::Window, QRgb(0x121218));
//            pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
//        } else if (theme == QChart::ChartThemeBlueCerulean) {
//            pal.setColor(QPalette::Window, QRgb(0x40434a));
//            pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
//        } else if (theme == QChart::ChartThemeBrownSand) {
//            pal.setColor(QPalette::Window, QRgb(0x9e8965));
//            pal.setColor(QPalette::WindowText, QRgb(0x404044));
//        } else if (theme == QChart::ChartThemeBlueNcs) {
//            pal.setColor(QPalette::Window, QRgb(0x018bba));
//            pal.setColor(QPalette::WindowText, QRgb(0x404044));
//        } else if (theme == QChart::ChartThemeHighContrast) {
//            pal.setColor(QPalette::Window, QRgb(0xffab03));
//            pal.setColor(QPalette::WindowText, QRgb(0x181818));
//        } else if (theme == QChart::ChartThemeBlueIcy) {
//            pal.setColor(QPalette::Window, QRgb(0xcee7f0));
//            pal.setColor(QPalette::WindowText, QRgb(0x404044));
//        } else {
//            pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
//            pal.setColor(QPalette::WindowText, QRgb(0x404044));
//        }
//        window()->setPalette(pal);
    }

//    // Update antialiasing
//    //![11]
//    bool checked = m_ui->antialiasCheckBox->isChecked();
//    for (QChartView *chart : charts)
//        chart->setRenderHint(QPainter::Antialiasing, checked);
//    //![11]

//    // Update animation options
//    //![9]
//    QChart::AnimationOptions options(
//                m_ui->animatedComboBox->itemData(m_ui->animatedComboBox->currentIndex()).toInt());
//    if (!m_charts.isEmpty() && m_charts.at(0)->chart()->animationOptions() != options) {
//        for (QChartView *chartView : charts)
//            chartView->chart()->setAnimationOptions(options);
//    }
//    //![9]

//    // Update legend alignment
//    //![10]
//    Qt::Alignment alignment(
//                m_ui->legendComboBox->itemData(m_ui->legendComboBox->currentIndex()).toInt());

//    if (!alignment) {
//        for (QChartView *chartView : charts)
//            chartView->chart()->legend()->hide();
//    } else {
//        for (QChartView *chartView : charts) {
//            chartView->chart()->legend()->setAlignment(alignment);
//            chartView->chart()->legend()->show();
//        }
//    }
//    //![10]
}

void DataVisualize::on_themeComboBox_currentIndexChanged(int index)
{
    qDebug() << "here" << endl;
    QChart::ChartTheme theme = static_cast<QChart::ChartTheme>(
                ui->themeComboBox->itemData(index).toInt());

    const auto charts = this->charts;
    if (charts.isEmpty())
        qDebug() << "???" << endl;
    if (!charts.isEmpty() && charts.at(0)->chart()->theme() != theme) {
        for (QChartView *chartView : charts) {
            qDebug() << "here" << endl;
            chartView->chart()->setTheme(theme);
        }
//        // Set palette colors based on selected theme
//        QPalette pal = window()->palette();
//        if (theme == QChart::ChartThemeLight) {
//            pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
//            pal.setColor(QPalette::WindowText, QRgb(0x404044));
//        //![8]
//        } else if (theme == QChart::ChartThemeDark) {
//            pal.setColor(QPalette::Window, QRgb(0x121218));
//            pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
//        } else if (theme == QChart::ChartThemeBlueCerulean) {
//            pal.setColor(QPalette::Window, QRgb(0x40434a));
//            pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
//        } else if (theme == QChart::ChartThemeBrownSand) {
//            pal.setColor(QPalette::Window, QRgb(0x9e8965));
//            pal.setColor(QPalette::WindowText, QRgb(0x404044));
//        } else if (theme == QChart::ChartThemeBlueNcs) {
//            pal.setColor(QPalette::Window, QRgb(0x018bba));
//            pal.setColor(QPalette::WindowText, QRgb(0x404044));
//        } else if (theme == QChart::ChartThemeHighContrast) {
//            pal.setColor(QPalette::Window, QRgb(0xffab03));
//            pal.setColor(QPalette::WindowText, QRgb(0x181818));
//        } else if (theme == QChart::ChartThemeBlueIcy) {
//            pal.setColor(QPalette::Window, QRgb(0xcee7f0));
//            pal.setColor(QPalette::WindowText, QRgb(0x404044));
//        } else {
//            pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
//            pal.setColor(QPalette::WindowText, QRgb(0x404044));
//        }
//        window()->setPalette(pal);
    }
}
