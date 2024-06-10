#ifndef SCARECROW_H
#define SCARECROW_H

#include "purplecard.h"

class Scarecrow : public PurpleCard {
public:
    Scarecrow();
    static std::string getHelp();
<<<<<<< HEAD
    virtual std::string getType() const override;
=======
    void applyFeature(Player* player, Game* game) const ;
    std::string getType() const; 
>>>>>>> refs/remotes/origin/main
protected:
private:
    static std::string help;
    std::string name;
};

#endif // SCARECROW_H