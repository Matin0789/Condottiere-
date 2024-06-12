#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <unordered_map>
#include <map>
#include <vector>

#include "state.h"

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

class GameBoard
{
public:
	bool checkAdjacency(const std::string, const std::string, const std::string);
	State* getState(std::string);
	std::vector<std::string> get_active_states_name() const;
private:
	std::unordered_map<std::string, State> states = {
		{BEL, State(BEL)},
		{CAL, State(CAL)},
		{ENN, State(ENN)},
		{ATE, State(ATE)},
		{PLA, State(PLA)},
		{BOR, State(BOR)},
		{DIM, State(DIM)},
		{MOR, State(MOR)},
		{OLI, State(OLI)},
		{ROL, State(ROL)},
		{TAL, State(TAL)},
		{ARM, State(ARM)},
		{LIA, State(LIA)},
		{ELI, State(ELI)}
	};
	std::map<std::string,std::map<std::string,bool>> adjacency = {
		{BEL,	{{CAL, 1}, {ENN, 0}, {ATE, 0}, {PLA, 1}, {BOR, 1}, {DIM, 0}, {MOR, 0}, {OLI, 0}, {ROL, 0}, {TAL, 0}, {ARM, 0}, {LIA, 0}, {ELI, 0}}},
		{CAL,	{{ENN, 1}, {ATE, 1}, {PLA, 1}, {BOR, 1}, {DIM, 0}, {MOR, 0}, {OLI, 0}, {ROL, 0}, {TAL, 0}, {ARM, 0}, {LIA, 0}, {ELI, 0}, {BEL, 1}}},
		{ENN,	{{ATE, 1}, {PLA, 0}, {BOR, 1}, {DIM, 1}, {MOR, 0}, {OLI, 0}, {ROL, 0}, {TAL, 0}, {ARM, 0}, {LIA, 0}, {ELI, 0}, {BEL, 1}, {CAL, 0}}},
		{ATE,	{{PLA, 0}, {BOR, 0}, {DIM, 1}, {MOR, 0}, {OLI, 0}, {ROL, 0}, {TAL, 0}, {ARM, 0}, {LIA, 0}, {ELI, 0}, {BEL, 0}, {CAL, 1}, {ENN, 1}}},
		{PLA,	{{BOR, 1}, {DIM, 0}, {MOR, 1}, {OLI, 0}, {ROL, 1}, {TAL, 0}, {ARM, 0}, {LIA, 0}, {ELI, 0}, {BEL, 1}, {CAL, 1}, {ENN, 0}, {ATE, 0}}},
		{BOR,	{{DIM, 1}, {MOR, 1}, {OLI, 1}, {ROL, 0}, {TAL, 0}, {ARM, 0}, {LIA, 0}, {ELI, 0}, {BEL, 1}, {CAL, 1}, {ENN, 1}, {ATE, 0}, {PLA, 1}}},
		{DIM,	{{MOR, 1}, {OLI, 1}, {ROL, 0}, {TAL, 0}, {ARM, 0}, {LIA, 0}, {ELI, 0}, {BEL, 0}, {CAL, 0}, {ENN, 1}, {ATE, 1}, {PLA, 0}, {BOR, 1}}},
		{MOR,	{{OLI, 1}, {ROL, 1}, {TAL, 1}, {ARM, 1}, {LIA, 0}, {ELI, 0}, {BEL, 0}, {CAL, 0}, {ENN, 0}, {ATE, 0}, {PLA, 1}, {BOR, 1}, {DIM, 0}}},
		{OLI,	{{ROL, 0}, {TAL, 0}, {ARM, 1}, {LIA, 1}, {ELI, 0}, {BEL, 0}, {CAL, 0}, {ENN, 0}, {ATE, 0}, {PLA, 0}, {BOR, 1}, {DIM, 1}, {MOR, 1}}},
		{ROL,	{{TAL, 1}, {ARM, 0}, {LIA, 0}, {ELI, 1}, {BEL, 0}, {CAL, 0}, {ENN, 0}, {ATE, 0}, {PLA, 1}, {BOR, 0}, {DIM, 0}, {MOR, 1}, {OLI, 0}}},
		{TAL,	{{ARM, 1}, {LIA, 0}, {ELI, 1}, {BEL, 0}, {CAL, 0}, {ENN, 0}, {ATE, 0}, {PLA, 0}, {BOR, 0}, {DIM, 0}, {MOR, 1}, {OLI, 0}, {ROL, 1}}},
		{ARM,	{{LIA, 1}, {ELI, 0}, {BEL, 0}, {CAL, 0}, {ENN, 0}, {ATE, 0}, {PLA, 0}, {BOR, 0}, {DIM, 0}, {MOR, 1}, {OLI, 1}, {ROL, 0}, {TAL, 1}}},
		{LIA,	{{ELI, 0}, {BEL, 0}, {CAL, 0}, {ENN, 0}, {ATE, 0}, {PLA, 0}, {BOR, 0}, {DIM, 0}, {MOR, 0}, {OLI, 1}, {ROL, 0}, {TAL, 0}, {ARM, 1}}},
		{ELI,	{{BEL, 0}, {CAL, 0}, {ENN, 0}, {ATE, 0}, {PLA, 0}, {BOR, 0}, {DIM, 0}, {MOR, 0}, {OLI, 0}, {ROL, 1}, {TAL, 1}, {ARM, 0}, {LIA, 0}}},
	};
};

#endif // GAMEBOARD_H