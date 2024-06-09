#include "scarecrow.h"
#include "player.h"
#include "game.h"

#define HELP ""

Scarecrow::Scarecrow() : PurpleCard(0,"Scarecrow",0,HELP){
    
}

void Scarecrow::applyFeature(Player* player, Game* game) const{
    game->interface.showYellowCards(player->getPlayedCards());
    player->playedCards.erase(player->playedCards.begin() + game->interface.getNumber());
    player->playedCards.push_back(*this);
}

std::string Scarecrow::getType() const {
    return name;
}