#include "state.h"

State::State(std::string inputName) : name(inputName) {

}

std::string State::getName() const {
    return name;
}