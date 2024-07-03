#ifndef YELLOWCARD_H
#define YELLOWCARD_H

#include "card.h"

class YellowCard : public Card {
public:
    YellowCard(unsigned int);// (point)
    virtual std::string getType() const override;
    virtual void applyFeature(std::vector<std::vector<unsigned int>>&, int) const override;
private:
};

#endif // YELLOWCARD_H