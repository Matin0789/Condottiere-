#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>


#include "card.h"

class UserInterface;

class Player {

public:
    std::string getName() const;
    int getID() const;
    unsigned int getPoint() const;
    void setPoint(unsigned int);
    const std::vector<Card*>& getPlayedCards() const;
    const std::vector<Card*>& getCards() const;
    void setState(State*);
private:
    std::string name;
    int ID;
    std::vector<Card*> cards;
    std::vector<Card*> playedCards;
    unsigned int point;
    size_t stateCount;
	std::array<PlayerMarker, 5> markers;
};

#endif // PLAYER_H