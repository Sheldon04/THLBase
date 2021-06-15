#ifndef HTTPTRACE_H
#define HTTPTRACE_H

#include <QWidget>
#include <QtNetwork/QNetworkReply>

namespace Ui {
class Httptrace;
}

class Httptrace : public QWidget
{
    Q_OBJECT

public:
    explicit Httptrace(QWidget *parent = nullptr);
    ~Httptrace();

private slots:
    void on_pushButton_clicked();

    void dealMsg(QNetworkReply * reply);//对数据进行解析
    void on_pushButton_2_clicked();

private:
    Ui::Httptrace *ui;
};

#endif // HTTPTRACE_H
