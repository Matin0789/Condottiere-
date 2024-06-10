#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>


#include "card.h"
#include "userinterface.h"

class Player {

public:
    std::string getName() const;
    int getID() const;
    const std::vector<Card*>& getPlayedCards() const;
    const std::vector<Card*>& getCards() const;
private:
    std::string name;
    int ID;
    std::vector<Card*> cards;
    std::vector<Card*> playedCards;

};

#endif // PLAYER_H