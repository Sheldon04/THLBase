#include <searchdata.h>
#include <QGridLayout>
#include "addrecord.h"
#include "databasemanager.h"
#include "datavisualize.h"
#include <QMovie>

#include "userwindow.h"
#include "ui_userwindow.h"

UserWindow::UserWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserWindow)
{
    ui->setupUi(this);

    ui->movieLabel->setScaledContents(true);
    QMovie *iconShow = new QMovie(":/new/prefix1/images/back.png");
    ui->movieLabel->setMovie(iconShow);
    iconShow->start();

//    ui->pushButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
//    ui->pushButton_3->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
//        ui->pushButton_2->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");

    DataBaseManager::init();
    ui->tabWidget->addTab(new DataVisualize(), "Data Visualization");
    ui->tabWidget->addTab(new SearchData(), "Search");
    ui->tabWidget->addTab(new AddRecord(), "Add Record");
    ui->tabWidget->setLayout(new QGridLayout());

    this->dbMgr = new DataBaseManager();
}

UserWindow::~UserWindow()
{
    delete ui;
}
