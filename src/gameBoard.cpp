#include "gameboard.h"

#include <vector>
#include <string>
#include <stdexcept>

bool GameBoard::checkAdjacency(const std::string state1Name,const std::string state2Name, const std::string state3Name) {
    return (adjacency[state1Name][state2Name] && adjacency[state1Name][state3Name] && adjacency[state2Name][state3Name]);
}

State* GameBoard::getState(std::string name){     // send state name 
    if (states.find(name) != states.end()){  // find it
        return &states.at(name); 
    }
    else {
        throw std::invalid_argument("State not found");   // exception handling
    }
}

std::vector<std::string> GameBoard::get_active_states_name() const{   // Send the name of the disputed province
    std::vector<std::string> active_states_name;
    for (auto &&state : states){
        if (state.second.is_set() == false)
            active_states_name.push_back(state.first);
    }
    return active_states_name;   //find and transmit
}
