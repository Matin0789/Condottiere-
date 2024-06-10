#ifndef SPY_H
#define SPY_H

#include "purplecard.h"

class Spy : public PurpleCard {
public:
    Spy();
<<<<<<< HEAD
    static std::string getHelp();
    virtual std::string getType() const override;
protected:
private:
    static std::string help;
=======
    void applyFeature(Player* player, Game* game) const;
    std::string Spy::getType() const ;
protected:
private:
    static std::string help;
    unsigned int point;
    std::string name;
>>>>>>> refs/remotes/origin/main
};

#endif // SPY_H