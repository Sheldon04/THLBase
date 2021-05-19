#include "statistic.h"
#include "ui_statistic.h"
#include <QtCharts>

Statistic::Statistic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Statistic)
{
    ui->setupUi(this);

    /*
     * LineChart Example
     */
    //添加一个QLineSeries实例
    QLineSeries *lineseries = new QLineSeries();
    //添加数据（点），有两种方式
    lineseries->append(0, 6);  //参数分别为横纵坐标
    lineseries->append(2, 4);
    lineseries->append(3, 8);
    lineseries->append(7, 4);
    *lineseries << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);
    //添加一个QChart实例，为了展示数据
    QChart *chart = new QChart();
    chart->legend()->hide();  //隐藏图例
    chart->addSeries(lineseries);
    chart->createDefaultAxes();
    chart->setTitle("Simple line chart example");
    //添加一个QChartView图例
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);  //呈现方式
    //显示
    QVBoxLayout *pVLayout = new QVBoxLayout(this);
    pVLayout->addWidget(chartView);
    this->resize(400, 300);
    this->show();
}

Statistic::~Statistic()
{
    delete ui;
}
