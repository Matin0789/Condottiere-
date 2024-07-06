#include <algorithm>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>

#include "spring.h"

std::string Spring::help;

Spring::Spring(std::string helpFilePath) : Season(0,"Spring",4){
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
        throw std::runtime_error("The Spring help file cannot be opened");
}

std::string Spring::getHelp() {
    return help;
}

void Spring::applyFeature(std::vector<std::vector<unsigned int>>& playersCardPoints, int currentPlayerID) const{
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
			for (auto &&point : cardsPoint)
			{
				if (point == maxPoint) {
                    point += 3;
                }
			}
		}
	}
    
}