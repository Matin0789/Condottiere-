#include "Help.h"
#include "ui_Help.h"
#include "filepath.h"

#include "bishop.h"
#include "drummer.h"
#include "heroine.h"
#include "scarecrow.h"
#include "spy.h"
#include "winter.h"
#include "spring.h"
#include "turncoat.h"
#include "game.h"

#include <QMainWindow>

Help::Help(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Help)
{
    ui->setupUi(this);

    cardsImageRef["Bishop"]    = "border-image:url(" + QString(BISHOP_IMAGE)    + ")";
    cardsImageRef["Drummer"]   = "border-image:url(" + QString(DRUMMER_IMAGE)   + ")";
    cardsImageRef["Heroine"]   = "border-image:url(" + QString(HEROINE_IMAGE)   + ")";
    cardsImageRef["Scarecrow"] = "border-image:url(" + QString(SCARECROW_IMAGE) + ")";
    cardsImageRef["Spring"]    = "border-image:url(" + QString(SPRING_IMAGE)    + ")";
    cardsImageRef["Winter"]    = "border-image:url(" + QString(WINTER_IMAGE)    + ")";
    cardsImageRef["Spy"]       = "border-image:url(" + QString(SPY_IMAGE)       + ")";
    cardsImageRef["Turncoat"]  = "border-image:url(" + QString(TURNCOAT_IMAGE)  + ")";
}

Help::~Help()
{
    delete ui;
}

void Help::on_btn_ok_clicked()
{
    QMainWindow *campaign = qobject_cast<QMainWindow*>(parent());
    campaign->show();
    this->hide();
}

void Help::on_ptn_back_clicked()
{

}

void Help::on_cb_help_list_activated(int index)
{

}
void Help::on_cb_help_list_currentTextChanged(const QString &arg1)
{
    ui->label_2->setVisible(false);
    ui->lb_help_txt->setVisible(false);
    if (arg1 == "Game") {
        ui->lb_help_txt->setText(QString::fromStdString(Game::getHelp()));
        ui->lb_help_txt->setVisible(true);
    }
    else if(arg1 == "Bishop") {
        ui->lb_help_txt->setText(QString::fromStdString(Bishop::getHelp()));
        ui->lb_help_txt->setVisible(true);
        ui->label_2->setStyleSheet(cardsImageRef["Bishop"]);
        ui->label_2->setVisible(true);
    }
    else if(arg1 == "Heroine") {
        ui->lb_help_txt->setText(QString::fromStdString(Heroine::getHelp()));
        ui->lb_help_txt->setVisible(true);
        ui->label_2->setStyleSheet(cardsImageRef["Heroine"]);
        ui->label_2->setVisible(true);
    }
    else if(arg1 == "Drummer") {
        ui->lb_help_txt->setText(QString::fromStdString(Drummer::getHelp()));
        ui->lb_help_txt->setVisible(true);
        ui->label_2->setStyleSheet(cardsImageRef["Drummer"]);
        ui->label_2->setVisible(true);
    }
    else if(arg1 == "Heroine") {
        ui->lb_help_txt->setText(QString::fromStdString(Heroine::getHelp()));
        ui->lb_help_txt->setVisible(false);
        ui->label_2->setStyleSheet(cardsImageRef["Heroine"]);
        ui->label_2->setVisible(true);
    }
    else if(arg1 == "Scarecrow") {
        ui->lb_help_txt->setText(QString::fromStdString(Scarecrow::getHelp()));
        ui->lb_help_txt->setVisible(true);
        ui->label_2->setStyleSheet(cardsImageRef["Scarecrow"]);
        ui->label_2->setVisible(true);
    }
    else if(arg1 == "Spring") {
        ui->lb_help_txt->setText(QString::fromStdString(Spring::getHelp()));
        ui->lb_help_txt->setVisible(true);
        ui->label_2->setStyleSheet(cardsImageRef["Spring"]);
        ui->label_2->setVisible(true);
    }
    else if(arg1 == "Winter") {
        ui->lb_help_txt->setText(QString::fromStdString(Winter::getHelp()));
        ui->lb_help_txt->setVisible(true);
        ui->label_2->setStyleSheet(cardsImageRef["Winter"]);
        ui->label_2->setVisible(true);
    }
    else if(arg1 == "Spy") {
        ui->lb_help_txt->setText(QString::fromStdString(Spy::getHelp()));
        ui->lb_help_txt->setVisible(true);
        ui->label_2->setStyleSheet(cardsImageRef["Spy"]);
        ui->label_2->setVisible(true);
    }
    else if(arg1 == "Turncoat") {
        ui->lb_help_txt->setText(QString::fromStdString(Turncoat::getHelp()));
        ui->lb_help_txt->setVisible(true);
        ui->label_2->setStyleSheet(cardsImageRef["Turncoat"]);
        ui->label_2->setVisible(true);
    }
}

