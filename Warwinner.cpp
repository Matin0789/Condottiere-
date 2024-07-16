#include "Warwinner.h"
#include "ui_Warwinner.h"

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
