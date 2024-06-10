#include "spy.h"

class Game;
class Player;

#define HELP "For each Spy in your row,add 1 to your strength.Also, after each battle, the player with the most Spies takes the battle marker instead of the player who won the battle. If players are tied for most Spies, the battle marker is taken as normal"

Spy::Spy() : PurpleCard(1,"Spy",5){
    help = HELP;
}

std::string Spy::getHelp() {
    return help;
}