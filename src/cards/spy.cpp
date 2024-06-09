#include "spy.h"
#include "player.h"
#include "game.h"

#define HELP ""

Spy::Spy() : PurpleCard(1,"Spy",5,HELP){
    
}

void Card::applyFeature(Player* player, Game* game) const{
    player->point += point;
    
}

std::string Spy::getType() const {
    return name;
}