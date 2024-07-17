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
    set = new Set(this);
    set->show();
}

void Start::on_btn_back_clicked()
{

}

void Start::on_le_number_cursorPositionChanged(int arg1)
{
    user = new UserInterface();
    user->get_players_number();  // prototype ----> int arg1    sent to function

    // after call function  should stop in this page
}

