#include "options.h"
#include "ui_options.h"

Options::Options(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Options)
{
    ui->setupUi(this);
}

Options::~Options()
{
    delete ui;
}

void Options::on_btn_save_clicked()
{
     // game.save();
}

void Options::on_btn_Continue_clicked()
{
    QMainWindow *campaign = qobject_cast<QMainWindow*>(parent());
    campaign->show();
    this->hide();
}

void Options::on_btn_load_games_clicked()
{
    this->hide();
    emit loadGame();          //  load games 
}

void Options::on_btn_audio_clicked()
{
    emit muteAudio();                       // mute music
}

void Options::on_btn_quit_clicked()
{
    exit(EXIT_SUCCESS);
}
