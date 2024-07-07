#ifndef SPRING_H
#define SPRING_H

#include <string>

#include "season.h"

class Spring : public Season {
public:
    Spring(std::string); //(help file path)
    static std::string getHelp();
    virtual void applyFeature(std::vector<std::vector<unsigned int>>&, int) const override;

protected:
private:
    static std::string help;
};

#endif // SPRING_H