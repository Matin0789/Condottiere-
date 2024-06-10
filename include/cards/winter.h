#ifndef WINTER_H
#define WINTER_H

#include "season.h"

class Winter : public Season {
public:
    Winter();
    static std::string getHelp();
    virtual std::string getType() const override;
    void applyFeature(Player* player, Game* game) const;
protected:
private:
    static std::string help;
    
};

#endif // WINTER_H