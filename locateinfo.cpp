#include "locateinfo.h"
#include "ui_locateinfo.h"

Locateinfo::Locateinfo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Locateinfo)
{
    ui->setupUi(this);
}

Locateinfo::~Locateinfo()
{
    delete ui;
}

void Locateinfo::on_lb_state_linkActivated(const QString &link)
{

}


void Locateinfo::on_cb_activated(int index)
{

}


void Locateinfo::on_lb_peace_linkActivated(const QString &link)
{

}


void Locateinfo::on_le_peace_sign_cursorPositionChanged(int arg1, int arg2)
{

}


void Locateinfo::on_btn_next_clicked()
{

}


void Locateinfo::on_btn_back_clicked()
{

}

