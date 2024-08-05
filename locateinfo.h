#ifndef LOCATEINFO_H
#define LOCATEINFO_H

#include <QDialog>

#include "campaign.h"
#include "game.h"
#include "userinterface.h"
#include "showcards.h"

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
    State* set_ground(const std::vector<Player>&, const Player&, GameBoard&, FavorMarker&);
private slots:
    void on_lb_state_linkActivated(const QString &link);
    void on_cb_activated(int index);
    void on_lb_peace_linkActivated(const QString &link);
    void on_le_peace_sign_cursorPositionChanged(int arg1, int arg2);
    void on_btn_next_clicked();
    void on_btn_back_clicked();
    void on_cb_2_currentTextChanged(const QString &arg1);

private:
    Ui::Locateinfo *ui;
    Campaign *Campaign;
    Game *game;
    UserInterface *user;
    bool next_click;
    showCards* showcards;
    bool startGet;
    QString currentState;
    QString type;
    std::map<std::string, QString> markers;
    std::map<std::string, QLabel*> stateLabels;

};

#endif // LOCATEINFO_H
