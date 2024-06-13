#include <stdexcept>

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

const std::vector<const Card*>& Player::getPlayedCards() const {
    return playedCards;
}

const std::vector<const Card*>& Player::getCards() const {
    return cards;
}

void Player::setCards(std::vector<const Card*> inputCards) {
    this->cards = inputCards;
}

void Player::setState(State* state) {
    markers[stateCounter].setState(state);
    stateCounter++;  
}

std::vector<std::string> Player::get_states_name() const{
    std::vector<std::string> stateNames;
    for (const auto marker : markers) {
        if (marker.is_set() == true)
            stateNames.push_back(marker.getState().getName());
    }
    return stateNames;
}

const Card* Player::drawn_card(std::string inputCard){
    for (size_t i = 0;i < cards.size(); i++) {
        if (cards[i]->getType() == inputCard) {
            const Card* card = cards[i];
            cards.erase(cards.begin() + i); 
            return card;
        }
    }
    throw std::invalid_argument("There is no such card");
}

void Player::push_to_cards(const Card* card){
    cards.push_back(card);
}

void Player::push_to_playedCards(const Card* card){
    playedCards.push_back(card);
}


const Card* Player::drawn_playedCard(std::string inputCard){
    for (size_t i = 0;i < playedCards.size(); i++) {
        if (playedCards[i]->getType() == inputCard) {
            const Card* card = playedCards[i];
            playedCards.erase(playedCards.begin() + i); 
            return card;
        }
    }
    throw std::invalid_argument("There is no such card");
}

size_t Player::getStateNumber() const {
    return stateCounter;
}

std::vector<const Card*> Player::burnCards(){
    std::vector<const Card*> tmp(cards);
    cards.clear();
    return tmp;
}
    
std::vector<const Card*> Player::burnPlayedCards(){
    std::vector<const Card*> tmp(playedCards);
    playedCards.clear();
    return tmp;
}
