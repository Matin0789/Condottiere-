#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <string>
#include <vector>
#include <cstddef>

#include "battlemarker.h"
#include "player.h"
#include "enumcolor.h"

class GameBoard;

class UserInterface
{
private:
public:
	void clearTerminal() const;
	void pause() const;
	void spliter() const;
	void showPlayerPlayedCards(const Player&) const;
	std::string getCommand(const Player&, const BattleMarker&, const Card*);
	State* get_battleground(const Player&,GameBoard&);
	void showPlayerStates(const Player&) const;	
	void showPlayerCards(const Player&) const;
	std::string get_card_name();
	//
	int get_players_number();
	std::string get_player_name(size_t);
	unsigned int get_player_old(size_t);
	Color get_player_color(size_t);
};

#endif // USERINTERFACE