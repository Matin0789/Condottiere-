#include "winter.h"
#include "player.h"
#include "game.h"

#define HELP ""

Winter::Winter() : Season(0,"Winter",2,HELP){
    
}

void Card::applyFeature(Player* player, Game* game) const{
    for (auto &&player : game->players){
        for (auto &&card : player.playedCards)
            if (card.getType().substr(0,10) == "YellowCard")
                card.setPoint(1);
    }
}

std::string Winter::getType() const {
    return name;
}