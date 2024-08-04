#include "gamewinner.h"
#include "ui_gamewinner.h"

GameWinner::GameWinner(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWinner)
{
    ui->setupUi(this);
}

GameWinner::~GameWinner()
{
    delete ui;
}
