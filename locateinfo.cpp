#include "locateinfo.h"
#include "ui_locateinfo.h"
#include "filepath.h"

#include <QMessageBox>

#include <algorithm>

Locateinfo::Locateinfo(QString type,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Locateinfo)
    , startGet(false)
{
    this->type = type;
    ui->setupUi(this);
    ui->lb_state->setText("Please select a " + type + " to start the battle ...");
    this->next_click = false;
    markers["BattleMarker"] = "border-image:url(" + QString(BATTLE_MARKER_IMAGE)  + ")";
    markers["FavorMarker"]  = "border-image:url(" + QString(PEACE_MARKER_IMAGE)   + ")";
    markers[""]             = "border-image:url(" + QString(PLAYER_MARKER_IMAGE)  + ")";

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

Locateinfo::~Locateinfo()
{
    delete ui;
}

State *Locateinfo::set_ground(const std::vector<Player>& players,const Player & currentPlayer,GameBoard & gameBoard, FavorMarker& favorMarker)
{
    for (auto&& labelmap : stateLabels) {
        labelmap.second->setVisible(false);
    }

    ui->cb_2->clear();
    for (auto &&state : gameBoard.get_active_states_name()) {
        ui->cb_2->addItem(QString::fromStdString(state));
    }


    currentState = ui->cb_2->currentText();
    stateLabels[currentState.toStdString()]->setStyleSheet(markers[this->type.toStdString()]);
    stateLabels[currentState.toStdString()]->setVisible(true);

    for(auto &&player : players) {
        for (auto &&playerState : player.get_states_name()) {
            stateLabels[playerState]->setStyleSheet(markers[""]);
            stateLabels[playerState]->setVisible(true);
        }
    }

    if (favorMarker.is_set() == true && this->type == "BattleMarker") {
        std::string favorStateName = favorMarker.getState().getName();
        stateLabels[favorStateName]->setStyleSheet(markers["FavorMarker"]);
        stateLabels[favorStateName]->setVisible(true);
    }

    ui->lb_player_counter->setText("Player " + QString::number(currentPlayer.getID() + 1));
    this->show();
    startGet = true;
    QEventLoop loop;
    QObject::connect(ui->btn_next, SIGNAL(clicked(bool)), &loop, SLOT(quit()));
    loop.exec();
    this->hide();
    startGet = false;
    QObject::disconnect(ui->btn_next, SIGNAL(clicked(bool)), &loop, SLOT(quit()));
    return gameBoard.getState(ui->cb_2->currentText().toStdString());
}

void Locateinfo::on_lb_state_linkActivated(const QString &link)
{

}


void Locateinfo::on_cb_activated(int index)
{

}


void Locateinfo::on_lb_peace_linkActivated(const QString &link)
{

}


void Locateinfo::on_le_peace_sign_cursorPositionChanged(int arg1, int arg2)
{

}


void Locateinfo::on_btn_next_clicked()
{

}


void Locateinfo::on_btn_back_clicked()
{

}


void Locateinfo::on_cb_2_currentTextChanged(const QString &arg1)
{
    if (startGet == true) {
        stateLabels[this->currentState.toStdString()]->setStyleSheet("");
        stateLabels[this->currentState.toStdString()]->setVisible(false);
        stateLabels[ui->cb_2->currentText().toStdString()]->setStyleSheet(markers[this->type.toStdString()]);
        stateLabels[ui->cb_2->currentText().toStdString()]->setVisible(true);
        this->currentState = ui->cb_2->currentText();
    }
}

