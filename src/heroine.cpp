#include "heroine.h"
#include "player.h"
#include "game.h"

#define HELP "For each Heroine in your row, add 10 to your strength."
Heroine::Heroine() : PurpleCard(10,"Heroine",5){
    help = HELP ;
}

void Heroine::applyFeature(Player* player, Game* game) const{

}

std::string Heroine::getType() const {
    return name;
}