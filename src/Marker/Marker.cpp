#include "Marker.h"

Marker::Marker(Color inputColor) : color(inputColor) {
    set = false;
}

State* Marker::getState() const{
    return state;
}
void Marker::setState(State* state){
    this->state = state;
    set = true;
}

bool Marker::is_set() const{
    return set;
}