#ifndef SHOWCARDS_H
#define SHOWCARDS_H

#include <QDialog>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

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
    campaign *Campaign;
    Game *game;
    UserInterface *user;
};

#endif // SHOWCARDS_H
