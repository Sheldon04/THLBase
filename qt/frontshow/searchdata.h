#ifndef SEARCHDATA_H
#define SEARCHDATA_H

#include <QWidget>
#include <QButtonGroup>
#include <oneSearchInfo.h>
#include "global.h"
#include "databasemanager.h"

using std::vector;
namespace Ui {
class SearchData;
}

class SearchData : public QWidget
{
    Q_OBJECT

public:
    explicit SearchData(QWidget *parent = nullptr);
    ~SearchData();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SearchData *ui;
    QButtonGroup *bg;

public:
    bool MIR_NamesFromDB(QString partStr, vector<oneSearchInfo> &resultInfos);
    bool MIR_SeqFromDB(QString partStr, vector<oneSearchInfo> &resultInfos);
};

#endif // SEARCHDATA_H
