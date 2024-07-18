#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "game.h"

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();
public slots:
    /*void showPlayerPlayedCards(const Player&) const;
    std::string getCommand(const Player&, const BattleMarker&, const Card*);
    State* get_battleground(const Player&,GameBoard&);
    State* get_favorground(const Player&,GameBoard&);
    void getPlayerStates(const Player&) const;
    void getPlayerCards(const Player&) const;
    std::string get_card_name();*/

    //
    void get_player(std::string, size_t, Color);

    //
    /*void declare_warWinner(const Player&) const;
    void declare_warWinner() const;

    void declare_gameWinner(const Player&) const;*/
signals:

private:
    Game *game;
};

#endif // CONTROLLER_H
