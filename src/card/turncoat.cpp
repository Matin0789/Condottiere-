#include "turncoat.h"

class Game;
class Player;

#define HELP "The battle ends immediately with the winner determined as normal."

std::string Turncoat::help = HELP;

Turncoat::Turncoat() : PurpleCard(0,"Turncoat",0){
    help = HELP;
}

std::string Turncoat::getHelp() {
    return help;
}

void Turncoat::applyFeature(std::vector<std::vector<unsigned int>> playersCardPoints, int currentPlayerID) {
    
}