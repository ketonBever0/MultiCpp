#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    bool maybeSave();

    void saveFile();

    void saveFileAs();

private slots:
    void on_actionInfo_triggered();

    void on_actionExit_triggered();

    void on_action_New_triggered();

    void on_action_Open_triggered();

    void on_action_Save_triggered();

    void on_actionSave_As_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
