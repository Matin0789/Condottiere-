#ifndef SPY_H
#define SPY_H

#include "purplecard.h"

class Spy : public PurpleCard {
public:
    Spy();
    static std::string getHelp();
protected:
private:
    static std::string help;
};

#endif // SPY_H