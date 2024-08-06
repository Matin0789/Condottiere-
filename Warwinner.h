#ifndef WARWINNER_H
#define WARWINNER_H

#include <QDialog>

#include "game.h"
#include "userinterface.h"

namespace Ui 
{
class Winner;
}

class Winner : public QDialog
{
    Q_OBJECT

public:
    explicit Winner(QWidget *parent = nullptr);
    ~Winner();

public slots:
    void declare(const Player&, BattleMarker&, bool);
private:
    Ui::Winner *ui;
};

#endif // WARWINNER_H
