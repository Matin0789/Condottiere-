#ifndef YELLOWCARD_H
#define YELLOWCARD_H

#include "card.h"

class YellowCard : public Card {
public:
    YellowCard(unsigned int);// (point)
    std::string YellowCard::getType() const ;
private:
};

#endif // YELLOWCARD_H