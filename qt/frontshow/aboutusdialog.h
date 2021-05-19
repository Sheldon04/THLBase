#ifndef ABOUTUSDIALOG_H
#define ABOUTUSDIALOG_H

#include <QWidget>

namespace Ui {
class AboutUsDialog;
}

class AboutUsDialog : public QWidget
{
    Q_OBJECT

public:
    explicit AboutUsDialog(QWidget *parent = nullptr);
    ~AboutUsDialog();

private:
    Ui::AboutUsDialog *ui;
};

#endif // ABOUTUSDIALOG_H
