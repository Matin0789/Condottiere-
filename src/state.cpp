#include "state.h"

State::State(std::string inputName) : name(inputName), set_marker(false) {

}

std::string State::getName() const {
    return name;
}

void State::set(bool inputSet) {
    set_marker = inputSet;
}

bool State::is_set() const{
    return set_marker;
}