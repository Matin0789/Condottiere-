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

    //
    const std::vector<const Card*>& getPlayedCards() const;
    const std::vector<const Card*>& getCards() const;
    void setCards(std::vector<const Card*>);

    //
    void setState(State*);
	std::vector<std::string> get_states_name() const;
    size_t getStateNumber() const;
    //
    const Card* drawn_card(std::string);
    void push_to_cards(const Card*);
    void push_to_playedCards(const Card*);
    const Card* drawn_playedCard(std::string);
    
    //
    std::vector<const Card*> burnCards();
    std::vector<const Card*> burnPlayedCards();

private:
    const std::string name;
    const size_t ID;
    const unsigned int age;
    std::vector<const Card*> cards;
    std::vector<const Card*> playedCards;
    size_t stateCounter;
	std::array<PlayerMarker, 5> markers;
};

#endif // PLAYER_H