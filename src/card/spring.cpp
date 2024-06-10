#include <algorithm>

#include "spring.h"

class Game;
class Player;

#define HELP "While Spring is in play, check which mercenary has the highest value among all player rows. Add “3” to the value of all copies of that card in all player rows. Note that the mercenary affected by Spring can change during the battle."

Spring::Spring() : Season(0,"Spring",4){
    help = HELP;
}

static bool compareByPoint(const Card& card1, const Card& card2){
    return card1.getPoint() < card2.getPoint();
}

std::string Spring::getHelp() {
    return help;
}