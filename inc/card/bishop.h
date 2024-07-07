#ifndef BISHOP_H
#define BISHOP_H

#include <string>

#include "purplecard.h"


class Bishop : public PurpleCard {
public:
    Bishop(std::string); // (help file path)
    static std::string getHelp();
    virtual void applyFeature(std::vector<std::vector<unsigned int>>&, int) const override;
protected:
private:
    static std::string help;
};

#endif // BISHOP_H
