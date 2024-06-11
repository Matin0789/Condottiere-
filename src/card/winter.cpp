#include "winter.h"
#include "player.h"
#include "game.h"

#define HELP "The value of each mercenary in play is “1.” This card replaces the current season"

std::string Winter::help = HELP;

Winter::Winter() : Season(0,"Winter",2){
  help = HELP ;
}

std::string Winter::getHelp(){
    return help;
}