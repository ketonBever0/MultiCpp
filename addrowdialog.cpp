#include "addrowdialog.h"
#include "httpclient.h"
#include "ui_addrowdialog.h"

#include <qmessagebox.h>

AddRowDialog::AddRowDialog(const Student& s, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddRowDialog)
    , student(s)
{
    ui->setupUi(this);
    setLayout(ui->mainLayout);
    ui->methodCB->addItems(CsvTableModel::methods.values());

    ui->idTB->setText(s.id);
    ui->cardNumberTB->setText(s.cardNumber);
    ui->nameTB->setText(s.name);
    ui->methodCB->setCurrentText(s.trainingMethod == "" ? "Full-time" : CsvTableModel::methods.value(s.trainingMethod));
    ui->tokenTB->setText(s.token);
}


AddRowDialog::~AddRowDialog()
{
    delete ui;
}

Student AddRowDialog::entry() const {
    auto s = Student(ui->idTB->text(),
                     ui->cardNumberTB->text(),
                     ui->nameTB->text(),
                     CsvTableModel::methods.key(ui->methodCB->currentText()),
                     ui->tokenTB->text());
    return s;
}

void AddRowDialog::on_buttonBox_accepted()
{
    accept();
}


void AddRowDialog::on_tokenGenerateBTN_clicked()
{
    HttpClient* client = new HttpClient(this);

    connect(client, &HttpClient::responseReceived, this, [this](const QString& body){
        ui->tokenTB->setText(body);
    });

    connect(client, &HttpClient::errorOccured, this, [this](const QString& err){
        QMessageBox::warning(this, "Error", "API error.", QMessageBox::Ok);
    });

    client->get("https://generateid.dev/nanoid");
}

