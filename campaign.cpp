#include "campaign.h"
#include "ui_campaign.h"

Campaign::Campaign(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Campaign)
{
    ui->setupUi(this);
   // QLabel *NameLabels = new QLabel(this);
   // for (int var = 0; var < total; ++var)
   // {

   // }
}

Campaign::~Campaign()
{
    delete ui;
}
