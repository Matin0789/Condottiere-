#ifndef SHOWCARDS_H
#define SHOWCARDS_H

#include <QDialog>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include "campaign.h"

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
    void on_pb_go_clicked();


    void on_toolButton_6_clicked();

    void on_cb_show_player_list_activated(int index);

private:
    Ui::showCards *ui;
    campaign *Campaign;
};

#endif // SHOWCARDS_H
