#include <algorithm>

#include "Spring.h"
#include "Player.h"
#include "Game.h"

#define HELP ""

Spring::Spring() : Season(0,"Spring",4,HELP){
    
}

static bool compareByPoint(const Card& card1, const Card& card2){
    return card1.getPoint() < card2.getPoint();
}

void Card::applyFeature(Player* player, Game* game) const {
    std::vector<Card>::iterator maxCard;
    for (auto &&player : game->players){
        std::vector<Card>::iterator localMaxCard;
        localMaxCard = std::max_element(player.playedCards.begin(), player.playedCards.end(), compareByPoint);
        if (maxCard->getPoint() < localMaxCard->getPoint()) {
            maxCard = localMaxCard;
        }
    }
    for (auto &&player : game->players){
        for (auto &&card : player.playedCards)
            if (card.getPoint() == maxCard->getPoint() && card.getType().substr(0,10) == "YellowCard"){
                card.setPoint(card.getPoint() + 3);
            }
        
    }
        
    
}

std::string Spring::getType() const {
    return name;
}