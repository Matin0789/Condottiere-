#include "gamewinner.h"
#include "ui_gamewinner.h"
#include "filepath.h"

GameWinner::GameWinner(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWinner)
{
    ui->setupUi(this);

    markers["BattleMarker"] = "border-image:url(" + QString(BATTLE_MARKER_IMAGE)  + ");" + " background-color:transparent";
    markers["FavorMarker"]  = "border-image:url(" + QString(PEACE_MARKER_IMAGE)   + ");" + " background-color:transparent";
    markers["blue"]         = "border-image:url(" + QString(PLAYER_BLUE_MARKER_IMAGE)  + ");" + " background-color:transparent";
    markers["green"]        = "border-image:url(" + QString(PLAYER_GREEN_MARKER_IMAGE)  + ");" + " background-color:transparent";
    markers["red"]          = "border-image:url(" + QString(PLAYER_RED_MARKER_IMAGE)  + ");" + " background-color:transparent";
    markers["orange"]       = "border-image:url(" + QString(PLAYER_ORANGE_MARKER_IMAGE)  + ");" + " background-color:transparent";
    markers["gray"]         = "border-image:url(" + QString(PLAYER_GRAY_MARKER_IMAGE)  + ");" + " background-color:transparent";
    markers["brown"]        = "border-image:url(" + QString(PLAYER_BROWN_MARKER_IMAGE)  + ");" + " background-color:transparent";

    stateLabels["BELLA"] = ui->lb_bella;
    stateLabels["PLADACI"] = ui->lb_pladaci;
    stateLabels["ROLLO"] = ui->lb_rollo;
    stateLabels["ELINIA"] = ui->lb_elinia;
    stateLabels["CALINE"] = ui->lb_caline;
    stateLabels["BORGE"] = ui->lb_borge;
    stateLabels["OLIVADI"] = ui->lb_olivadi;
    stateLabels["ARMENTO"] = ui->lb_armento;
    stateLabels["TALMONE"] = ui->lb_talmone;
    stateLabels["ENNA"] = ui->lb_enna;
    stateLabels["LIA"] = ui->lb_lia;
    stateLabels["MORINA"] = ui->lb_morina;
    stateLabels["DIMASE"] = ui->lb_dimase;
    stateLabels["ATELA"] = ui->lb_atela;
}

GameWinner::~GameWinner()
{
    delete ui;
}

void GameWinner::declare(const std::vector<Player> &players, const Player &winner)
{
    this->show();
    for(auto &&label : stateLabels) {
        label.second->setStyleSheet("");
        label.second->setVisible(false);
    }
    ui->lb_player_counter->setText("Player " + QString::number(winner.getID() + 1) + " won this game and became the emperor of the world");

    for (auto &&player : players) {
        for (auto &&state_name : player.get_states_name()) {
            stateLabels[state_name]->setStyleSheet(markers[player.getColor()]);
            stateLabels[state_name]->setVisible(true);
        }
    }

    QEventLoop loop;
    connect(ui->pushButton_3, SIGNAL(clicked(bool)), &loop, SLOT(quit()));
    loop.exec();
    disconnect(ui->pushButton_3, SIGNAL(clicked(bool)), &loop, SLOT(quit()));
    this->hide();
}

void GameWinner::on_pushButton_4_clicked()
{
    exit(EXIT_SUCCESS);
}


void GameWinner::on_pushButton_3_clicked()
{
    QMainWindow *menu = qobject_cast<QMainWindow*>(parent());
    menu->show();
    this->hide();
}

