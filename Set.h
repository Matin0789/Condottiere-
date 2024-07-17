#ifndef SET_H
#define SET_H

#include <QDialog>

#include "showcards.h"
#include "game.h"
#include "userinterface.h"


namespace Ui {
class Set;
}

class Set : public QDialog
{
    Q_OBJECT

public:
    explicit Set(QWidget *parent = nullptr);
    ~Set();

private slots:
    void on_btn_next_clicked();
    void on_btn_back_clicked();

private:
    Ui::Set *ui;
    showCards *showcards;
    Game *game;
    UserInterface *user;
};

#endif // SET_H
