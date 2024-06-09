#ifndef STATE_H
#define STATE_H

#include <string>

class State
{
private:
    std::string name;
public:
    State(std::string); // (name)
    ~State();
    std::string getName() const;
};

#endif //STATE_H