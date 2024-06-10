#ifndef TURNCOAT_H
#define TURNCOAT_H

#include "purplecard.h"

class Game;

class Turncoat : public PurpleCard {
public:
    Turncoat();
    static std::string getHelp();
    virtual std::string getType() const override;
protected:
private:
    static std::string help;
    std::string name;
};

#endif // TURNCOAT_H