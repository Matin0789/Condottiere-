#ifndef BISHOP_H
#define BISHOP_H

#include <string>

#include "purplecard.h"


class Bishop : public PurpleCard {
public:
    Bishop();
    static std::string getHelp();
    virtual void applyFeature(std::vector<std::vector<unsigned int>>, int) override;
protected:
private:
    static std::string help;
};

#endif // BISHOP_H
