#include <vector>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>

#include "winter.h"
#include "player.h"
#include "game.h"

std::string Winter::help;

Winter::Winter(std::string helpFilePath) : Season(0,"Winter",2) {
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
        throw std::runtime_error("The Turncoat help file cannot be opened");
}

std::string Winter::getHelp(){
    return help;
}

void Winter::applyFeature(std::vector<std::vector<unsigned int>>& playersCardPoints, int currentPlayerID) const {
	for (auto &&CardsPoint : playersCardPoints)
	{
		if (!CardsPoint.empty()) {
			for (auto &&point : CardsPoint)
			{
                point = 1;
			}
		}
	}
	
}
