#ifndef LOCATEINFO_H
#define LOCATEINFO_H

#include <QDialog>

#include "campaign.h"
#include "game.h"
#include "userinterface.h"


namespace Ui {
class Locateinfo;
}

class Locateinfo : public QDialog
{
    Q_OBJECT

public:
    explicit Locateinfo(QString type,QWidget *parent = nullptr);
    ~Locateinfo();
public slots:
    State* set_ground(const Player&,GameBoard&);
private slots:
    void on_lb_state_linkActivated(const QString &link);
    void on_cb_activated(int index);
    void on_lb_peace_linkActivated(const QString &link);
    void on_le_peace_sign_cursorPositionChanged(int arg1, int arg2);
    void on_btn_next_clicked();
    void on_btn_back_clicked();
private:
    Ui::Locateinfo *ui;
    Campaign *Campaign;
    Game *game;
    UserInterface *user;
};

#endif // LOCATEINFO_H
