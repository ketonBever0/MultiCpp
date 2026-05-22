#include "addrowdialog.h"
#include "ui_addrowdialog.h"

AddRowDialog::AddRowDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddRowDialog)
{
    ui->setupUi(this);
}

AddRowDialog::~AddRowDialog()
{
    delete ui;
}
