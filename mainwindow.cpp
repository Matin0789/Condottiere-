#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "battlemarker.h"
#include "favormarker.h"

#include <QMessageBox>
#include <QPixmap>
#include <QMediaPlayer>
#include <QAudioOutput>

#include <typeinfo>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    game(new Game),
    battleground_page(new Locateinfo),
    favorground_page(new Locateinfo)
{
    ui->setupUi(this);
    start = new Start(this);
    QObject::connect(start, &Start::end, this, &MainWindow::startGame);
    QObject::connect(start, &Start::set_player, game, &Game::get_player);
    QObject::connect(game, &Game::show_set_ground_page, this, &MainWindow::showLocateinfo);
    QObject::connect(game, &Game::set_battleground, battleground_page, &Locateinfo::set_battleground );
    QObject::connect(game, &Game::set_favorground,  favorground_page,  &Locateinfo::set_favorground );
}

MainWindow::~MainWindow()
{
    QObject::disconnect(start, &Start::set_player, game, &Game::get_player);
    QObject::disconnect(start, &Start::end, this, &MainWindow::startGame);
    QObject::disconnect(game, &Game::set_battleground, battleground_page, &Locateinfo::set_battleground );
    QObject::disconnect(game, &Game::set_favorground,  favorground_page,  &Locateinfo::set_favorground );
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
    game->play();
}

void MainWindow::showLocateinfo(Marker *marker)
{
    if (typeid(*marker) == typeid(BattleMarker)){
        battleground_page->show();
    }
    else if (typeid(*marker) == typeid(FavorMarker)) {
        favorground_page->show();
    }
    else {
        QMessageBox msgBox;
        msgBox.setText(typeid(*marker));
        msgBox.exec();
        //throw std::runtime_error("invalid marker");
    }
}

void MainWindow::on_btn_Start_clicked()
{
    hide();
    start->show();
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
    enable = (enable != true);
    if (enable = true){
        ui->btn_sound->setStyleSheet("qrc:/Description/Graphics/photos/volume.png");
    }
    else {
        ui->btn_sound->setStyleSheet("qrc:/Description/Graphics/photos/mute.png");
    }
}
