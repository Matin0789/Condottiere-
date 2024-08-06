#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "battlemarker.h"
#include "favormarker.h"
#include "filepath.h"

#include <QMessageBox>
#include <QPixmap>
#include <QMediaPlayer>
#include <QAudioOutput>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    game(new Game),
    battleground_page(new Locateinfo("BattleMarker", this)),
    favorground_page(new Locateinfo( "FavorMarker", this)),
    start(new Start(this)),
    campaign(new Campaign(this)),
    warWinner_page(new Winner(this)),
    gameWinner_page(new GameWinner(this))
{
    ui->setupUi(this);
    this->setWindowTitle("Condottiere");
    showcards = new showCards;
    QObject::connect(start, &Start::end, this, &MainWindow::startGame);
    QObject::connect(start, &Start::set_player, game, &Game::get_player);
    QObject::connect(game, &Game::set_battleground, battleground_page, &Locateinfo::set_ground);
    QObject::connect(game, &Game::set_favorground,  favorground_page,  &Locateinfo::set_ground);
    QObject::connect(game, &Game::showPlayerCards, showcards, &showCards::getPlayer);
    QObject::connect(game, &Game::startWar, campaign, &Campaign::startWar);
    QObject::connect(game, &Game::getCommand, campaign, &Campaign::getCommand);
    QObject::connect(game, &Game::declare_gameWinner, gameWinner_page, &GameWinner::declare);
    QObject::connect(game, &Game::declare_warWinner, warWinner_page, &Winner::declare);
    player = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile("../../Description/Graphics/Sounds/background_music.mp3"));
    audioOutput->setVolume(100);
    player->play();
    player->setLoops(QMediaPlayer::Infinite);
}

MainWindow::~MainWindow()
{
    QObject::disconnect(start, &Start::set_player, game, &Game::get_player);
    QObject::disconnect(start, &Start::end, this, &MainWindow::startGame);
    QObject::disconnect(game, &Game::set_battleground, battleground_page, &Locateinfo::set_ground );
    QObject::disconnect(game, &Game::set_favorground,  favorground_page,  &Locateinfo::set_ground );
    QObject::disconnect(game, &Game::showPlayerCards, showcards, &showCards::getPlayer);
    QObject::disconnect(game, &Game::showPlayerCards, showcards, &showCards::getPlayer);
    QObject::disconnect(game, &Game::startWar, campaign, &Campaign::startWar);
    QObject::disconnect(game, &Game::getCommand, campaign, &Campaign::getCommand);
    QObject::disconnect(game, &Game::declare_gameWinner, gameWinner_page, &GameWinner::declare);
    QObject::disconnect(game, &Game::declare_warWinner, warWinner_page, &Winner::declare);
    delete battleground_page;
    delete favorground_page;
    delete start;
    delete ui;
    delete game;
    delete showcards;
    delete campaign;
    delete player;
    delete audioOutput;
    delete gameWinner_page;
    delete warWinner_page;
}

void MainWindow::startGame()
{
    game->start();
}

void MainWindow::on_btn_Start_clicked()
{
    start->show();
    hide();
}

void MainWindow::on_btn_exit_clicked()
{
    exit(EXIT_SUCCESS);
}

void MainWindow::on_btn_load_game_clicked()
{
    //game->load();
    game->start();
}

void MainWindow::on_btn_sound_clicked()
{
    static bool enable = true;
    if (enable == true){
        ui->btn_sound->setStyleSheet("border-image:url(:/Description/Graphics/photos/mute.png)");
        player->pause();
        enable = false;
    }
    else {
        ui->btn_sound->setStyleSheet("border-image:url(:/Description/Graphics/photos/volume.png)");
        player->play();
        enable = true;
    }
}
