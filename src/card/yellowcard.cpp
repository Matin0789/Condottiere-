#include <string>
#include <vector>

#include "yellowcard.h"

YellowCard::YellowCard(unsigned int point) : Card(point,0){

}

std::string YellowCard::getType() const{
    return std::to_string(point);
}

void YellowCard::applyFeature(std::vector<std::vector<unsigned int>> playersCardPoints, int currentPlayerID) {
    playersCardPoints[currentPlayerID].push_back(this->point);
}