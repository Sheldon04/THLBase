#ifndef SEARCHDATA_H
#define SEARCHDATA_H

#include <QWidget>
#include <QButtonGroup>
#include <oneSearchInfo.h>
#include <QMenu>
#include <QAction>
#include <QTableWidgetSelectionRange>
#include <QInputDialog>
#include "global.h"
#include "databasemanager.h"
#include "service.h"
#include "avltree.h"

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

    void on_pushButton_3_clicked();

    void on_checkBox_stateChanged(int arg1);

    void show_menu(const QPoint pos);

    void on_tableWidget_cellChanged(int row, int column);

    void on_pushButton_4_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void deleteItems();

    void on_pushButton_5_clicked();

    void on_checkBox_2_stateChanged(int arg1);

    void on_pushButton_6_clicked();

    void updateExpInfoTable();

    void on_comboBox_currentIndexChanged(int index);

    void on_bt_detail_clicked();

private:
    Ui::SearchData *ui;
    QButtonGroup *bg;

    vector<oneSearchInfo> searchResult;

    AVLTree * avl_t = new AVLTree();

    std::map<QString, std::map<QString, QString> > modifyBuffer;

    bool modifyMode = false;

    bool encryption = false;

    // debug
    void show();


public:
    bool MIR_NamesFromDB(QString partStr, vector<oneSearchInfo> &resultInfos);
    bool MIR_SeqFromDB(QString partStr, vector<oneSearchInfo> &resultInfos);
};

#endif // SEARCHDATA_H
