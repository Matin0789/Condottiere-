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
    /*ui->sb_age->setMaximum(100);
    ui->sb_age->setMaximum(0);*/
    std::string labelText = "Player " + std::to_string(playerID + 1);
    ui->lb_player_counter->setText(QString::fromStdString(labelText));
    this->setWindowTitle(QString::fromStdString(labelText));
}

Setplayer::~Setplayer()
{
    delete ui;
}

void Setplayer::on_btn_next_clicked()
{
    QString name = ui->lineEdit_name->text();
    size_t old = ui->sb_age->value();
    QString color = ui->comboBox_color->currentText();

    if(name == "") {
        QMessageBox ErrorMessage;
        ErrorMessage.setText("name is empty!");
        ErrorMessage.exec();
    }
    else if (old == 0){
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
        Color choiceColor;
        choiceColor = freeColors[color];
        this->hide();
        emit get_player(name.toStdString(), old, choiceColor);
    }
}

void Setplayer::on_btn_back_clicked()
{

}
