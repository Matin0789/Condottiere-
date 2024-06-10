#ifndef TURNCOAT_H
#define TURNCOAT_H

#include "purplecard.h"

class Game;

class Turncoat : public PurpleCard {
public:
    Turncoat();
    static std::string getHelp();
protected:
private:
    static std::string help;
};

#endif // TURNCOAT_H