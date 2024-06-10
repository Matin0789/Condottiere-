#ifndef SPY_H
#define SPY_H

#include "purplecard.h"

class Spy : public PurpleCard {
public:
    Spy();
    static std::string getHelp();
    virtual std::string getType() const override;
    void applyFeature(Player* player, Game* game) const;
protected:
    
private:
    static std::string help;
    unsigned int point;
    std::string name;
};

#endif // SPY_H