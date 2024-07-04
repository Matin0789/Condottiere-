#include "spy.h"

#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>

std::string Spy::help;

Spy::Spy(std::string helpFilePath) : PurpleCard(1,"Spy",5){
    std::ifstream helpFile(helpFilePath, std::ios::in);
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
        throw std::runtime_error("The Spy help file cannot be opened");
}

std::string Spy::getHelp() {
    return help;
}

void Spy::applyFeature(std::vector<std::vector<unsigned int>>& playersCardPoint, int currentPlayerID) const {
    playersCardPoint[currentPlayerID].push_back(point);
}