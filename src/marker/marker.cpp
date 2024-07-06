#include "marker.h"

#include <fstream>

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

bool Marker::save(std::string filePath) const {
    std::ofstream file(filePath, std::ios::binary | std::ios::app);
    if (!file) {
        throw std::runtime_error("save file cannot be open in marker");
    }

    std::string stateName = state->getName();
    size_t size = stateName.capacity();
    file.write(reinterpret_cast<const char*>(&size), sizeof(size_t));
    file.write(reinterpret_cast<const char*>(&stateName), size);

    file.write(reinterpret_cast<const char*>(&color), sizeof(Color));
    file.write(reinterpret_cast<const char*>(&set), sizeof(bool));

    file.close();
    return true;
}