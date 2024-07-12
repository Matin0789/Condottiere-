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

void showCards::on_pb_go_clicked()
{
    hide();
    Campaign = new campaign(this);
    Campaign->show();
}



void showCards::on_toolButton_6_clicked()
{

}

