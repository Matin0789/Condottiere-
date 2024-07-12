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
    QMediaPlayer * music = new QMediaPlayer();
    //music->setActiveAudioTrack(QUrl("qrc:/Description/Graphics/Sounds/pirate-of-caribbean.mp3"));
        music->play();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Start_clicked()
{
    hide();
    start = new Start(this);
    start->show();

}



void MainWindow::on_btn_exit_clicked()
{
    close();
}


