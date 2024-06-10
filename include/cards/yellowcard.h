#ifndef YELLOWCARD_H
#define YELLOWCARD_H

#include "card.h"

class YellowCard : public Card {
public:
    YellowCard(unsigned int);// (point)
<<<<<<< HEAD
    virtual std::string getType() const override;
=======
    std::string YellowCard::getType() const ;
>>>>>>> refs/remotes/origin/main
private:
};

#endif // YELLOWCARD_H