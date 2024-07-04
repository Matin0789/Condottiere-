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
            helpString << tmp;
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
    unsigned int minPoint = 0;
    for (auto &&cardsPoint : playersCardPoints)
    {
        unsigned int playerMinPoint = *std::min_element(cardsPoint.begin(), cardsPoint.end());
        minPoint = (minPoint > playerMinPoint) ? playerMinPoint:minPoint;
    }
    
    for (auto &&cardsPoint : playersCardPoints)
	{
		if (!cardsPoint.empty()) {
			for (auto &&point : cardsPoint)
			{
				if (point == minPoint) {
                    point = 0;
                }
			}
		}
	}
}