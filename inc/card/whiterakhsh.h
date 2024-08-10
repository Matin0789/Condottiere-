#ifndef WHITERAKHSH_H
#define WHITERAKHSH_H

#include "purplecard.h"

class WhiteRakhsh : public PurpleCard {
public:
    WhiteRakhsh(std::string); // (help file path)
    static std::string getHelp();
    virtual void applyFeature(std::vector<std::vector<unsigned int>>&, int) const override;

protected:
private:
    static std::string help;
};

#endif // WHITERAKHSH_H
