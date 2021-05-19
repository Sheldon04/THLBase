#include "personaldailog.h"
#include "ui_personaldailog.h"
#include "statistic.h"
#include <searchdata.h>
#include <QMovie>
PersonalDailog::PersonalDailog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonalDailog)
{
    ui->setupUi(this);

    ui->movieLabel->setScaledContents(true);
    QMovie *iconShow = new QMovie(":/new/prefix1/images/12.gif");
    ui->movieLabel->setMovie(iconShow);
    iconShow->start();

    ui->pushButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
        ui->pushButton_2->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
            ui->pushButton_3->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
                ui->pushButton_4->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
}

PersonalDailog::~PersonalDailog()
{
    delete ui;
}

// 向数据库中增加数据
void PersonalDailog::on_pushButton_clicked()
{







}

// 删除数据库中指定数据
void PersonalDailog::on_pushButton_2_clicked()
{




}

// 查找数据库中的数据
void PersonalDailog::on_pushButton_3_clicked()
{

    SearchData* newDialog = new SearchData();
    newDialog->show();




}

// 修改数据库中的数据
void PersonalDailog::on_pushButton_4_clicked()
{

}
