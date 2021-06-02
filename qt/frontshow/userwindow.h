#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QWidget>
#include "databasemanager.h"

namespace Ui {
class UserWindow;
}

class UserWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UserWindow(QWidget *parent = nullptr);
    ~UserWindow();

private:
    Ui::UserWindow *ui;

    DataBaseManager *dbMgr;
};

#endif // USERWINDOW_H
