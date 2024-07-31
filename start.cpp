#include "start.h"
#include "ui_start.h"

#include <QMessageBox>

Start::Start(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Start)
    , playerID(0)
{
    ui->setupUi(this);
    ui->sb->setMaximum(6);
    ui->sb->setMinimum(3);

    freeColors["ORANGE"] =  orange;
    freeColors["BLUE"]   =  blue;
    freeColors["GREEN"]  =  green;
    freeColors["RED"]    =  red;
    freeColors["GRAY"]   =  gray;
    freeColors["BROWN"]  =  brown;
    this->setWindowTitle("get player number");
}

Start::~Start()
{
    delete setplayer;
    delete ui;
}

void Start::get_player(std::string name, size_t age, Color color)
{
    for (auto &&freeColor : freeColors) {
        if(freeColor.second == color){
            freeColors.erase(freeColors.find(freeColor.first));
        }
    }
    emit set_player(name, age, color);
    QObject::disconnect(setplayer, &Setplayer::get_player, this, &get_player);
    delete setplayer;
    playerID++;
    if (playersNumber > playerID) {
        setplayer = new Setplayer(freeColors, playerID,this);
        QObject::connect(setplayer, &Setplayer::get_player, this, &get_player);
        setplayer->show();
    }
    else {
        emit end();
    }
}

void Start::on_btn_next_clicked()
{
    playersNumber = ui->sb->value();
    setplayer = new Setplayer(freeColors, playerID,this);
    QObject::connect(setplayer, &Setplayer::get_player, this, &get_player);
    setplayer->show();
    this->hide();
}

void Start::on_btn_back_clicked()
{

}

