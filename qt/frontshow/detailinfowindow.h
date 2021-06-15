#ifndef DETAILINFOWINDOW_H
#define DETAILINFOWINDOW_H

#include <QWidget>
#include "global.h"
#include "oneSearchInfo.h"

namespace Ui {
class DetailInfoWindow;
}

class DetailInfoWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DetailInfoWindow(QWidget *parent = nullptr);

    DetailInfoWindow(oneSearchInfo & info);

    ~DetailInfoWindow();

private:
    Ui::DetailInfoWindow *ui;
};

#endif // DETAILINFOWINDOW_H
