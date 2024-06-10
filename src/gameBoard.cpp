#include "gameboard.h"

#include <vector>
#include <string>

bool GameBoard::checkAdjacency(const State* state1,const State* state2,const State* state3) {
    std::string name1{state1->getName()},name2{state2->getName()},name3{state3->getName()};
    return (adjacency[name1][name2] && adjacency[name1][name3] && adjacency[name2][name3]);
}

const std::unordered_map<std::string, State>& GameBoard::getStates() const { return state; }

