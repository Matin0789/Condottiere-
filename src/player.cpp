#include "player.h"

Player::Player(std::string inputName, size_t inputID, unsigned int inputAge, Color inputColor) :
    name(inputName),
    ID(inputID),
    age(inputAge),
    markers{PlayerMarker(inputColor),
        PlayerMarker(inputColor),
        PlayerMarker(inputColor),
        PlayerMarker(inputColor),
        PlayerMarker(inputColor)},
    stateCounter(0) {
        
}

std::string Player::getName() const {
    return name;
}

int Player::getAge() const
{
    return age;
}

int Player::getID() const {
    return ID;
};

unsigned int Player::getPoint() const {
    return point;
}

void Player::setPoint(unsigned int point) {
    this->point = point;
}

const std::vector<const Card*>& Player::getPlayedCards() const {
    return playedCards;
}

const std::vector<const Card*>& Player::getCards() const {
    return cards;
}

void Player::setState(State* state) {
    markers[stateCounter].setState(state);
    stateCounter++;  
}