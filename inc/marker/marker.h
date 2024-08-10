#ifndef MARKER_H
#define MARKER_H

#include "enumcolor.h"
#include "state.h"
#include "gameboard.h"

class Marker
{
private:
    State* state;
    bool set;
protected :
    Color color;
public:
    Marker(Color);
    void setState(State*);
    State& getState() const;
    bool is_set() const;
    Color getColor() const;
    bool save(std::string, size_t) const;
    bool load(std::string, GameBoard&, size_t, size_t);
    virtual std::string getType() const = 0;
};

#endif // MARKER_H
