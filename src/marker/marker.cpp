#include "marker.h"

Marker::Marker(Color inputColor) : color(inputColor), state(nullptr) {
    set = false;
}

State& Marker::getState() const{
    return *state;
}
void Marker::setState(State* state){
    this->state = state;
    this->state->set(true);
    set = true;
}

bool Marker::is_set() const{
    return set;
}