#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QMediaPlayer>
#include <QAudioOutput>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    controller(new Controller)
{
    ui->setupUi(this);
    QObject::connect(start, &Start::get_players_number, controller, &Controller::get_players_number);
    QObject::connect(set, &Set::get_player_name, controller, &Controller::get_player_name);
    QObject::connect(set, &Set::get_player_old, controller, &Controller::get_player_old);
    QObject::connect(set, &Set::get_player_color, controller, &Controller::get_player_color);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_Start_clicked()
{
    hide();
    start = new Start(this);
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
    // end of project
}
