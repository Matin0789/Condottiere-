#include "turncoat.h"

class Game;
class Player;

#define HELP "The battle ends immediately with the winner determined as normal."

Turncoat::Turncoat() : PurpleCard(0,"Turncoat",0){
    help = HELP;
}

std::string Turncoat::getType() const {
    return name;
}