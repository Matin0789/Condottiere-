#ifndef START_H
#define START_H

#include <QDialog>

#include "Set.h"
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

private slots:

    void on_btn_next_clicked();

    void on_btn_back_clicked();

    void on_le_number_cursorPositionChanged(int arg1);

private:
    Ui::Start *ui;
    Set *set;
    Game *game;
    UserInterface *user;
};

#endif // START_H
