#ifndef ADDDATA_H
#define ADDDATA_H

#include <QWidget>

namespace Ui {
class AddData;
}

class AddData : public QWidget
{
    Q_OBJECT

public:
    explicit AddData(QWidget *parent = nullptr);
    ~AddData();

private:
    Ui::AddData *ui;
};

#endif // ADDDATA_H
