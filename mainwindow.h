#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "game.h"
#include "start.h"
#include "setplayer.h"
#include "campaign.h"
#include "locateinfo.h"
#include "marker.h"

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

public slots:
    void startGame();
    void showLocateinfo(Marker*);
private slots:
    void on_btn_Start_clicked();
    void on_btn_exit_clicked();
    void on_btn_load_game_clicked();
    void on_btn_sound_clicked();

private:
    Ui::MainWindow *ui;
    Start *start;
    showCards *showcards;
    Campaign *campaign;
    Game *game;
    Locateinfo *battleground_page;
    Locateinfo *favorground_page;
};
#endif // MAINWINDOW_H
