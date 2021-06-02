#include "aboutusdialog.h"
#include "ui_aboutusdialog.h"
#include <QMovie>

AboutUsDialog::AboutUsDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutUsDialog)
{
    ui->setupUi(this);
    ui->movieLabel->setScaledContents(true);
    QMovie *iconShow = new QMovie(":/new/prefix1/images/back.png");
    ui->movieLabel->setMovie(iconShow);
    iconShow->start();
}

AboutUsDialog::~AboutUsDialog()
{
    delete ui;
}
