#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "game.h"

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
public slots:
    void showPlayerPlayedCards(const Player&) const;
    std::string getCommand(const Player&, const BattleMarker&, const Card*);
    State* get_battleground(const Player&,GameBoard&);
    State* get_favorground(const Player&,GameBoard&);
    void showPlayerStates(const Player&) const;
    void showPlayerCards(const Player&) const;
    std::string get_card_name();

    //
    int get_players_number(size_t);
    void get_player_name(std::string);
    void get_player_old(size_t);
    void get_player_color(Color);

    //
    void declare_warWinner(const Player&) const;
    void declare_warWinner() const;

    void declare_gameWinner(const Player&) const;
signals:

private:
    Game *game;
};

#endif // CONTROLLER_H
