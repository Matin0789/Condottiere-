#include "turncoat.h"

#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>


std::string Turncoat::help;

Turncoat::Turncoat(std::string helpFilePath) : PurpleCard(0,"Turncoat",0){
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
        throw std::runtime_error("The Turncoat help file cannot be opened");
}

std::string Turncoat::getHelp() {
    return help;
}

void Turncoat::applyFeature(std::vector<std::vector<unsigned int>>& playersCardPoints, int currentPlayerID) const {
    
}