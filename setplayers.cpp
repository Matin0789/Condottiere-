#include "setplayers.h"
#include "ui_setplayers.h"

SetPlayers::SetPlayers(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SetPlayers)
{
    ui->setupUi(this);
}

SetPlayers::~SetPlayers()
{
    delete ui;
}
