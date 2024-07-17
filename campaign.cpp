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

void campaign::on_pb_help_clicked()
{
    hide();
    help = new Help(this);
    help->show();
}

void campaign::on_pb_setting_clicked()
{
    hide();
    options = new Options(this);
    options->show();
}