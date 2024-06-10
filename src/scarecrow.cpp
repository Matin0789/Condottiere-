#include "scarecrow.h"
#include "player.h"
#include "game.h"

#define HELP "Take 1 mercenary from your row back to your hand."

Scarecrow::Scarecrow() : PurpleCard(0,"Scarecrow",0){
    help = HELP;
}

void Scarecrow::applyFeature(Player* player, Game* game) const{

}

std::string Scarecrow::getType() const {
    return name;
}