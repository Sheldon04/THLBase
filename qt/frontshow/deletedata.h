#ifndef DELETEDATA_H
#define DELETEDATA_H

#include <QWidget>

namespace Ui {
class DeleteData;
}

class DeleteData : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteData(QWidget *parent = nullptr);
    ~DeleteData();

private:
    Ui::DeleteData *ui;
};

#endif // DELETEDATA_H
