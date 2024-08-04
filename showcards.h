#ifndef SHOWCARDS_H
#define SHOWCARDS_H

#include <QDialog>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QLabel>
#include <QVector>

#include <map>

#include "campaign.h"
#include "player.h"

namespace Ui {
class showCards;
}

class showCards : public QDialog
{
    Q_OBJECT

public:
    explicit showCards(QWidget *parent = nullptr);
    ~showCards();

public slots:
    void getPlayer(const Player&);

private slots:
    void on_btn_Nplayer_clicked();
    void on_cb_show_player_list_activated(int index);
    void on_btn_lets_go_clicked();

private:
    Ui::showCards *ui;
    Campaign *Campaign;
    QVector<QLabel*> cardLabel;
    std::map<std::string, std::string> cardsImageRef;
};

#endif // SHOWCARDS_H
