#include "entrydialog.h"
#include "ui_entrydialog.h"
#include <QDebug>
#include "personaldailog.h"
#include <QMovie>
EntryDialog::EntryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EntryDialog)
{
    ui->setupUi(this);

    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->movieLabel->setScaledContents(true);
    QMovie *iconShow = new QMovie(":/new/prefix1/images/12.gif");
    ui->movieLabel->setMovie(iconShow);
    iconShow->start();

    ui->pushButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");

}

EntryDialog::~EntryDialog()
{
    delete ui;
}


void EntryDialog::on_pushButton_clicked()
{
    // 获得字符串
    QString idStr = ui->lineEdit->text();
    QString passWordStr = ui->lineEdit_2->text();

    // 此处连接数据库


    // 如果用户名和密码一致 则进入系统




    // 如果没有一致的用户名和密码  提示输入错误


    PersonalDailog* newDialog = new PersonalDailog();
    newDialog->show();
    delete this;


}
