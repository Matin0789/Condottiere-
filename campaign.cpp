#include "campaign.h"
#include "ui_campaign.h"

campaign::campaign(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::campaign)
{
    ui->setupUi(this);
}

campaign::~campaign()
{
    delete ui;
}
