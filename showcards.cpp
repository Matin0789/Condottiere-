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
