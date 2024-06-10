#ifndef TURNCOAT_H
#define TURNCOAT_H

#include "purplecard.h"
#include "game.h"

class Turncoat : public PurpleCard {
public:
    Turncoat();
    static std::string getHelp();
    virtual std::string getType() const override;
    void applyFeature(Player* player, Game* game) const;
protected:
private:
    static std::string help;
    std::string name;
};

#endif // TURNCOAT_H