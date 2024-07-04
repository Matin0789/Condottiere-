#include "scarecrow.h"
#include "player.h"
#include "game.h"

#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>


std::string Scarecrow::help;

Scarecrow::Scarecrow(std::string helpFilePath) : PurpleCard(0,"Scarecrow",0){
    std::ifstream helpFile(helpFilePath);
    if (helpFile.is_open()){
        std::stringstream helpString;
        std::string tmp;
        while(getline(helpFile,tmp)){
            helpString << tmp;
        }
        help = helpString.str();
        helpFile.close();
    }
    else 
        throw std::runtime_error("The Scarecrow help file cannot be opened");
}

std::string Scarecrow::getHelp() {
    return help;
}

void Scarecrow::applyFeature(std::vector<std::vector<unsigned int>>& playersCardPoints, int currentPlayerID) const {
    
}