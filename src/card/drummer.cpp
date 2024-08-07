#include "drummer.h"
#include "player.h"
#include "game.h"

#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>

std::string Drummer::help;

Drummer::Drummer(std::string helpFilePath) : PurpleCard(0,"Drummer",3){
    std::ifstream helpFile(helpFilePath);
    if (helpFile.is_open()){
        std::stringstream helpString;
        std::string tmp;
        while(getline(helpFile,tmp)){
            helpString << '\n' << tmp;
        }
        help = helpString.str();
        helpFile.close();
    }
    else 
        throw std::runtime_error("The Drummer help file cannot be opened");
}

std::string Drummer::getHelp() {
    return help;
}

void Drummer::applyFeature(std::vector<std::vector<unsigned int>>& playersCardPoints, int currentPlayerID) const {
    for (auto &&point : playersCardPoints[currentPlayerID])
    {
        point *= 1.5;  // point*=2
        //This change is for the third phase of the project 
    }
    
}