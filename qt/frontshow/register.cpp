#include "register.h"
#include "ui_register.h"
#include <QMovie>

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);

    ui->label_8->setScaledContents(true);
    QMovie *iconShow = new QMovie(":/new/prefix1/images/back.png");
    ui->label_8->setMovie(iconShow);
    iconShow->start();

    ui->pushButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
        ui->pushButton_2->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_2_clicked()
{
    delete this;
}

void Register::on_pushButton_clicked()
{
    QString idSet = ui->lineEdit->text();
    QString passWordSet = ui->lineEdit_2->text();
    QString confirmSet = ui->lineEdit_3->text();
    QString realNameSet = ui->lineEdit_4->text();
    QString mailSet = ui->lineEdit_5->text();
    QString phoneSet = ui->lineEdit_6->text();



    // 判断id和数据库中不重复且不为空



    // 判断 passWord不为空


    // 判断 confirm 与password 一致



    // 判断真实姓名不为空



    // 判断mailSet不为空


    // 判断手机号不为空



    //以上条件都满足 将此信息们导入数据库 作为个人账号信息

}
