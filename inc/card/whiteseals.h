#ifndef WHITESEALS_H
#define WHITESEALS_H

#include "purplecard.h"

class WhiteSeal : public PurpleCard {
public:
    WhiteSeal
(std::string); // (help file path)
    static std::string getHelp();
    virtual void applyFeature(std::vector<std::vector<unsigned int>>&, int) const override;

protected:
private:
    static std::string help;
};

#endif // WHITESEALS_H
