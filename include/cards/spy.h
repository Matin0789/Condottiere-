#ifndef SPY_H
#define SPY_H

#include "purplecard.h"

class Spy : public PurpleCard {
public:
    Spy();
    void applyFeature(Player* player, Game* game) const;
    std::string Spy::getType() const ;
protected:
private:
    static std::string help;
    unsigned int point;
    std::string name;
};

#endif // SPY_H