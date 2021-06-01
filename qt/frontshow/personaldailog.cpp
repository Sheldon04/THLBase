#include "personaldailog.h"
#include "ui_personaldailog.h"
#include <searchdata.h>
#include "addrecord.h"
#include "databasemanager.h"
#include "datavisualize.h"
#include <QMovie>
PersonalDailog::PersonalDailog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonalDailog)
{
    ui->setupUi(this);

    ui->movieLabel->setScaledContents(true);
    QMovie *iconShow = new QMovie(":/new/prefix1/images/back.png");
    ui->movieLabel->setMovie(iconShow);
    iconShow->start();

    ui->pushButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->pushButton_3->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
        ui->pushButton_2->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");

    DataBaseManager::init();
}

PersonalDailog::~PersonalDailog()
{
    delete ui;
}

// 向数据库中增加数据
void PersonalDailog::on_pushButton_clicked()
{
    AddRecord *newDialog = new AddRecord();
    newDialog->show();
}


// 查找数据库中的数据
void PersonalDailog::on_pushButton_3_clicked()
{

    SearchData* newDialog = new SearchData();
    newDialog->show();

}


void PersonalDailog::on_pushButton_2_clicked()
{
    DataVisualize *view = new DataVisualize();
    view->show();
}
