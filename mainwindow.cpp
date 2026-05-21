#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QTableView"

#include "QMessageBox"
#include "csvtablemodel.h"

#include <QFileDialog>

CsvTableModel* model;
QString currentFilePath;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new CsvTableModel(this);

    ui->sTable->setModel(model);
    setCentralWidget(ui->sTable);

    QObject::connect(model, &CsvTableModel::modifiedChanged, this, &MainWindow::updateWindowTitle);

    MainWindow::updateWindowTitle(false);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateWindowTitle(bool modified = false) {
    QString title = currentFilePath.isEmpty() ? "Untitled" : QFileInfo(currentFilePath).fileName();
    if (modified) title = '*' + title;
    setWindowTitle(title);
}

void saveFile() {
    // TODO: Implement
}

void MainWindow::on_actionExit_triggered()
{
    close();
}


void MainWindow::on_actionInfo_triggered()
{
    QMessageBox::about(this, "Created by", "Kurucz László (Z5RFY1)");
}


void MainWindow::on_action_New_triggered()
{
    if(model->isModified()) {
        auto reply = QMessageBox::question(
            this,
            "New File",
            "You have unsaved work. Do You want to Save it?",
            QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel
            );

        if (reply == QMessageBox::Cancel) {
            return;
        }

        if (reply == QMessageBox::Yes) {
            saveFile();
        }
    }

    model->clear();
    currentFilePath.clear();
    MainWindow::updateWindowTitle();
}


void MainWindow::on_action_Open_triggered()
{
    QString result = QFileDialog::getOpenFileName(
        this,
        tr("Open CSV"),
        "",
        tr("CSV Files (*.csv)")
    );

    if (!result.isEmpty()) {
        currentFilePath = result;
        model->loadFromCsv(currentFilePath);
        this->setWindowTitle(currentFilePath);
        MainWindow::updateWindowTitle();
    }
}

