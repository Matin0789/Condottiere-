#include <utility>
#include <QMessageBox>

#include "Playerinfo.h"
#include "ui_Playerinfo.h"

Set::Set(std::vector<std::pair<QString, Color>> freeColors, size_t playerID, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PlayerInfo)
{
    ui->setupUi(this);
    for(auto &&freeColor : freeColors)
        ui->comboBox_color->addItem(freeColor.first);
    this->freeColors = freeColors;
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
        get_player(name.toStdString(), old, choiceColor);
    }
}

void Playerinfo::on_btn_back_clicked()
{

}
