#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>

#include "game.h"
#include "start.h"
#include "setplayer.h"
#include "campaign.h"
#include "locateinfo.h"
#include "marker.h"
#include "Warwinner.h"
#include "gamewinner.h"

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

private slots:
    void on_btn_Start_clicked();
    void on_btn_exit_clicked();
    void on_btn_load_game_clicked();
    void on_btn_sound_clicked();

private:
    Ui::MainWindow *ui;
    Start *start;
    Setplayer *setplayer;
    showCards *showcards;
    Campaign *campaign;
    Game *game;
    Locateinfo *battleground_page;
    Locateinfo *favorground_page;
    Winner *warWinner_page;
    GameWinner *gameWinner_page;

    QMediaPlayer* player;
    QAudioOutput* audioOutput;
};
#endif // MAINWINDOW_H
