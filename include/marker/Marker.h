#ifndef MARKER_H
#define MARKER_H

#include "enumColor.h"
#include "State.h"

class Marker
{
private:
    State *state;
    const Color color;
    bool set;
public:
    Marker(Color);
    ~Marker();
    void setState(State*);
    State* getState() const;
    bool is_set() const;
};

#endif // MARKER_H