#ifndef SHOWCARDS_H
#define SHOWCARDS_H

#include <QDialog>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QLabel>
#include <QVector>

#include "campaign.h"
#include "game.h"
#include "userinterface.h"

namespace Ui {
class showCards;
}

class showCards : public QDialog
{
    Q_OBJECT

public:
    explicit showCards(QWidget *parent = nullptr);
    ~showCards();

private slots:
    void on_btn_Nplayer_clicked();
    void on_cb_show_player_list_activated(int index);
    void on_btn_lets_go_clicked();

private:
    Ui::showCards *ui;
    Campaign *Campaign;
    Game *game;
    UserInterface *user;
    //QVector<QLabel*> Nameoflabels;
};

#endif // SHOWCARDS_H
