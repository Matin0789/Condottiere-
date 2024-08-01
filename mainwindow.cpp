#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "battlemarker.h"
#include "favormarker.h"

#include <QMessageBox>
#include <QPixmap>
#include <QMediaPlayer>
#include <QAudioOutput>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    game(new Game),
    battleground_page(new Locateinfo("battle", this)),
    favorground_page(new Locateinfo("favor", this))
{
    ui->setupUi(this);
    this->setWindowTitle("Condottiere");
    start = new Start(this);
    QObject::connect(start, &Start::end, this, &MainWindow::startGame);
    QObject::connect(start, &Start::set_player, game, &Game::get_player);
    QObject::connect(game, &Game::set_battleground, battleground_page, &Locateinfo::set_ground );
    QObject::connect(game, &Game::set_favorground,  favorground_page,  &Locateinfo::set_ground );
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
    delete battleground_page;
    delete favorground_page;
    delete start;
    delete ui;
    delete game;
    delete showcards;
    delete campaign;
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
    close();
}

void MainWindow::on_btn_load_game_clicked()
{

}

void MainWindow::on_btn_sound_clicked()
{
    static bool enable = true;
    if (enable == true){
        ui->btn_sound->setStyleSheet("../../Description/Graphics/photos/volume.png");
        player->pause();
        enable = false;
    }
    else {
        ui->btn_sound->setStyleSheet("../../Description/Graphics/photos/mute.png");
        player->play();
        enable = true;
    }
}
