#include "locateinfo.h"
#include "ui_locateinfo.h"

#include <QMessageBox>

Locateinfo::Locateinfo(QString type,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Locateinfo)
{
    ui->setupUi(this);
    ui->lb_state->setText("Please select a " + type + "state to start the battle ...");
    this->next_click = false;
}

Locateinfo::~Locateinfo()
{
    delete ui;
}

State *Locateinfo::set_ground(const Player & player, GameBoard & gameBoard)
{
    ui->lb_player_counter->setText("Player " + QString::number(player.getID() + 1));
    this->show();
    ui->cb_2->clear();
    for (auto &&state : gameBoard.get_active_states_name()) {
        ui->cb_2->addItem(QString::fromStdString(state));
    }
    QEventLoop loop;
    QObject::connect(ui->btn_next, SIGNAL(clicked(bool)), &loop, SLOT(quit()));
    loop.exec();
    this->hide();
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

