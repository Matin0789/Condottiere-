#ifndef GAME_H
#define GAME_H

#include <vector>
#include <array>
#include <string>

#include "player.h"
#include "gameboard.h"
#include "userinterface.h"

#include "card.h"
#include "yellowcard.h"
#include "bishop.h"
#include "drummer.h"
#include "heroine.h"
#include "scarecrow.h"
#include "spy.h"
#include "winter.h"
#include "spring.h"
#include "turncoat.h"

#include "marker.h"
#include "playermarker.h"
#include "favormarker.h"
#include "battlemarker.h"

class Game {
public:
	size_t compareAge();
    Game(UserInterface&);
	static std::string getHelp();
    void play();
	static bool check_number_of_player(int);
	void set_battleground(const Player&);
	bool save(); // (save file path)
	bool load();	// (save file path)
private:
	//private methods
	size_t find_war_winner();
	bool find_game_winner(const Player&);
	void getPlayers();
	void shuffle();
	void distributeCards();
	int war(int);
	//private atributes
	static std::string help;
    UserInterface &ui;
    //
	GameBoard gameBoard;
	BattleMarker battleMarker;
	FavorMarker favorMarker;
	std::vector<Player> players;
    std::vector<const Card*> cards;
    const Card* season;
    // Cards
	const std::vector<YellowCard> one_point_yellow_card;
	const std::vector<YellowCard> two_point_yellow_card;
	const std::vector<YellowCard> three_point_yellow_card;
	const std::vector<YellowCard> four_point_yellow_card;
	const std::vector<YellowCard> five_point_yellow_card;
	const std::vector<YellowCard> six_point_yellow_card;
	const std::vector<YellowCard> ten_point_yellow_card;
	const std::vector<Bishop> bishop;
	const std::vector<Turncoat> turncoat;
    const std::vector<Heroine> heroine;
    const std::vector<Spring> spring;
    const std::vector<Winter> winter;
    const std::vector<Scarecrow> scarecrow;
    const std::vector<Drummer> drummer;
	const std::vector<Spy> spy;
};

#endif // GAME_H
