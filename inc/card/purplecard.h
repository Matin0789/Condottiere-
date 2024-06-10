#ifndef PURPLECARD_H
#define PURPLECARD_H

#include <string>

#include "card.h"

class PurpleCard : public Card {
public:
    PurpleCard(int, std::string, int);// (point,type,priority)
    virtual std::string getType() const override;
protected:
private:
    const std::string type;
};

#endif // PURPLECARD_H
