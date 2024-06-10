#include "player.h"

std::string Player::getName() const {
    return name;
}

int Player::getID() const {
    return ID;
};

unsigned int Player::getPoint() const {
    return point;
}

void Player::setPoint(unsigned int point) {
    this->point;
}

const std::vector<Card*>& Player::getPlayedCards() const {
    return playedCards;
}

const std::vector<Card*>& Player::getCards() const {
    return cards;
}

void Player::setState(State* state) {
    markers[stateCounter].setState(state);
    stateCounter++;  
}