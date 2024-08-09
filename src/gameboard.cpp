#include "gameboard.h"
#include "state.h"

#include <iomanip>
#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <utility>

GameBoard::GameBoard(std::string filePath) {
    std::ifstream file(filePath);
    if (!file) {
        throw std::runtime_error("board file cannot be open");
    }

    std::string tmp_state_name;
    while(file >> quoted(tmp_state_name)){ // add state to states and adjacent of them
        states.insert(std::pair<std::string, State>(tmp_state_name, State(tmp_state_name)));
        std::string tmp_adjacency_line; //A line in the file where the adjacent is written
        file.ignore(256,'\n');
        getline(file, tmp_adjacency_line);// read adjacency line in file
        file.ignore(256,'\n');
        std::stringstream tmp(tmp_adjacency_line); // for keep the line of adjacency
        std::string tmp_adjacency_state_name;// Name of the adjacent state
        while(tmp >> quoted(tmp_adjacency_state_name)) { // add adjacent of the state to adjacency
            adjacency[tmp_state_name].push_back(tmp_adjacency_state_name);
        }
    }
}

bool GameBoard::checkAdjacency(const std::string state1Name,const std::string state2Name, const std::string state3Name) {
    // check arguments
    if (states.find(state1Name) == states.end()){
        throw std::invalid_argument("State1 not found"); 
    }
    if (states.find(state2Name) == states.end()){
        throw std::invalid_argument("State2 not found"); 
    }
    if (states.find(state3Name) == states.end()){
        throw std::invalid_argument("State3 not found"); 
    }
    //

    // check adjacency
    if(std::find(adjacency[state1Name].begin(), adjacency[state1Name].end(), state2Name) == adjacency[state1Name].end())
        return false;
    if(std::find(adjacency[state2Name].begin(), adjacency[state2Name].end(), state3Name) == adjacency[state2Name].end())
        return false;
    if(std::find(adjacency[state3Name].begin(), adjacency[state3Name].end(), state1Name) == adjacency[state3Name].end())
        return false;
    
    return true;
    //
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

bool GameBoard::save(std::string filePath) const{
    std::ofstream file(filePath, std::ios::app);
    if (!file) {
        throw std::runtime_error("save file cannot be open in gameboard");
    }

    file << "GameBoard" << std::endl;
    //save unordered_map states
    // for (auto &&state : states)
    // {
    //     size_t nameSize = sizeof(state.first);
    //     file.write(reinterpret_cast<const char*>(&nameSize), sizeof(size_t));
    //     file.write(reinterpret_cast<const char*>(&state.first), nameSize);
    //     bool set = state.second.is_set();
    //     file.write(reinterpret_cast<const char*>(&set), sizeof(bool));
    // }

    for (auto &&state : states) {
        file << '\"' << state.first << '\"' << ' ';
        bool set = state.second.is_set();
        file << set << std::endl;
    }
    file.close();
    return true;
}

bool GameBoard::load(std::string filePath)
{
    std::ifstream file(filePath);
    if (!file) {
        throw std::runtime_error("save file cannot be open in gameboard");
    }

    std::string finder;
    while (getline(file, finder)) {
        if (finder == "GameBoard") {
            break;
        }
    }

    //load unordered_map states
    for (size_t i = 0;i < states.size();i++)
    {
        // size_t nameSize;
        // file.read(reinterpret_cast<char*>(&nameSize), sizeof(size_t));
        std::string name;
        // file.read(reinterpret_cast<char*>(&name), nameSize);
        file >> quoted(name);
        bool isSet;
        // file.read(reinterpret_cast<char*>(&isSet), sizeof(bool));
        file >> isSet;
        (*states.find(name)).second.set(isSet);
    }

    file.close();

    return true;

}
