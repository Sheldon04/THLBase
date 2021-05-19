#include "searchdata.h"
#include "ui_searchdata.h"
#include <QButtonGroup>
#include <QDebug>
#include <QMovie>
#include <QHeaderView>
SearchData::SearchData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchData)
{
    ui->setupUi(this);

    bg=new QButtonGroup(this);
    bg->addButton(ui->radioButton,0);//一个值为0
    bg->addButton(ui->radioButton_2,1);//一个值为1
    ui->radioButton->setChecked(true);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中的方

    ui->movieLabel->setScaledContents(true);
    QMovie *iconShow = new QMovie(":/new/prefix1/images/12.gif");
    ui->movieLabel->setMovie(iconShow);
    iconShow->start();

    ui->pushButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->pushButton_2->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    //ui->tableWidget->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    //ui->textEdit->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");

    ui->lineEdit->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");


    QStringList headerList;
    headerList << "rep_miRID" << "miRBase_seq" << "miR_seq" << "rep_miRID"
        << "miRBase_seq" << "type"<< "CG" << "dG"<< "Sum11(raw)" << "Sum12(raw)"<< "Sum13(raw)" << "Sum14(raw)"
        << "Sum15(raw)" << "Sum21(raw)"<< "Sum22(raw)" << "Sum23(raw)"<< "Sum24(raw)" << "Sum25(raw)"<< "Spr11(raw)" << "Spr12(raw)"
        << "Spr13(raw)" << "Spr14(raw)"<< "Spr15(raw)" << "Spr31(raw)"<< "Spr32(raw)" << "Spr33(raw)"<< "Spr34(raw)" << "Spr35(raw)"
        << "Sum11(norm)" << "Sum12(norm)"  << "Sum13(norm)" << "Sum14(norm)"<< "Sum15(norm)" << "Sum21(norm)"<< "Sum22(norm)" << "Sum23(norm)"<< "Sum24(norm)" << "Sum25(norm)"
        << "Spr11(norm)" << "Spr12(norm)"<< "Spr13(norm)" << "Spr14(norm)"<< "Spr15(norm)" << "Spr31(norm)" << "Spr32(norm)"
           << "Spr33(norm)" << "Spr34(norm)"<< "Spr35(norm)" << "Expression level" ;

           ui->tableWidget->setHorizontalHeaderLabels(headerList);
    //QHeaderView *hview = ui->


}

SearchData::~SearchData()
{
    delete ui;
}


// 确认按钮  开始查找
void SearchData::on_pushButton_clicked()
{
    // 获取当前输入文本
    QString searchStr = ui->lineEdit->text();
    int sel= bg->checkedId();//取到所选的radioButton的值
    vector<oneSearchInfo> searchResult;


    switch(sel)
    {
    case 0:
        // 查找miR_name
        //qDebug() << "miR_name" << endl;

        // 注意 这里涉及到大数组的拷贝 可能会影响程序运行速度  建议把函数内的内容直接写这里
        MIR_NamesFromDB(searchStr, searchResult);

        break;
    case 1:
        // 查找miR_seq
        //qDebug() << "miR_seq" << endl;

        // 注意 这里涉及到大数组的拷贝 可能会影响程序运行速度  建议把函数内的内容直接写这里
        MIR_SeqFromDB(searchStr, searchResult);
        break;
    default:
        qDebug() << "Program Wrong! You select no 1 or 2" << endl;
        return; // 函数终止
    }

    // 在得到结果之后

    if (searchResult.size() == 0) { // 如果数组大小为空
        QMessageBox::information(this, "Notation", "No such information");
    } else { // 数组不为空  含有查找信息
        // 将查找信息呈现并统计
        for (size_t i = 0; i < searchResult.size(); i++) {
            ui->tableWidget->setItem(int(i), 0, new QTableWidgetItem(searchResult[i].miR_index));
            ui->tableWidget->setItem(int(i), 1, new QTableWidgetItem(searchResult[i].miR_name));
            ui->tableWidget->setItem(int(i), 2, new QTableWidgetItem(searchResult[i].miR_seq));
            ui->tableWidget->setItem(int(i), 3, new QTableWidgetItem(searchResult[i].rep_miRIDl));
            ui->tableWidget->setItem(int(i), 4, new QTableWidgetItem(searchResult[i].miRbase_seq));
            ui->tableWidget->setItem(int(i), 5, new QTableWidgetItem(searchResult[i].type));
            ui->tableWidget->setItem(int(i), 6, new QTableWidgetItem(searchResult[i].CG));
            ui->tableWidget->setItem(int(i), 7, new QTableWidgetItem(searchResult[i].dG));

            int numLabel = 8;
            for (size_t m = 0; m < searchResult[i].sum1_raw.size(); m++) {
                ui->tableWidget->setItem(int(i), int(numLabel+m), new QTableWidgetItem(searchResult[i].sum1_raw[m]));
            }
            numLabel = numLabel + int(searchResult[i].sum1_raw.size());

            for (size_t m = 0; m < searchResult[i].sum2_raw.size(); m++) {
                ui->tableWidget->setItem(int(i), int(numLabel+m), new QTableWidgetItem(searchResult[i].sum2_raw[m]));
            }
            numLabel = numLabel + int(searchResult[i].sum2_raw.size());

            for (size_t m = 0; m < searchResult[i].spr1_raw.size(); m++) {
                ui->tableWidget->setItem(int(i), int(numLabel+m), new QTableWidgetItem(searchResult[i].spr1_raw[m]));
            }
            numLabel = numLabel + int(searchResult[i].spr1_raw.size());

            for (size_t m = 0; m < searchResult[i].spr3_raw.size(); m++) {
                ui->tableWidget->setItem(int(i), int(numLabel+m), new QTableWidgetItem(searchResult[i].spr3_raw[m]));
            }
            numLabel = numLabel + int(searchResult[i].spr3_raw.size());

            for (size_t m = 0; m < searchResult[i].sum1_norm.size(); m++) {
                ui->tableWidget->setItem(int(i), int(numLabel+m), new QTableWidgetItem(searchResult[i].sum1_norm[m]));
            }
            numLabel = numLabel + int(searchResult[i].sum1_norm.size());

            for (size_t m = 0; m < searchResult[i].sum2_norm.size(); m++) {
                ui->tableWidget->setItem(int(i), int(numLabel+m), new QTableWidgetItem(searchResult[i].sum2_norm[m]));
            }
            numLabel = numLabel + int(searchResult[i].sum2_norm.size());

            for (size_t m = 0; m < searchResult[i].spr1_norm.size(); m++) {
                ui->tableWidget->setItem(int(i), int(numLabel+m), new QTableWidgetItem(searchResult[i].spr1_norm[m]));
            }
            numLabel = numLabel + int(searchResult[i].spr1_norm.size());

            for (size_t m = 0; m < searchResult[i].spr3_norm.size(); m++) {
                ui->tableWidget->setItem(int(i), int(numLabel+m), new QTableWidgetItem(searchResult[i].spr3_norm[m]));
            }
            numLabel = numLabel + int(searchResult[i].spr3_norm.size());

            ui->tableWidget->setItem(int(i), numLabel, new QTableWidgetItem(searchResult[i].expression_level));
        }

    }
}

// 通过miR_name 的一部分来从数据库中查找所有有可能的值并返回
bool SearchData::MIR_NamesFromDB(QString partStr, vector<oneSearchInfo> &resultInfos) {
    return DataBaseManager::searchAllInfo(partStr, resultInfos, 0);
}


// 通过miR_seq 的一部分来从数据库中查找所有有可能的值并返回
bool SearchData::MIR_SeqFromDB(QString partStr, vector<oneSearchInfo> &resultInfos) {
    return DataBaseManager::searchAllInfo(partStr, resultInfos, 1);
}



void SearchData::on_pushButton_2_clicked()
{
    ui->tableWidget->clearContents();
}
