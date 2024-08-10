#ifndef SHIRINAGHL_H
#define SHIRINAGHL_H

#include "purplecard.h"

class shirinaghl : public PurpleCard {
public:
    shirinaghl(std::string); // (help file path)
    static std::string getHelp();
    virtual void applyFeature(std::vector<std::vector<unsigned int>>&, int) const override;

protected:
private:
    static std::string help;
};

#endif // SHIRINAGHL_H
