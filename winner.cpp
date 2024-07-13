#include "winner.h"
#include "ui_winner.h"

Winner::Winner(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Winner)
{
    ui->setupUi(this);
}

Winner::~Winner()
{
    delete ui;
}
