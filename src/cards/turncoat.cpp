#include "turncoat.h"
#include "player.h"
#include "game.h"

#define HELP ""

Turncoat::Turncoat() : PurpleCard(0,"Turncoat",0){
    help = HELP;
}

void Turncoat::applyFeature(Player* player, Game* game) const{
    
}

std::string Turncoat::getType() const {
    return name;
}