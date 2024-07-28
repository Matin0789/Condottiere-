#include "start.h"
#include "ui_start.h"


Start::Start(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Start)
    , playerID(0)
{
    ui->setupUi(this);
    ui->sb->setMaximum(6);
    ui->sb->setMinimum(3);

    freeColors.push_back(std::pair<QString, Color>("ORANGE", orange));
    freeColors.push_back(std::pair<QString, Color>("BLUE",   blue));
    freeColors.push_back(std::pair<QString, Color>("GREEN",  green));
    freeColors.push_back(std::pair<QString, Color>("RED",    red));
    freeColors.push_back(std::pair<QString, Color>("GRAY",   gray));
    freeColors.push_back(std::pair<QString, Color>("BROWN",  brown));
}

Start::~Start()
{
    delete setplayer;
    delete ui;
}

void Start::get_player(std::string name, size_t age, Color color)
{
    emit set_player(name, age, color);
    QObject::disconnect(setplayer, &Setplayer::get_player, this, &get_player);
    delete setplayer;
    playerID++;
    if (playersNumber > playerID) {
        setplayer = new Setplayer(freeColors, playerID,this);
        setplayer->show();
    }
    else {
        hide();
        emit end();
    }
}

void Start::on_btn_next_clicked()
{
    playersNumber = ui->sb->value();
    setplayer = new Setplayer(freeColors, playerID,this);
    QObject::connect(setplayer, &Setplayer::get_player, this, &get_player);
    setplayer->show();
}

void Start::on_btn_back_clicked()
{

}

