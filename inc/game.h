#ifndef GAME_H
#define GAME_H

#include <vector>
#include <array>
#include <string>
#include <utility>

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
	~Game();
	static std::string getHelp();
    void play();
	static bool check_number_of_player(std::string);
	void set_battleground(const Player&);
	void set_favorground(const Player&);
	bool save(std::string) const; 	// (save file path)
	bool load(std::string);	// (save file path)
private:
	//private methods
	size_t warـanalyst();
	bool find_game_winner(const Player&);
	void getPlayers();
	void shuffle();
	void distributeCards();
	std::pair<size_t, std::pair<size_t, size_t>> war(int); // // first currentplayerID, second.first favorSetterID, second.second battleSetterID
	//private atributes
	static std::string help;
    //data
	BattleMarker battleMarker;
	FavorMarker favorMarker;
    std::vector<const Card*> cards;
    const Card* season;
	GameBoard gameBoard;
	std::vector<Player> players;
    UserInterface *ui;
	//
};

#endif // GAME_H
