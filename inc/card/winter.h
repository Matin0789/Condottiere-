#ifndef WINTER_H
#define WINTER_H

#include <string>

#include "season.h"

class Winter : public Season {
public:
    Winter(std::string); //(help file path)
    static std::string getHelp();
    virtual void applyFeature(std::vector<std::vector<unsigned int>>&, int) const override;

protected:
private:
    static std::string help;
};

#endif // WINTER_H