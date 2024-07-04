#ifndef TURNCOAT_H
#define TURNCOAT_H

#include "purplecard.h"

class Game;

class Turncoat : public PurpleCard {
public:
    Turncoat(std::string); // (help path)
    static std::string getHelp();
    virtual void applyFeature(std::vector<std::vector<unsigned int>>&, int) const override;

protected:
private:
    static std::string help;
};

#endif // TURNCOAT_H