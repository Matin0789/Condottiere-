#include "whiteseals.h"
#include "player.h"
#include "game.h"

#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>

std::string whiteseals::help;

whiteseals::whiteseals(std::string helpFilePath) : PurpleCard(0,"whiteseals",3){
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
        throw std::runtime_error("The whiteseals help file cannot be opened");
}

std::string whiteseals::getHelp() {
    return help;
}

void whiteseals::applyFeature(std::vector<std::vector<unsigned int>>& playersCardPoints, int currentPlayerID) const {

}
 