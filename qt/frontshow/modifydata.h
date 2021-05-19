#ifndef MODIFYDATA_H
#define MODIFYDATA_H

#include <QWidget>

namespace Ui {
class ModifyData;
}

class ModifyData : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyData(QWidget *parent = nullptr);
    ~ModifyData();

private:
    Ui::ModifyData *ui;
};

#endif // MODIFYDATA_H
