#ifndef PERSONALDAILOG_H
#define PERSONALDAILOG_H

#include <QWidget>

namespace Ui {
class PersonalDailog;
}

class PersonalDailog : public QWidget
{
    Q_OBJECT

public:
    explicit PersonalDailog(QWidget *parent = nullptr);
    ~PersonalDailog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::PersonalDailog *ui;
};

#endif // PERSONALDAILOG_H
