#ifndef SPY_H
#define SPY_H

#include "purplecard.h"

class Spy : public PurpleCard {
public:
    Spy(std::string);//(help file path)
    static std::string getHelp();
    virtual void applyFeature(std::vector<std::vector<unsigned int>>&, int) const override;

protected:
    
private:
    static std::string help;
    unsigned int point;
};

#endif // SPY_H