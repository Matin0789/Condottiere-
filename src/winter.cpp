#include "winter.h"
#include "player.h"
#include "game.h"

#define HELP "The value of each mercenary in play is “1.” This card replaces the current season"

Winter::Winter() : Season(0,"Winter",2){
  help = HELP ;
}

void Winter::applyFeature(Player* player, Game* game) const{

}

std::string Winter::getType() const {
    return name;
}