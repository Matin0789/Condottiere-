#ifndef START_H
#define START_H

#include <QDialog>
#include <map>
#include "game.h"
#include "userinterface.h"
#include "setplayer.h"

namespace Ui {
class Start;
}

class Start : public QDialog
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = nullptr);
    ~Start();
public slots:
    size_t get_players_number();
private slots:
    void on_btn_next_clicked();    // next page

    void on_btn_back_clicked();     // delete this

    //void on_le_number_cursorPositionChanged(int arg1);

private:
    Ui::Start *ui;
};

#endif // START_H
