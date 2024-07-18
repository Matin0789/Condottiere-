#include <utility>
#include <QMessageBox>

#include "Playerinfo.h"
#include "ui_Playerinfo.h"

Set::Set(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PlayerInfo)
{
    ui->setupUi(this);
    freeColors.push_back(std::pair<QString, Color>("ORANGE", orange));
    freeColors.push_back(std::pair<QString, Color>("BLUE",   blue));
    freeColors.push_back(std::pair<QString, Color>("GREEN",  green));
    freeColors.push_back(std::pair<QString, Color>("RED",    red));
    freeColors.push_back(std::pair<QString, Color>("GRAY",   gray));
    freeColors.push_back(std::pair<QString, Color>("BROWN",  brown));
    ui->comboBox_color->addItems({
        "ORANGE",
        "BLUE",
        "GREEN",
        "RED",
        "GRAY",
        "BROWN",
    });
}

Playerinfo::~Playerinfo()
{
    delete ui;
}

void Playerinfo::on_btn_next_clicked()
{
    hide();
    QString name = ui->lineEdit_name->text();
    size_t old = ui->lineEdit_name->text().toInt();
    QString color = ui->comboBox_color->currentText();
    Color choiceColor;
    bool flag = false;
    for (size_t i = 0; i < freeColors.size(); i++)
    {
        if (color == freeColors[i].first) {
            flag = true;
            choiceColor = freeColors[i].second;
            freeColors.erase(freeColors.begin() + i);
            break;
        }
    }

    if (!flag) {
        QMessageBox msgBox;
        msgBox.setText("bad color choice");
        msgBox.exec();
    }
    else {
        get_player_name(name.toStdString());
        get_player_old(old);
        get_player_color(choiceColor);
    }
}

void Playerinfo::on_btn_back_clicked()
{

}
