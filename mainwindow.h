#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    void updateWindowTitle(bool modified);

    ~MainWindow() override;

    void keyPressEvent(QKeyEvent *event) override;

    void openEditDialog(const QModelIndex& index);

    bool maybeSave();

    void saveFile();

    void saveFileAs();

    void deleteRow();


private slots:
    void on_actionInfo_triggered();

    void on_actionExit_triggered();

    void on_action_New_triggered();

    void on_action_Open_triggered();

    void on_action_Save_triggered();

    void on_actionSave_As_triggered();

    void on_actionNew_Student_triggered();

    void on_sTable_activated(const QModelIndex &index);

    void on_actionEdit_triggered();

    void on_action_Delete_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
