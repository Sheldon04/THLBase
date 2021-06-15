#ifndef ENV_H
#define ENV_H

#include <QWidget>
#include <QNetworkReply>

namespace Ui {
class Env;
}

class Env : public QWidget
{
    Q_OBJECT

public:
    explicit Env(QWidget *parent = nullptr);
    ~Env();

private slots:
    void on_pushButton_clicked();

    void dealMsg(QNetworkReply *reply);

    void on_pushButton_2_clicked();

private:
    Ui::Env *ui;
};

#endif // ENV_H
