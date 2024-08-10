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
                             QString::number(winner.getID() + 1) +
                             " Won the Battle and captured the " +
                             QString::fromStdString(battleMarker.getState().getName()));   // show name of winner player
    }
    else {
        ui->label_2->setText("The battle was inconclusive and the state of " +
                             QString::fromStdString(battleMarker.getState().getName()) +    // show name of winner player
                             " still remains");
    }

    QEventLoop loop;
    connect(ui->pushButton_3, SIGNAL(clicked(bool)), &loop, SLOT(quit()));      //signal and slot
    loop.exec();
    disconnect(ui->pushButton_3, SIGNAL(clicked(bool)), &loop, SLOT(quit()));    //signal and slot
    this->hide();
}

void Winner::on_btn_save_clicked()    /// save button
{
    emit save();
}

