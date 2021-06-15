#include "env.h"
#include "ui_env.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


Env::Env(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Env)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
        ui->pushButton_2->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");

    ui->textEdit->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
}

Env::~Env()
{
    delete ui;
}

void Env::on_pushButton_clicked()
{
    QNetworkAccessManager* m_manager = new QNetworkAccessManager;
    QNetworkRequest request; request.setUrl(QUrl(QString("http://47.106.148.74:8989/actuator/env")));
    m_manager->get(request);//向网页发起get请求
    connect(m_manager, SIGNAL(finished(QNetworkReply*)), this,SLOT(dealMsg(QNetworkReply*)));//请求完成,获取数据并在槽函数中进行处理
}

void Env::dealMsg(QNetworkReply *reply) {
    QByteArray array = reply->readAll();
    QJsonParseError error;
    QJsonDocument data = QJsonDocument::fromJson(array, &error);
    QString httpStr = QString(data.toJson(QJsonDocument::Compact));
    ui->textEdit->append(httpStr);

    //if (!data.isNull()) {
        //QJsonObject obj = data.object();
        //qDebug() << QString(QJsonDocument(obj).toJson(QJsonDocument::Compact));
        //QJsonValue val = obj.value("propertySources");
        //QJsonArray jarr = val.toArray();
        //for (int i = 0; i < jarr.size(); i++) {
            //QJsonValue val1 = jarr[i];
            //ui->textEdit->append(val1["name"].toString());
            //ui->textEdit->append(QString(val1["properties"]));
        //}

    //}
     reply->deleteLater();
}

void Env::on_pushButton_2_clicked()
{
    ui->textEdit->setText("");
}
