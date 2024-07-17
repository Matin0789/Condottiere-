#include "showcards.h"
#include "ui_showcards.h"

showCards::showCards(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::showCards)
{
    ui->setupUi(this);

}

showCards::~showCards()
{
    delete ui;
}

void showCards::on_btn_Nplayer_clicked()
{

}

void showCards::on_cb_show_player_list_activated(int index)
{

}

void showCards::on_btn_lets_go_clicked()
{
    hide();
    Campaign = new campaign(this);
    Campaign->show();
}