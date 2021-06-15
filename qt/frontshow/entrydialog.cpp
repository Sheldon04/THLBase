#include "entrydialog.h"
#include "ui_entrydialog.h"
#include <QDebug>
#include "userwindow.h"
#include <QMovie>
EntryDialog::EntryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EntryDialog)
{
    ui->setupUi(this);

    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->movieLabel->setScaledContents(true);
    QMovie *iconShow = new QMovie(":/new/prefix1/images/back.png");
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
//    // 获得字符串
//    QString idStr = ui->lineEdit->text();
//    QString passWordStr = ui->lineEdit_2->text();
//    QString pass;

//    // 如果用户名和密码一致 则进入系统
//    if ( !DataBaseManager::getPassword(idStr, pass))
//    {
//        QMessageBox::warning(this, "Warning", "The id does not exist, please register first");
//        return;
//    }
//    else if (passWordStr.compare(pass) != 0)
//    {
//        QMessageBox::warning(this, "Warning", "The password is not correct" + pass);
//        return;
//    }

    // 显示登录界面
    UserWindow* newDialog = new UserWindow();
    newDialog->show();
    emit hideWindow();
}
