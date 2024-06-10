#ifndef TURNCOAT_H
#define TURNCOAT_H

#include "purplecard.h"
#include "game.h"

class Turncoat : public PurpleCard {
public:
    Turncoat();
    static std::string getHelp();
    virtual std::string getType() const override;
protected:
private:
    static std::string help;
};

#endif // TURNCOAT_H