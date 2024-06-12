#ifndef SCARECROW_H
#define SCARECROW_H

#include "purplecard.h"

class Scarecrow : public PurpleCard {
public:
    Scarecrow();
    static std::string getHelp();
    virtual void applyFeature(std::vector<std::vector<unsigned int>>, int) override;

protected:
private:
    static std::string help;
};

#endif // SCARECROW_H