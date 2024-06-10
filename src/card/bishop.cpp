#include "bishop.h"

class Game;
class Player;

#define HELP "When you play a Bishop, check which mercenary has the highest value among all player rows. Discard all copies of that card from all player rows"

Bishop::Bishop() : PurpleCard(0,"Bishop",1) {
    help = HELP ;
}

std::string Bishop::getHelp() {
    return help;
}