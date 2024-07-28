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
    start = new Start(this);
    QObject::connect(start, &Start::end, this, &MainWindow::nextPage);
    QObject::connect(start, &Start::set_player, controller, &Controller::get_player);
}

MainWindow::~MainWindow()
{
    QObject::disconnect(start, &Start::set_player, controller, &Controller::get_player);
    QObject::disconnect(start, &Start::end, this, &MainWindow::nextPage);
    delete start;
    delete ui;
}

void MainWindow::nextPage()
{
    showcards = new showCards(this);
    showcards->show();
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
    // end of project
}
