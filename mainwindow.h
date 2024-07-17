#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <controller.h>

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
    void on_btn_sound_clicked();

private:
    Ui::MainWindow *ui;
    Start *start;
    Set *set;
    showCards *showcards;
    Controller *controller;
};
#endif // MAINWINDOW_H
