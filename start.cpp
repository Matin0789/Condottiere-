#include "start.h"
#include "ui_start.h"


Start::Start(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Start)
    , playerID(0)
{
    ui->setupUi(this);

    freeColors.push_back(std::pair<QString, Color>("ORANGE", orange));
    freeColors.push_back(std::pair<QString, Color>("BLUE",   blue));
    freeColors.push_back(std::pair<QString, Color>("GREEN",  green));
    freeColors.push_back(std::pair<QString, Color>("RED",    red));
    freeColors.push_back(std::pair<QString, Color>("GRAY",   gray));
    freeColors.push_back(std::pair<QString, Color>("BROWN",  brown));
}

Start::~Start()
{
    delete playerinfo;
    delete ui;
}

void Start::get_player(std::string name, size_t age, Color color)
{
    set_player(name, age, color);
    QObject::disconnect(playerinfo, &PlayerInfo::get_player, this, &get_player);
    delete playerinfo;
    playerID++;
    if (playersNumber > playerID) {
        playerinfo = new PlayerInfo(freeColors, playerID,this);
        playerinfo->show();
    }
    else {
        hide();
        end();
    }
}

void Start::on_btn_next_clicked()
{
    hide();
    playerinfo = new PlayerInfo(freeColors, playerID,this);
    QObject::connect(playerinfo, &PlayerInfo::get_player, this, &get_player);
    playerinfo->show();
}

void Start::on_btn_back_clicked()
{

}

/*void Start::on_le_number_cursorPositionChanged(int arg1)
{
    user = new UserInterface();
    user->get_players_number();  // prototype ----> int arg1    sent to function

    // after call function  should stop in this page
}*/

