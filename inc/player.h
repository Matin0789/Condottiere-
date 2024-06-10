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
    unsigned int getPoint() const;
    void setPoint(unsigned int);
    const std::vector<Card*>& getPlayedCards() const;
    const std::vector<Card*>& getCards() const;
private:
    std::string name;
    int ID;
    std::vector<Card*> cards;
    std::vector<Card*> playedCards;
    unsigned int point;
};

#endif // PLAYER_H