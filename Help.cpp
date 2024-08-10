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

    cardsImageRef["Bishop"]    = "border-image:url(" + QString(BISHOP_IMAGE)    + ")";            // Bishop image 
    cardsImageRef["Drummer"]   = "border-image:url(" + QString(DRUMMER_IMAGE)   + ")";            // Drummer image 
    cardsImageRef["Heroine"]   = "border-image:url(" + QString(HEROINE_IMAGE)   + ")";            // heroine image 
    cardsImageRef["Scarecrow"] = "border-image:url(" + QString(SCARECROW_IMAGE) + ")";            // Scarecrow image
    cardsImageRef["Spring"]    = "border-image:url(" + QString(SPRING_IMAGE)    + ")";            // Spring image
    cardsImageRef["Winter"]    = "border-image:url(" + QString(WINTER_IMAGE)    + ")";            // winter image 
    cardsImageRef["Spy"]       = "border-image:url(" + QString(SPY_IMAGE)       + ")";            // spy image 
    cardsImageRef["Turncoat"]  = "border-image:url(" + QString(TURNCOAT_IMAGE)  + ")";            // turncoat image 
    cardsImageRef["WhiteRakhsh"] = "border-image:url(" + std::string(WHITERAKHSH_IMAGE) + ")";           //This code is related to phase 3 of the project
    cardsImageRef["WhiteSeals"] = "border-image:url(" + std::string(WHITESEALS_IMAGE) + ")";            //This code is related to phase 3 of the project
    cardsImageRef["ShirinAghl"] = "border-image:url(" + std::string(SHIRINAGHL_IMAGE) + ")";           //This code is related to phase 3 of the project

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
void Help::on_cb_help_list_currentTextChanged(const QString &arg1)                             /// show help text fo player 
{
    ui->label_2->setVisible(false);
    ui->lb_help_txt->setVisible(false);
    if (arg1 == "Game") {
        ui->lb_help_txt->setText(QString::fromStdString(Game::getHelp()));            ///  with gethelp function on the card class
        ui->lb_help_txt->setVisible(true);
    }
    else if(arg1 == "Bishop") {
        ui->lb_help_txt->setText(QString::fromStdString(Bishop::getHelp()));     ///  with gethelp function on the card class
        ui->lb_help_txt->setVisible(true);
        ui->label_2->setStyleSheet(cardsImageRef["Bishop"]);
        ui->label_2->setVisible(true);
    }
    else if(arg1 == "Heroine") {
        ui->lb_help_txt->setText(QString::fromStdString(Heroine::getHelp()));      ///  with gethelp function on the card class
        ui->lb_help_txt->setVisible(true);
        ui->label_2->setStyleSheet(cardsImageRef["Heroine"]);
        ui->label_2->setVisible(true);
    }
    else if(arg1 == "Drummer") {
        ui->lb_help_txt->setText(QString::fromStdString(Drummer::getHelp()));                 ///  with gethelp function on the card class
        ui->lb_help_txt->setVisible(true);
        ui->label_2->setStyleSheet(cardsImageRef["Drummer"]);
        ui->label_2->setVisible(true);
    }
    else if(arg1 == "Heroine") {
        ui->lb_help_txt->setText(QString::fromStdString(Heroine::getHelp()));        ///  with gethelp function on the card class
        ui->lb_help_txt->setVisible(false);
        ui->label_2->setStyleSheet(cardsImageRef["Heroine"]);
        ui->label_2->setVisible(true);
    }
    else if(arg1 == "Scarecrow") {
        ui->lb_help_txt->setText(QString::fromStdString(Scarecrow::getHelp()));                ///  with gethelp function on the card class
        ui->lb_help_txt->setVisible(true);
        ui->label_2->setStyleSheet(cardsImageRef["Scarecrow"]);
        ui->label_2->setVisible(true);
    }
    else if(arg1 == "Spring") {
        ui->lb_help_txt->setText(QString::fromStdString(Spring::getHelp()));         ///  with gethelp function on the card class
        ui->lb_help_txt->setVisible(true);
        ui->label_2->setStyleSheet(cardsImageRef["Spring"]);
        ui->label_2->setVisible(true);
    }
    else if(arg1 == "Winter") {
        ui->lb_help_txt->setText(QString::fromStdString(Winter::getHelp()));       ///  with gethelp function on the card class
        ui->lb_help_txt->setVisible(true);
        ui->label_2->setStyleSheet(cardsImageRef["Winter"]);
        ui->label_2->setVisible(true);
    }
    else if(arg1 == "Spy") {
        ui->lb_help_txt->setText(QString::fromStdString(Spy::getHelp()));              ///  with gethelp function on the card class
        ui->lb_help_txt->setVisible(true);
        ui->label_2->setStyleSheet(cardsImageRef["Spy"]);
        ui->label_2->setVisible(true);
    }
    else if(arg1 == "Turncoat") {
        ui->lb_help_txt->setText(QString::fromStdString(Turncoat::getHelp()));     ///  with gethelp function on the card class
        ui->lb_help_txt->setVisible(true);
        ui->label_2->setStyleSheet(cardsImageRef["Turncoat"]);
        ui->label_2->setVisible(true);
    }
}

