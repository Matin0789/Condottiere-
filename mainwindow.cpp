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
    battleground_page(new Locateinfo("battle", this)),
    favorground_page(new Locateinfo("favor", this))
{
    ui->setupUi(this);
    start = new Start(this);
    QObject::connect(start, &Start::end, this, &MainWindow::startGame);
    QObject::connect(start, &Start::set_player, game, &Game::get_player);
    QObject::connect(game, &Game::show_set_ground_page, this, &MainWindow::showLocateinfo);
    QObject::connect(game, &Game::set_battleground, battleground_page, &Locateinfo::set_ground );
    QObject::connect(game, &Game::set_favorground,  favorground_page,  &Locateinfo::set_ground );
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
    game->play();
}

void MainWindow::showLocateinfo(Marker *marker)
{
    if (marker->getType() == "BattleMarker"){
        battleground_page->show();
        hide();
    }
    else if (marker->getType() == "FavorMarker") {
        favorground_page->show();
        hide();
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("invalid marker");
        msgBox.exec();
    }
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
    enable = (enable != true);
    if (enable = true){
        ui->btn_sound->setStyleSheet("qrc:/Description/Graphics/photos/volume.png");
    }
    else {
        ui->btn_sound->setStyleSheet("qrc:/Description/Graphics/photos/mute.png");
    }
}
