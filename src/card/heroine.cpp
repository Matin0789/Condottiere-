#include "heroine.h"

class Game;
class Player;

#define HELP "For each Heroine in your row, add 10 to your strength."
Heroine::Heroine() : PurpleCard(10,"Heroine",5){
    help = HELP ;
}

std::string Heroine::getHelp() {
    return help;
}

