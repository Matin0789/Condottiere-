#ifndef BISHOP_H
#define BISHOP_H

#include <string>

#include "purplecard.h"


class Bishop : public PurpleCard {
public:
    Bishop();
    static std::string getHelp();
protected:
private:
    static std::string help;
};

#endif // BISHOP_H