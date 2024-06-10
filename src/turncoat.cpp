#include "turncoat.h"
#include "player.h"
#include "game.h"

#define HELP "The battle ends immediately with the winner determined as normal."

Turncoat::Turncoat() : PurpleCard(0,"Turncoat",0){
    help = HELP;
}

void Turncoat::applyFeature(Player* player, Game* game) const{
    
}

std::string Turncoat::getType() const {
    return name;
}