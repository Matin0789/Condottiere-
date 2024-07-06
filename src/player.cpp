#include <stdexcept>
#include <fstream>

#include "player.h"

Player::Player(std::string inputName, size_t inputID, unsigned int inputAge, Color inputColor) : // constructor
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

std::string Player::getName() const {   // Submit name
    return name;
}

int Player::getAge() const  // submit age
{
    return age;
}

int Player::getID() const {  // submit id
    return ID;
};

const std::vector<const Card*>& Player::getPlayedCards() const {  // submit played cards
    return playedCards;
}

const std::vector<const Card*>& Player::getCards() const {   // submit vector of playercards
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
    throw std::invalid_argument("There is no such card");  // exception 
}

size_t Player::getStateNumber() const {  // counter of Conquered provinces
    return stateCounter;
}

std::vector<const Card*> Player::burnCards(){   
    std::vector<const Card*> tmp(cards);
    cards.clear();
    return tmp;
}
    
std::vector<const Card*> Player::burnPlayedCards(){  // killing cards or delete cards 
    std::vector<const Card*> tmp(playedCards);
    playedCards.clear(); // remove from player hands 
    return tmp;
}

bool Player::save(std::string filePath) const{
    std::ofstream file(filePath, std::ios::binary | std::ios::app);
    if (!file) {
        throw std::runtime_error("save file cannot be open in player" + ID);
    }
    

    // name
    {
        size_t size = name.capacity();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size_t));
        file.write(reinterpret_cast<const char*>(&name), size);
    }
    
    // ID
    file.write(reinterpret_cast<const char*>(&ID), sizeof(size_t));

    // age
    file.write(reinterpret_cast<const char*>(&age), sizeof(size_t));

    // save cards
    {
        size_t size = cards.size();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size_t));
        for (auto &&card : cards) {
            size_t capacity = card->getType().capacity();
            file.write(reinterpret_cast<const char*>(&capacity), sizeof(size_t));
            std::string tmp = card->getType();
            file.write(reinterpret_cast<const char*>(&tmp), capacity);
        }  
    }
    

    // save played cards
    {
        size_t size = playedCards.size();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size_t));
        for (auto &&playedCard : playedCards) {
            size_t capacity = playedCard->getType().capacity();
            file.write(reinterpret_cast<const char*>(&capacity), sizeof(size_t));
            std::string tmp = playedCard->getType();
            file.write(reinterpret_cast<const char*>(&tmp), capacity);
        }
    }
    
    // state counter
    file.write(reinterpret_cast<const char*>(&stateCounter), sizeof(size_t));

    file.close();

    // markers
    for (auto &&marker : markers)
    {
        marker.save(filePath);
    }
    return true;
}
