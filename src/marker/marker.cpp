#include "marker.h"

Marker::Marker(Color inputColor) : color(inputColor) {
    set = false;
}

const State& Marker::getState() const{
    return *state;
}
void Marker::setState(State* state){
    this->state->set(false);
    this->state = state;
    this->state->set(true);
    set = true;
}

bool Marker::is_set() const{
    return set;
}