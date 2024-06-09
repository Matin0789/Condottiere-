#include "drummer.h"
#include "player.h"
#include "game.h"

#define HELP "While you have a Drummer in your row, double the value of each mercenary in your row. You can play additional Drummers, but they have no effect."

Drummer::Drummer() : PurpleCard(0,"Drummer",3,HELP){
    
}

void Drummer::applyFeature(Player* player, Game* game) const{
    for (auto &&card : player->playedCards)
        if (card.getType().substr(0,10) == "YellowCard")
            card.setPoint(card.getPoint() * 2);
}

std::string Drummer::getType() const {
    return name;
}