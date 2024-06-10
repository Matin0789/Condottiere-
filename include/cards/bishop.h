#ifndef BISHOP_H
#define BISHOP_H

#include <string>

#include "purplecard.h"


class Bishop : public PurpleCard {
public:
    Bishop();
    virtual std::string getType() const override;
    static std::string getHelp();
protected:
private:
    static std::string help;
};

#endif // BISHOP_H