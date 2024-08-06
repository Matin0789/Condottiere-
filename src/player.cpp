#include <stdexcept>
#include <fstream>

#include "player.h"

#include "yellowcard.h"
#include "bishop.h"
#include "drummer.h"
#include "heroine.h"
#include "scarecrow.h"
#include "spy.h"
#include "winter.h"
#include "spring.h"
#include "turncoat.h"

#include "filepath.h"

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
}

std::string Player::getColor() const {
    std::string color;
    switch(markers[0].getColor()){
    case orange :
        color = "orange";
        break;
    case blue   :
        color = "blue";
        break;
    case green  :
        color = "green";
        break;
    case red    :
        color = "red";
        break;
    case gray   :
        color = "gray";
        break;
    case brown  :
        color = "brown";
        break;
    default     :
        color = "white";
        break;
    }
    return color;
}

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
        throw std::runtime_error("file " + filePath + " cannot be open in player" + std::to_string(ID));
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

bool Player::load(std::string filePath, GameBoard& gameBoard) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        throw std::runtime_error("file " + filePath + " cannot be open in player" + std::to_string(ID));
    }

    // name
    {
        size_t size;
        file.read(reinterpret_cast<char*>(&size), sizeof(size_t));
        file.read(reinterpret_cast<char*>(&name), size);
    }

    // ID
    file.read(reinterpret_cast<char*>(&ID), sizeof(size_t));

    // age
    file.read(reinterpret_cast<char*>(&age), sizeof(size_t));

    // read cards
    {
        size_t size;
        file.read(reinterpret_cast<char*>(&size), sizeof(size_t));
        for (size_t i = 0; i < size; i++)
        {
            size_t capacity;
            file.read(reinterpret_cast<char*>(&capacity), sizeof(size_t));
            std::string cardName;
            file.read(reinterpret_cast<char*>(&cardName), sizeof(capacity));
            if (cardName == "1")
                cards.push_back(new YellowCard(1));
            else if (cardName == "2")
                cards.push_back(new YellowCard(2));
            else if (cardName == "3")
                cards.push_back(new YellowCard(3));
            else if (cardName == "4")
                cards.push_back(new YellowCard(4));
            else if (cardName == "5")
                cards.push_back(new YellowCard(5));
            else if (cardName == "6")
                cards.push_back(new YellowCard(6));
            else if (cardName == "10")
                cards.push_back(new YellowCard(10));
            else if (cardName == "Heroine")
                cards.push_back(new Heroine(HEROINE_HELP_FILE));
            else if (cardName == "Turncoat")
                cards.push_back(new Turncoat(TURNCOAT_HELP_FILE));
            else if (cardName == "Scarecrow")
                cards.push_back(new Scarecrow(SCARECROW_HELP_FILE));
            else if (cardName == "Drummer")
                cards.push_back(new Drummer(DRUMMER_HELP_FILE));
            else if (cardName == "Bishop")
                cards.push_back(new Bishop(BISHOP_HELP_FILE));
            else if (cardName == "Spy")
                cards.push_back(new Spy(SPY_HELP_FILE));
            else 
                throw std::runtime_error("card" + cardName + " not found");
        }
    }

    // read played cards
    {
        size_t size;
        file.read(reinterpret_cast<char*>(&size), sizeof(size_t));
        for (size_t i = 0; i < size; i++)
        {
            size_t capacity;
            file.read(reinterpret_cast<char*>(&capacity), sizeof(size_t));
            std::string cardName;
            file.read(reinterpret_cast<char*>(&cardName), sizeof(capacity));
            if (cardName == "1")
                playedCards.push_back(new YellowCard(1));
            else if (cardName == "2")
                playedCards.push_back(new YellowCard(2));
            else if (cardName == "3")
                playedCards.push_back(new YellowCard(3));
            else if (cardName == "4")
                playedCards.push_back(new YellowCard(4));
            else if (cardName == "5")
                playedCards.push_back(new YellowCard(5));
            else if (cardName == "6")
                playedCards.push_back(new YellowCard(6));
            else if (cardName == "10")
                playedCards.push_back(new YellowCard(10));
            else if (cardName == "Heroine")
                playedCards.push_back(new Heroine(HEROINE_HELP_FILE));
            else if (cardName == "Turncoat")
                playedCards.push_back(new Turncoat(TURNCOAT_HELP_FILE));
            else if (cardName == "Scarecrow")
                playedCards.push_back(new Scarecrow(SCARECROW_HELP_FILE));
            else if (cardName == "Drummer")
                playedCards.push_back(new Drummer(DRUMMER_HELP_FILE));
            else if (cardName == "Bishop")
                cards.push_back(new Bishop(BISHOP_HELP_FILE));
            else if (cardName == "Spy")
                playedCards.push_back(new Spy(SPY_HELP_FILE));
            else 
                throw std::runtime_error("card" + cardName + " not found");
        }
    }

    // state counter
    file.read(reinterpret_cast<char*>(&stateCounter), sizeof(size_t));

    file.close();
    return true;
}
