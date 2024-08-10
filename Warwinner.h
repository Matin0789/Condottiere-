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
    void declare(const Player&, BattleMarker&, bool);  // for battlemarker and player number
private slots:
    void on_btn_save_clicked();
signals:
    void save();   // save signal
private:
    Ui::Winner *ui;
};

#endif // WARWINNER_H
