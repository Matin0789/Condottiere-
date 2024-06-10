#ifndef SPRING_H
#define SPRING_H

#include "season.h"

class Spring : public Season {
public:
    Spring();
    static std::string getHelp();
protected:
private:
    static std::string help;
};

#endif // SPRING_H