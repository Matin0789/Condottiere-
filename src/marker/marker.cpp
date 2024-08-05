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

Color Marker::getColor() const
{
    return color;
}

bool Marker::save(std::string filePath) const {
    std::ofstream file(filePath, std::ios::binary | std::ios::app);
    if (!file) {
        throw std::runtime_error("file " + filePath + "cannot be open in marker");
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

bool Marker::load(std::string filePath, GameBoard& gameBoard) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        throw std::runtime_error("file " + filePath + "cannot be open in marker");
    }
    
    std::string stateName;
    size_t size;
    file.read(reinterpret_cast<char*>(&size), sizeof(size_t));
    file.read(reinterpret_cast<char*>(&stateName), size);
    state = gameBoard.getState(stateName);

    file.read(reinterpret_cast<char*>(&color), sizeof(Color));
    file.read(reinterpret_cast<char*>(&set), sizeof(bool));

    file.close();
    return true;

}
