#include "heroine.h"

#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>

std::string Heroine::help;

Heroine::Heroine(std::string helpFilePath) : PurpleCard(10,"Heroine",5){
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
        throw std::runtime_error("The Heroine help file cannot be opened");
}

std::string Heroine::getHelp() {
    return help;
}

void Heroine::applyFeature(std::vector<std::vector<unsigned int>>& playersCardPoint, int currentPlayerID) const {
    playersCardPoint[currentPlayerID].push_back(this->point);
}

