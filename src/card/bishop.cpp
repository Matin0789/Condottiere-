#include <algorithm>

#include "bishop.h"

class Game;
class Player;

#define HELP "When you play a Bishop, check which mercenary has the highest value among all player rows. Discard all copies of that card from all player rows"

std::string Bishop::help = HELP;

Bishop::Bishop() : PurpleCard(0,"Bishop",1) {
}

std::string Bishop::getHelp() {
    return Bishop::help;
}

void Bishop::applyFeature(std::vector<std::vector<unsigned int>> playersCardPoints, int currentPlayerID) { 
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