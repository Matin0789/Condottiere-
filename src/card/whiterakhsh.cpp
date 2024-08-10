#include "whiterakhsh.h"
#include "player.h"
#include "game.h"

#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>

std::string whiterakhsh::help;

whiterakhsh::whiterakhsh(std::string helpFilePath) : PurpleCard(0,"whiterakhsh",3){
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
        throw std::runtime_error("The whiterakhsh help file cannot be opened");
}

std::string whiterakhsh::getHelp() {
    return help;
}

void whiterakhsh::applyFeature(std::vector<std::vector<unsigned int>>& playersCardPoints, int currentPlayerID) const {

}