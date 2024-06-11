#include "gameboard.h"

#include <vector>
#include <string>
#include <stdexcept>

bool GameBoard::checkAdjacency(const State* state1,const State* state2,const State* state3) {
    std::string name1{state1->getName()},name2{state2->getName()},name3{state3->getName()};
    return (adjacency[name1][name2] && adjacency[name1][name3] && adjacency[name2][name3]);
}

State* GameBoard::getState(std::string name){ 
    if (states.find(name) != states.end()){
        return &states.at(name); 
    }
    else {
        throw std::invalid_argument("State not found");
    }
}

std::vector<std::string> GameBoard::get_active_states_name() const{
    std::vector<std::string> active_states_name;
    for (auto &&state : states){
        if (state.second.is_set() == false)
            active_states_name.push_back(state.first);
    }
    return active_states_name;
}
