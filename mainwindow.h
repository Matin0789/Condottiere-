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
#include "savegame.h"
#include "loadgames.h"

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
signals :
    std::string getLoadFile();
public slots:
    void on_btn_load_game_clicked();
    void on_btn_sound_clicked();
private slots:
    void on_btn_Start_clicked();
    void on_btn_exit_clicked();


private:
    Ui::MainWindow *ui;       //userinterface 

    // pages
    Start *start;             // first page 
    Setplayer *setplayer;          // setplayer
    showCards *showcards;
    Campaign *campaign;
    Game *game;
    Locateinfo *battleground_page;
    Locateinfo *favorground_page;
    Winner *warWinner_page;
    GameWinner *gameWinner_page;
    saveGame *save_page;
    loadGames *load_page;

    // music players
    QMediaPlayer* player;            // this class and object is for play music 
    QAudioOutput* audioOutput;          /// play music in output
};
#endif // MAINWINDOW_H
