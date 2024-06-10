#include "player.h"
#include "game.h"
#include "card.h"

Card::Card(unsigned int inputPoint,unsigned int inputPriority) : point(inputPoint), priority(inputPriority) {}

unsigned int Card::getPriority() const {
    return priority;
}

unsigned int Card::getPoint() const {
    return point ;
}

bool Card::is_season() const{
    return false;
}

void Card::setPoint(unsigned int) {
   this->point = point ; 
}