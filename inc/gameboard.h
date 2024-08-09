#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <unordered_map>
#include <map>
#include <vector>
#include <list>
#include <utility>

#include "state.h"

//
#define BEL "BELLA"
#define CAL "CALINE"
#define ENN "ENNA"
#define ATE "ATELA"
#define PLA "PLADACI"
#define BOR "BORGE"
#define DIM "DIMASE"
#define MOR "MORINA"
#define OLI "OLIVADI"
#define ROL "ROLLO"
#define TAL "TALIMONE"
#define ARM "ARMENTO"
#define LIA "LIA"
#define ELI "ELINIA"
//

class GameBoard
{
public:
	GameBoard(std::string); // (board file path)
	bool checkAdjacency(const std::string, const std::string, const std::string);
	State* getState(std::string);
	std::vector<std::string> get_active_states_name() const;
    bool save(std::string) const;
    bool load(std::string);
	
private:
	std::unordered_map<std::string, State> states;// states
	std::map<std::string,std::list<std::string>> adjacency; // list of adjacency
};

#endif // GAMEBOARD_H
