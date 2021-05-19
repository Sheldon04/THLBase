#include "adddata.h"
#include "ui_adddata.h"

AddData::AddData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddData)
{
    ui->setupUi(this);
}

AddData::~AddData()
{
    delete ui;
}
