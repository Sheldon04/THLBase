#ifndef ENTRYDIALOG_H
#define ENTRYDIALOG_H

#include <QDialog>

namespace Ui {
class EntryDialog;
}

class EntryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EntryDialog(QWidget *parent = nullptr);
    ~EntryDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::EntryDialog *ui;

signals:
    void hideWindow();
};

#endif // ENTRYDIALOG_H
