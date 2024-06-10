#ifndef WINTER_H
#define WINTER_H

#include "season.h"

class Winter : public Season {
public:
    Winter();
    static std::string getHelp();
protected:
private:
    static std::string help;
};

#endif // WINTER_H