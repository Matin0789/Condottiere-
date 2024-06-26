#include "heroine.h"

class Game;
class Player;

#define HELP "For each Heroine in your row, add 10 to your strength."

std::string Heroine::help = HELP;

Heroine::Heroine() : PurpleCard(10,"Heroine",5){

}

std::string Heroine::getHelp() {
    return help;
}

void Heroine::applyFeature(std::vector<std::vector<unsigned int>>& playersCardPoint, int currentPlayerID) const {
    playersCardPoint[currentPlayerID].push_back(this->point);
}

