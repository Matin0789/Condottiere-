#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include "start.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_Start_clicked();

    void on_btn_exit_clicked();

    void on_btn_load_game_clicked();

private:
    Ui::MainWindow *ui;
    Start *start;
};
#endif // MAINWINDOW_H
