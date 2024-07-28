#include <utility>
#include <QMessageBox>

#include "Setplayer.h"
#include "ui_Setplayer.h"

Setplayer::Setplayer(std::map<QString, Color> freeColors, size_t playerID, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Setplayer)
{
    ui->setupUi(this);
    for(auto &&freeColor : freeColors)
        ui->comboBox_color->addItem(freeColor.first);
    this->freeColors = freeColors;
}

Setplayer::~Setplayer()
{
    delete ui;
}

void Setplayer::on_btn_next_clicked()
{
    if(ui->lineEdit_name->text() == "") {
        QMessageBox ErrorMessage;
        ErrorMessage.setText("name is empty!");
        ErrorMessage.exec();
    }
    else if (ui->lineEdit_age->text() == ""){
        QMessageBox ErrorMessage;
        ErrorMessage.setText("age is empty!");
        ErrorMessage.exec();
    }
    // else if (ui->comboBox_color->){

    // }
    else {
        hide();
        QString name = ui->lineEdit_name->text();
        size_t old = ui->lineEdit_age->text().toInt();
        QString color = ui->comboBox_color->currentText();
        Color choiceColor;
        if (freeColors.find(color) == freeColors.end()) {
            QMessageBox msgBox;
            msgBox.setText("bad color choice");
            msgBox.exec();
        }
        else {
            choiceColor = freeColors[color];
            emit get_player(name.toStdString(), old, choiceColor);
        }
    }
}

void Setplayer::on_btn_back_clicked()
{

}
