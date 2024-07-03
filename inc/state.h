#ifndef STATE_H
#define STATE_H

#include <string>

class State
{
public:
    State(std::string); // (name)
    std::string getName() const;
    bool is_set() const;
    void set(bool);
private:
    std::string name;
    bool set_marker;
};

#endif //STATE_H