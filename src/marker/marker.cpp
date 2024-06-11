#include "marker.h"

Marker::Marker(Color inputColor) : color(inputColor) {
    set = false;
}

const State& Marker::getState() const{
    return *state;
}
void Marker::setState(const State* state){
    this->state = state;
    set = true;
}

bool Marker::is_set() const{
    return set;
}