#include "start.h"
#include "ui_start.h"

#include <QMessageBox>

Start::Start(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Start)
{
    ui->setupUi(this);
    ui->sb->setMaximum(6);
    ui->sb->setMinimum(3);

    this->setWindowTitle("get player number");
}

Start::~Start()
{
    delete ui;
}

size_t Start::get_players_number()
{
    ui->sb->setValue(3);
    this->show();
    QEventLoop loop;
    connect(ui->btn_next, SIGNAL(clicked(bool)), &loop, SLOT(quit()));
    loop.exec();
    disconnect(ui->btn_next, SIGNAL(clicked(bool)), &loop, SLOT(quit()));
    this->hide();
    return ui->sb->value();
}

void Start::on_btn_next_clicked()
{

}

void Start::on_btn_back_clicked()
{

}

