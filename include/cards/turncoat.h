#ifndef TURNCOAT_H
#define TURNCOAT_H

#include "purplecard.h"
#include "game.h"

class Turncoat : public PurpleCard {
public:
    Turncoat();
    static std::string getHelp();
<<<<<<< HEAD
    virtual std::string getType() const override;
=======
    void applyFeature(Player* player, Game* game) const;
    std::string getType() const ;
>>>>>>> refs/remotes/origin/main
protected:
private:
    static std::string help;
    std::string name;
};

#endif // TURNCOAT_H