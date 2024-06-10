#ifndef MARKER_H
#define MARKER_H

#include "enumcolor.h"
#include "state.h"

class Marker
{
private:
    State *state;
    const Color color;
    bool set;
public:
    Marker(Color);
    void setState(State*);
    const State& getState() const;
    bool is_set() const;
};

#endif // MARKER_H