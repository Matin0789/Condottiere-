#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QMediaPlayer>
#include <QAudioOutput>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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

