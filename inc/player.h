#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <array>
#include <cstddef>

#include "card.h"
#include "state.h"
#include "playermarker.h"

class UserInterface;

class Player {

public:
    Player(std::string, size_t, unsigned int, Color);// (name,ID,old,marker Color)
    std::string getName() const;
    int getAge() const;
    int getID() const;
    unsigned int getPoint() const;
    void setPoint(unsigned int);
    const std::vector<Card*>& getPlayedCards() const;
    const std::vector<Card*>& getCards() const;
    void setState(State*);
private:
    const std::string name;
    const size_t ID;
    const unsigned int age;
    std::vector<Card*> cards;
    std::vector<Card*> playedCards;
    unsigned int point;
    size_t stateCounter;
	std::array<PlayerMarker, 5> markers;
};

#endif // PLAYER_H