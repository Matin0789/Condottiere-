#include "campaign.h"
#include "ui_campaign.h"

Campaign::Campaign(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::campaign)
{
    ui->setupUi(this);
}

Campaign::~Campaign()
{
    delete ui;
}

void Campaign::on_pb_help_clicked()
{
    hide();
    help = new Help(this);
    help->show();
}

void Campaign::on_pb_setting_clicked()
{
    hide();
    options = new Options(this);
    options->show();
}
