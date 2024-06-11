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

    //
    const std::vector<const Card*>& getPlayedCards() const;
    const std::vector<const Card*>& getCards() const;

    //
    void setState(State*);
	std::vector<std::string> get_states_name() const;

    //
    const Card* drawn_card(std::string);
    void push_to_playedCards(const Card*);
    
private:
    const std::string name;
    const size_t ID;
    const unsigned int age;
    std::vector<const Card*> cards;
    std::vector<const Card*> playedCards;
    unsigned int point;
    size_t stateCounter;
	std::array<PlayerMarker, 5> markers;
};

#endif // PLAYER_H