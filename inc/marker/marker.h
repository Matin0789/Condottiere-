#ifndef MARKER_H
#define MARKER_H

#include "enumcolor.h"
#include "state.h"

class Marker
{
private:
    State* state;
    const Color color;
    bool set;
public:
    Marker(Color);
    void setState(State*);
    State& getState() const;
    bool is_set() const;
    bool save(std::string) const;
    bool load(std::string);
};

#endif // MARKER_H