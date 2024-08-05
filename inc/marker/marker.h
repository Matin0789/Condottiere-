#ifndef MARKER_H
#define MARKER_H

#include "enumcolor.h"
#include "state.h"
#include "gameboard.h"

class Marker
{
private:
    State* state;
    Color color;
    bool set;
public:
    Marker(Color);
    void setState(State*);
    State& getState() const;
    bool is_set() const;
    Color getColor() const;
    bool save(std::string) const;
    bool load(std::string, GameBoard&);
    virtual std::string getType() const = 0;
};

#endif // MARKER_H
