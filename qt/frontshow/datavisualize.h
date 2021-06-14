#ifndef DATAVISUALIZE_H
#define DATAVISUALIZE_H

#include <QWidget>
#include <QChart>
#include <QChartView>
#include <QList>
#include <QGridLayout>
#include <QBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QPieSeries>
#include "databasemanager.h"
#include "global.h"

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class DataVisualize;
}

class DataVisualize : public QWidget
{
    Q_OBJECT

public:
    explicit DataVisualize(QWidget *parent = nullptr);
    ~DataVisualize();

private:
    Ui::DataVisualize *ui;

    QList<QChartView *> charts;

private:
    void populateThemeBox();

    QWidget * generateTotalChart();

    QWidget * generateDiffExpChart(QString mir_name);

    QChartView * generateLensChart(std::map<int, int> lens);

    QChartView * generateTypeChart(std::map<int, int> type);

    QChartView * generateLevelChart(std::map<int, int> Level);

public slots:
    void showHightLight(bool show);

private Q_SLOTS:
    void updateUI();
    void on_themeComboBox_currentIndexChanged(int index);
};

#endif // DATAVISUALIZE_H
