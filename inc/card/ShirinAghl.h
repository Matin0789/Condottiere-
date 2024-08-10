#ifndef SHIRINAGHL_H
#define SHIRINAGHL_H

#include "purplecard.h"
#include "bishop.h"
#include "filepath.h"

class ShirinAghl : public PurpleCard {
public:
    ShirinAghl(std::string); // (help file path)
    static std::string getHelp();
    virtual void applyFeature(std::vector<std::vector<unsigned int>>&, int) const override;
   // virtual void shirinAghlFeature(const Player&)  override;
    virtual std::string getType() const override;
protected:
private:
    static std::string help;
    Card *equalCard;
};

#endif // SHIRINAGHL_H
