#include "scarecrow.h"
#include "player.h"
#include "game.h"

#define HELP "Take 1 mercenary from your row back to your hand."

std::string Scarecrow::help = HELP;

Scarecrow::Scarecrow() : PurpleCard(0,"Scarecrow",0){

}

std::string Scarecrow::getHelp() {
    return help;
}