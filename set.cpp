#include "set.h"
#include "ui_set.h"

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



void Set::on_pb_next_pressed()
{
    hide();
    showcards = new showCards(this);
    showcards->show();
}

