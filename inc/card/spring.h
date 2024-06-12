#ifndef SPRING_H
#define SPRING_H

#include "season.h"

class Spring : public Season {
public:
    Spring();
    static std::string getHelp();
    virtual void applyFeature(std::vector<std::vector<unsigned int>>, int) override;

protected:
private:
    static std::string help;
};

#endif // SPRING_H