#ifndef ADDROWDIALOG_H
#define ADDROWDIALOG_H

#include "csvtablemodel.h"

#include <QDialog>

namespace Ui {
class AddRowDialog;
}

class AddRowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddRowDialog(const Student& s, QWidget *parent = nullptr);
    ~AddRowDialog();

    Student entry() const;

private slots:
    void on_buttonBox_accepted();

    void on_tokenGenerateBTN_clicked();

private:
    Ui::AddRowDialog *ui;

    Student student;
};

#endif // ADDROWDIALOG_H
