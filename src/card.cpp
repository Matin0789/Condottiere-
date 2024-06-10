
#include "player.h"
#include "game.h"
#include "card.h"

unsigned int Card::getPriority() const {
    return priority ;
}

unsigned int Card::getPoint() const {
    return point ;
}

void Card::setPoint(unsigned int) {
   this->point = point ; 
}