#include "start.h"
#include "ui_start.h"

Start::Start(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Start)
{
    ui->setupUi(this);
}

Start::~Start()
{
    delete ui;
}





void Start::on_btn_next_clicked()
{
    hide();
    playerinfo = new Playerinfo(this);
    playerinfo->show();
}

void Start::on_btn_back_clicked()
{

}

