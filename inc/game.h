#ifndef GAME_H
#define GAME_H

#include <QObject>

#include <vector>
#include <array>
#include <string>
#include <utility>

#include "player.h"
#include "gameboard.h"

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
#include "ShirinAghl.h"
#include "whiterakhsh.h"
#include "whiteseals.h"

#include "marker.h"
#include "playermarker.h"
#include "favormarker.h"
#include "battlemarker.h"


class Game : public QObject
{
    Q_OBJECT
public:
    size_t compareAge();
    Game(QObject *parent = nullptr);
    ~Game();
    static std::string getHelp();
    void start();
    static bool check_number_of_player(std::string);
public slots:
    void get_player(std::string, size_t, Color);
    void save(std::string); 	// (save file path)
    void load(std::string);// (save file path)
signals :
    State* set_battleground(const std::vector<Player>&,const Player&, GameBoard&, FavorMarker& );
    State* set_favorground(const std::vector<Player>&,const Player&, GameBoard&, FavorMarker& );
    void showPlayerCards(const Player&);
    void startWar(const std::vector<Player>&, BattleMarker&, FavorMarker&);
    void endWar();
    std::string getCommand(const std::vector<Player>&, const Player&, const Card*);
    std::string scarecrow_get_card(const Player&);
    void declare_warWinner(const Player&, BattleMarker&, bool = true);
    void declare_gameWinner(const std::vector<Player>&, const Player&);
    size_t get_players_number();
    void get_player_page_show(std::map<QString, Color>, size_t);
private:
	//private methods
	size_t warـanalyst();
	bool find_game_winner(const Player&);

	void shuffle();
	void distributeCards();
    void war(int); // // first currentplayerID, second.first favorSetterID, second.second battleSetterID


    //private atributes
	static std::string help;
    //data
	BattleMarker battleMarker;
	FavorMarker favorMarker;
    std::vector<const Card*> cards;
    const Card* season;
	GameBoard gameBoard;
	std::vector<Player> players;
    std::map<QString, Color> freeColors;

    bool is_load;
	//

    size_t currentPlayerID;
    size_t favorSetterID;
    size_t battleSetterID;
};

#endif // GAME_H
