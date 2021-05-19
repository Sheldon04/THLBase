#include "modifydata.h"
#include "ui_modifydata.h"

ModifyData::ModifyData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifyData)
{
    ui->setupUi(this);
}

ModifyData::~ModifyData()
{
    delete ui;
}
