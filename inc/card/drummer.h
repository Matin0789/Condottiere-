#ifndef DRUMMER_H
#define DRUMMER_H

#include "purplecard.h"

class Drummer : public PurpleCard {
public:
    Drummer(std::string); // (help file path)
    static std::string getHelp();
    virtual void applyFeature(std::vector<std::vector<unsigned int>>&, int) const override;

protected:
private:
    static std::string help;
};

#endif // DRUMMER_H