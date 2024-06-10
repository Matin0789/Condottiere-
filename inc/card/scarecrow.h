#ifndef SCARECROW_H
#define SCARECROW_H

#include "purplecard.h"

class Scarecrow : public PurpleCard {
public:
    Scarecrow();
    static std::string getHelp();
    virtual std::string getType() const override;
protected:
private:
    static std::string help;
    std::string name;
};

#endif // SCARECROW_H