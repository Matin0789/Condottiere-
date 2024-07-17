#include "Help.h"
#include "ui_Help.h"

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

void Help::on_btn_ok_clicked()
{

}

void Help::on_ptn_back_clicked()
{

}

void Help::on_cb_help_list_activated(int index)
{

}

