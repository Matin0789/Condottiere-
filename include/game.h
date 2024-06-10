#ifndef GAME_H
#define GAME_H

#include <vector>
#include <array>
#include <string>

#include "player.h"
#include "gameboard.h"
#include "userinterface.h"

#include "card.h"
#include "bishop.h"
#include "drummer.h"
#include "heroine.h"
#include "scarecrow.h"
#include "spy.h"
#include "winter.h"
#include "spring.h"
#include "turncoat.h"
#include "yellowcard.h"

#include "marker.h"
#include "playermarker.h"
#include "favormarker.h"
#include "battlemarker.h"

class Game {
	friend Bishop;
	friend Drummer;
	friend Heroine;
	friend Scarecrow;
	friend Spy;
	friend Turncoat;
	friend Winter;
	friend Spring;
public:
    Game(UserInterface&);
    void play();
    void war();
private:
    UserInterface &ui;
	GameBoard gameBoard;
	BattleMarker battleMarker;
	FavorMarker favorMarker;
	std::vector<Player> players;
	const std::array<YellowCard, 10> one_point_yellow_card = {YellowCard(1),YellowCard(1),YellowCard(1),YellowCard(1),YellowCard(1),YellowCard(1),YellowCard(1),YellowCard(1),YellowCard(1),YellowCard(1)};
	const std::array<YellowCard, 8> two_point_yellow_card = {YellowCard(2),YellowCard(2),YellowCard(2),YellowCard(2),YellowCard(2),YellowCard(2),YellowCard(2),YellowCard(2)};
	const std::array<YellowCard, 8> three_point_yellow_card = {YellowCard(3),YellowCard(3),YellowCard(3),YellowCard(3),YellowCard(3),YellowCard(3),YellowCard(3),YellowCard(3)};
	const std::array<YellowCard, 8> four_point_yellow_card = {YellowCard(4),YellowCard(4),YellowCard(4),YellowCard(4),YellowCard(4),YellowCard(4),YellowCard(4),YellowCard(4)};
	const std::array<YellowCard, 8> five_point_yellow_card = {YellowCard(5),YellowCard(5),YellowCard(5),YellowCard(5),YellowCard(5),YellowCard(5),YellowCard(5),YellowCard(5)};
	const std::array<YellowCard, 8> six_point_yellow_card = {YellowCard(6),YellowCard(6),YellowCard(6),YellowCard(6),YellowCard(6),YellowCard(6),YellowCard(6),YellowCard(6)};
	const std::array<YellowCard, 8> ten_point_yellow_card = {YellowCard(10),YellowCard(10),YellowCard(10),YellowCard(10),YellowCard(10),YellowCard(10),YellowCard(10),YellowCard(10)};
	std::array<Turncoat, 3> turncoat;
    std::array<Heroine, 3> heroine;
    std::array<Spring, 3> spring;
    std::array<Winter, 3> winter;
    std::array<Scarecrow, 16> scarecrow;
    std::array<Heroine, 6> drummer;
	//std::array<Spy, 12> spy;
	//const std::array<Heroine, 6> bishop;
    std::vector<const Card*> cards;
	Card* season;
private:
	void shuffle();
	void distributeCards(); 
};

#endif // GAME_H