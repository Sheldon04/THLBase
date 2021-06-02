#ifndef ADDRECORD_H
#define ADDRECORD_H

#include <QWidget>
#include "databasemanager.h"

namespace Ui {
class AddRecord;
}

class AddRecord : public QWidget
{
    Q_OBJECT

public:
    explicit AddRecord(QWidget *parent = nullptr);
    ~AddRecord();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::AddRecord *ui;

    QStringList fileNames;
};

#endif // ADDRECORD_H
