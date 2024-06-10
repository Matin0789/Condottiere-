#include "heroine.h"
#include "player.h"
#include "game.h"

#define HELP ""

Heroine::Heroine() : PurpleCard(10,"Heroine",5){
    help = HELP ;
}

void Heroine::applyFeature(Player* player, Game* game) const{
   // player->point += point;
}

std::string Heroine::getType() const {
    return name;
}