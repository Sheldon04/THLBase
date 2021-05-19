#include "deletedata.h"
#include "ui_deletedata.h"

DeleteData::DeleteData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteData)
{
    ui->setupUi(this);
}

DeleteData::~DeleteData()
{
    delete ui;
}
