#ifndef START_H
#define START_H

#include <QDialog>

#include "Playerinfo.h"
#include "game.h"
#include "userinterface.h"

namespace Ui {
class Start;
}

class Start : public QDialog
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = nullptr);
    ~Start();

signals:
    int get_players_number(size_t);

private slots:

    void on_btn_next_clicked();

    void on_btn_back_clicked();

    //void on_le_number_cursorPositionChanged(int arg1);

private:
    Ui::Start *ui;
};

#endif // START_H
