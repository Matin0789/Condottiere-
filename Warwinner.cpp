#include "Warwinner.h"
#include "ui_Warwinner.h"


Winner::Winner(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Winner)
    
{
    ui->setupUi(this);
}

Winner::~Winner()
{
    delete ui;
}

void Winner::declare(const Player &winner, BattleMarker& battleMarker, bool win)
{
    this->show();
    if (win) {
        ui->label_2->setText("The player" +
                             QString::number(winner.getID()) +
                             "Won the Battle Of Emperors and captured the " +
                             QString::fromStdString(battleMarker.getState().getName()));
    }
    else {
        ui->label_2->setText("The battle was inconclusive and the state of " +
                             QString::fromStdString(battleMarker.getState().getName()) +
                             " still remains");
    }

    QEventLoop loop;
    connect(ui->pushButton_3, SIGNAL(clicked(bool)), &loop, SLOT(quit()));
    loop.exec();
    disconnect(ui->pushButton_3, SIGNAL(clicked(bool)), &loop, SLOT(quit()));
    this->hide();
}
