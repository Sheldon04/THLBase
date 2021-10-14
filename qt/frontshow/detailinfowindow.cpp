#include "detailinfowindow.h"
#include "ui_detailinfowindow.h"

DetailInfoWindow::DetailInfoWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetailInfoWindow)
{
    ui->setupUi(this);
}

DetailInfoWindow::DetailInfoWindow(oneSearchInfo &info) :
    QWidget(nullptr),
    ui(new Ui::DetailInfoWindow)
{
    ui->setupUi(this);
    QString temp;
    qDebug() << info.miR_name << endl;
    ui->label_name->setText(info.miR_name);
    ui->textBrowser->append("miR_seq:\t" + info.miR_seq);
    ui->textBrowser->append("miR_base_seq:\t" + info.miRbase_seq);
    ui->textBrowser->append("type:\t" + info.type);
    ui->textBrowser->append("CG:\t" + info.CG);
    ui->textBrowser->append("dG:\t" + info.dG);
    ui->textBrowser->append("");

    ui->textBrowser->append("sum1(row)");
    for (int i = 0; i < 5; i++)
    {
        temp.append(info.sum1_raw[i] + " ");
    }
    ui->textBrowser->append(temp);

    temp = "";
    ui->textBrowser->append("sum2(row)");
    for (int i = 0; i < 5; i++)
    {
        temp.append(info.sum2_raw[i] + " ");
    }
    ui->textBrowser->append(temp);

    temp = "";
    ui->textBrowser->append("spr1(row)");
    for (int i = 0; i < 5; i++)
    {
        temp.append(info.spr1_raw[i] + " ");
    }
    ui->textBrowser->append(temp);

    temp = "";
    ui->textBrowser->append("spr3(row)");
    for (int i = 0; i < 5; i++)
    {
        temp.append(info.spr3_raw[i] + " ");
    }
    ui->textBrowser->append(temp);

    temp = "";
    ui->textBrowser->append("sum1(norm)");
    for (int i = 0; i < 5; i++)
    {
        temp.append(info.sum1_norm[i] + " ");
    }
    ui->textBrowser->append(temp);

    temp = "";
    ui->textBrowser->append("sum2(norm)");
    for (int i = 0; i < 5; i++)
    {
        temp.append(info.sum2_norm[i] + " ");
    }
    ui->textBrowser->append(temp);

    temp = "";
    ui->textBrowser->append("spr1(norm)");
    for (int i = 0; i < 5; i++)
    {
        temp.append(info.spr1_norm[i] + " ");
    }
    ui->textBrowser->append(temp);

    temp = "";
    ui->textBrowser->append("spr3(norm)");
    for (int i = 0; i < 5; i++)
    {
        temp.append(info.spr3_norm[i] + " ");
    }
    ui->textBrowser->append(temp);
}

DetailInfoWindow::~DetailInfoWindow()
{
    delete ui;
}
