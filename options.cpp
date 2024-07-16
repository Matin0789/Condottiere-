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

}

void Options::on_btn_load_games_clicked()
{
    //game.load();
}

void Options::on_btn_audio_clicked()
{

}

void Options::on_btn_quit_clicked()
{
    close();
}

