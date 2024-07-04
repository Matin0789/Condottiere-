#ifndef HEROINE_H
#define HEROINE_H

#include "purplecard.h"

class Heroine : public PurpleCard {
public:
    Heroine(std::string); // (help file path)
    static std::string getHelp();
    virtual void applyFeature(std::vector<std::vector<unsigned int>>&, int) const override;
protected:
private:
    static std::string help;
};

#endif // HEROINE_H