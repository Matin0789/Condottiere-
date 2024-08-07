#include <algorithm>
#include <fstream>
#include <sstream>

#include "bishop.h"


std::string Bishop::help;

Bishop::Bishop(std::string helpFilePath) : PurpleCard(0,"Bishop",1) {
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
        throw std::runtime_error("The Bishop help file cannot be opened");
}


std::string Bishop::getHelp() {
    return Bishop::help;
}

void Bishop::applyFeature(std::vector<std::vector<unsigned int>>& playersCardPoints, int currentPlayerID) const {
    unsigned int maxPoint = 0;
    for (auto &&cardsPoint : playersCardPoints)
    {
        if (!cardsPoint.empty()) {
            unsigned int playerMaxPoint = *std::max_element(cardsPoint.begin(), cardsPoint.end());
            maxPoint = (maxPoint < playerMaxPoint) ? playerMaxPoint:maxPoint;
        }
    }
    
    for (auto &&cardsPoint : playersCardPoints)
	{
		if (!cardsPoint.empty()) {
            for (auto &&cardPoint : cardsPoint)
			{
                if (cardPoint == maxPoint) {
                    cardPoint = 0;
                }
			}
		}
	}
}
