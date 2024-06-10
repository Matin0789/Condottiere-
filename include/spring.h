#ifndef SPRING_H
#define SPRING_H

#include "season.h"

class Spring : public Season {
public:
    Spring();
    static std::string getHelp();
    virtual std::string getType() const override;
    void applyFeature(Player* player, Game* game) const; 
protected:
private:
    static std::string help;
    std::string name;
};

#endif // SPRING_H