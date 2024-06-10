#ifndef WINTER_H
#define WINTER_H

#include "season.h"

class Winter : public Season {
public:
    Winter();
    static std::string getHelp();
    virtual std::string getType() const override;
protected:
private:
    static std::string help;
    std::string name;
};

#endif // WINTER_H