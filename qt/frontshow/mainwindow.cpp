#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "entrydialog.h"
#include "register.h"
#include "aboutusdialog.h"
#include <QMovie>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->movieLabel->setScaledContents(true);
    QMovie *iconShow = new QMovie(":/new/prefix1/images/back.png");
    ui->movieLabel->setMovie(iconShow);
    iconShow->start();

    ui->label->raise();
    ui->pushButton->raise();
    ui->pushButton_2->raise();
    ui->pushButton_3->raise();

    ui->pushButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->pushButton_2->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->pushButton_3->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 登录
void MainWindow::on_pushButton_2_clicked()
{
    EntryDialog *newDialog = new EntryDialog();
    newDialog->show();
    newDialog->show();
    connect(newDialog, &EntryDialog::hideWindow, this, &MainWindow::hide);
}


// 注册
void MainWindow::on_pushButton_clicked()
{
    Register *newDialog = new Register();
    newDialog->show();
}

// About Us
void MainWindow::on_pushButton_3_clicked()
{
    AboutUsDialog* newDialog = new AboutUsDialog();
    newDialog->show();
}

void MainWindow::hide()
{
    EntryDialog *temp = qobject_cast<EntryDialog *>(sender());
    delete temp;
    this->setVisible(false);
}
