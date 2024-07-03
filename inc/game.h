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
	GameBoard gameBoard;
	BattleMarker battleMarker;
	FavorMarker favorMarker;
	std::vector<Player> players;
    std::vector<const Card*> cards;
    const Card* season;
	const std::array<YellowCard, 10> one_point_yellow_card = {YellowCard(1),YellowCard(1),YellowCard(1),YellowCard(1),YellowCard(1),YellowCard(1),YellowCard(1),YellowCard(1),YellowCard(1),YellowCard(1)};
	const std::array<YellowCard, 8> two_point_yellow_card = {YellowCard(2),YellowCard(2),YellowCard(2),YellowCard(2),YellowCard(2),YellowCard(2),YellowCard(2),YellowCard(2)};
	const std::array<YellowCard, 8> three_point_yellow_card = {YellowCard(3),YellowCard(3),YellowCard(3),YellowCard(3),YellowCard(3),YellowCard(3),YellowCard(3),YellowCard(3)};
	const std::array<YellowCard, 8> four_point_yellow_card = {YellowCard(4),YellowCard(4),YellowCard(4),YellowCard(4),YellowCard(4),YellowCard(4),YellowCard(4),YellowCard(4)};
	const std::array<YellowCard, 8> five_point_yellow_card = {YellowCard(5),YellowCard(5),YellowCard(5),YellowCard(5),YellowCard(5),YellowCard(5),YellowCard(5),YellowCard(5)};
	const std::array<YellowCard, 8> six_point_yellow_card = {YellowCard(6),YellowCard(6),YellowCard(6),YellowCard(6),YellowCard(6),YellowCard(6),YellowCard(6),YellowCard(6)};
	const std::array<YellowCard, 8> ten_point_yellow_card = {YellowCard(10),YellowCard(10),YellowCard(10),YellowCard(10),YellowCard(10),YellowCard(10),YellowCard(10),YellowCard(10)};
	const std::array<Turncoat, 3> turncoat;
    const std::array<Heroine, 3> heroine;
    const std::array<Spring, 3> spring;
    const std::array<Winter, 3> winter;
    const std::array<Scarecrow, 16> scarecrow;
    const std::array<Heroine, 6> drummer;
	//std::array<Spy, 12> spy;
	//std::array<Bishop, 6> bishop;
};

#endif // GAME_H
