#include <algorithm>


#include "spring.h"

class Game;
class Player;

#define HELP "While Spring is in play, check which mercenary has the highest value among all player rows. Add “3” to the value of all copies of that card in all player rows. Note that the mercenary affected by Spring can change during the battle."

std::string Spring::help = HELP;

Spring::Spring() : Season(0,"Spring",4){

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