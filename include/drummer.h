#ifndef DRUMMER_H
#define DRUMMER_H

#include "purplecard.h"

class Drummer : public PurpleCard {
public:
    Drummer();
    static std::string getHelp();
    virtual std::string getType() const override;
protected:
private:
    static std::string help;
};

#endif // DRUMMER_H