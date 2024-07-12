#ifndef SHOWCARDS_H
#define SHOWCARDS_H

#include <QDialog>

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

private:
    Ui::showCards *ui;
    campaign *Campaign;
};

#endif // SHOWCARDS_H
