#ifndef HEROINE_H
#define HEROINE_H

#include "purplecard.h"

class Heroine : public PurpleCard {
public:
    Heroine();
    static std::string getHelp();
<<<<<<< HEAD
    virtual std::string getType() const override;
=======
    void applyFeature(Player* player, Game* game) const;
    std::string Heroine::getType() const ;
>>>>>>> refs/remotes/origin/main
protected:
private:
    static std::string help;
    unsigned int point;
    std::string name;
};

#endif // HEROINE_H