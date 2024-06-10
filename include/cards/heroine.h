#ifndef HEROINE_H
#define HEROINE_H

#include "purplecard.h"

class Heroine : public PurpleCard {
public:
    Heroine();
    static std::string getHelp();
    virtual std::string getType() const override;
protected:
private:
    static std::string help;
};

#endif // HEROINE_H