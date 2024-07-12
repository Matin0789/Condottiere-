#include "help.h"
#include "ui_help.h"

Help::Help(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Help)
{
    ui->setupUi(this);
}

Help::~Help()
{
    delete ui;
}

void Help::on_cb_help_list_activated(int index)
{

}


void Help::on_pb_ok_clicked()
{

}


void Help::on_pb_go_back_clicked()
{

}

