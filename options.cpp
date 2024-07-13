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


void Options::on_pb_save_clicked()
{

   // game.save();

}


void Options::on_pb_load_clicked()
{
    //game.load();
}


void Options::on_pb_audio_clicked()
{
    //
}


void Options::on_pb_quit_clicked()
{
    close();
}


void Options::on_pb_Continue_clicked()
{

}

