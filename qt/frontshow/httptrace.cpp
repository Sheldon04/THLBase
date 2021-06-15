#include "httptrace.h"
#include "ui_httptrace.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

Httptrace::Httptrace(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Httptrace)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
            ui->pushButton_2->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->textEdit->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
}

Httptrace::~Httptrace()
{
    delete ui;
}

void Httptrace::on_pushButton_clicked()
{
    QNetworkAccessManager* m_manager = new QNetworkAccessManager;
    QNetworkRequest request; request.setUrl(QUrl(QString("http://47.106.148.74:8989/actuator/httptrace")));
    m_manager->get(request);//向网页发起get请求
    connect(m_manager, SIGNAL(finished(QNetworkReply*)), this,SLOT(dealMsg(QNetworkReply*)));//请求完成,获取数据并在槽函数中进行处理
}

void Httptrace::dealMsg(QNetworkReply *reply)//对数据进行解析
{
    QByteArray array = reply->readAll();
    QJsonParseError error;
    QJsonDocument data = QJsonDocument::fromJson(array, &error);
    if (!data.isNull()) {
        QJsonObject obj = data.object();
        //qDebug() << QString(QJsonDocument(obj).toJson(QJsonDocument::Compact));
        QJsonValue val = obj.value("traces");
        QJsonArray jarr = val.toArray();

        for (int m = 0; m < jarr.size(); m++) { // 对于每一条访问数据
            QJsonValue val1 = jarr[m];
            qDebug() << val1["timestamp"];
            ui->textEdit->append("Record " + QString::number(m+1) + ": ");

            ui->textEdit->append("timestamp: " + val1["timestamp"].toString());
            //ui->textEdit->append(val1["principal"].toString());
            //ui->textEdit->append(val1["session"].toString());
            ui->textEdit->append("request/method: " + val1["request"]["method"].toString());
            ui->textEdit->append("request/uri" + val1["request"]["uri"].toString());
            ui->textEdit->append("");
        }

    }
     reply->deleteLater();
}

void Httptrace::on_pushButton_2_clicked()
{
    ui->textEdit->setText("");
}
