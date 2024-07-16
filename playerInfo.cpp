#include "playerInfo.h"
#include "ui_playerInfo.h"

Set::Set(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Set)
{
    ui->setupUi(this);
}

Set::~Set()
{
    delete ui;
}

void Set::on_ptn_next_clicked()
{
    hide();
    showcards = new showCards(this);
    showcards->show();
}


void Set::on_btn_back_clicked()
{

}

