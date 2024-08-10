#include "marker.h"

#include <fstream>
#include <iomanip>

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

bool Marker::save(std::string filePath, size_t ID) const {
    std::ofstream file(filePath, std::ios::app);
    if (!file) {
        throw std::runtime_error("file " + filePath + "cannot be open in marker");
    }

    file << "marker" << std::to_string(ID) << std::endl;
    // std::string stateName = state->getName();
    // size_t size = stateName.capacity();
    // file.write(reinterpret_cast<const char*>(&size), sizeof(size_t));
    // file.write(reinterpret_cast<const char*>(&stateName), size);
    std::string stateName = state->getName();
    file << '\"' << stateName << '\"' << std::endl;



    file.close();
    return true;
}

bool Marker::load(std::string filePath, GameBoard& gameBoard, size_t ID, size_t playerID) {
    std::ifstream file(filePath);
    if (!file) {
        throw std::runtime_error("file " + filePath + "cannot be open in marker");
    }
    
    std::string finder;

    while(getline(file, finder)) {
        if (finder == ("player" + std::to_string(playerID))) {
            break;
        }
    }

    while(getline(file, finder)) {
        if (finder == ("marker" + std::to_string(ID))){
            break;
        }
    }

    std::string stateName;
    // size_t size;
    // file.read(reinterpret_cast<char*>(&size), sizeof(size_t));
    // file.read(reinterpret_cast<char*>(&stateName), size);
    file >> quoted(stateName);
    state = gameBoard.getState(stateName);
    state->set(true);
    this->set = true;

    file.close();
    return true;

}
