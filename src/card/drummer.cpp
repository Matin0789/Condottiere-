#include "drummer.h"
#include "player.h"
#include "game.h"

#define HELP "While you have a Drummer in your row, double the value of each mercenary in your row. You can play additional Drummers, but they have no effect."

std::string Drummer::help = HELP;

Drummer::Drummer() : PurpleCard(0,"Drummer",3){
    
}

std::string Drummer::getHelp() {
    return help;
}