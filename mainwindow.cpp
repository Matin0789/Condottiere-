#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QMediaPlayer>
#include <QAudioOutput>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , game(new UserInterface)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_Start_clicked()
{
    hide();
    game->play();
}



void MainWindow::on_btn_exit_clicked()
{
    close();
}



void MainWindow::on_btn_load_game_clicked()
{

}

