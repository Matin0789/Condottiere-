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
    QString name = ui->lineEdit_name->text();
    QString old = ui->lineEdit_age->text();
    QString color = ui->comboBox_color->currentText();

    if(name == "") {
        QMessageBox ErrorMessage;
        ErrorMessage.setText("name is empty!");
        ErrorMessage.exec();
    }
    else if (old == ""){
        QMessageBox ErrorMessage;
        ErrorMessage.setText("age is empty!");
        ErrorMessage.exec();
    }
    else if (freeColors.find(color) == freeColors.end()) {
        QMessageBox ErrorMessage;
        ErrorMessage.setText("bad color choice");
        ErrorMessage.exec();
    }
    else {
        hide();
        Color choiceColor;
        choiceColor = freeColors[color];
        emit get_player(name.toStdString(), old.toInt(), choiceColor);
    }
}

void Setplayer::on_btn_back_clicked()
{

}
