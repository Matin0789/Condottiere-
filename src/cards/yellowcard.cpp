#include "yellowcard.h"

YellowCard::YellowCard(unsigned int point) : Card(point,0){

}

std::string YellowCard::getType() const{
    return "YellowCard" + std::to_string(point);
}