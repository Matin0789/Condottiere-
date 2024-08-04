#ifndef GAME_H
#define GAME_H

#include <QObject>

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
    bool save(std::string) const; 	// (save file path)
    bool load(std::string);	// (save file path)
public slots:
    /*
    std::string getCommand(const Player&, const BattleMarker&, const Card*);

    void getPlayerStates(const Player&) const;
    void getPlayerCards(const Player&) const;
    void getPlayerPlayedCards(const Player&) const;
    std::string get_card_name();*/

    void get_player(std::string, size_t, Color);

    //
    /*void declare_warWinner(const Player&) const;
    void declare_warWinner() const;

    void declare_gameWinner(const Player&) const;*/
signals :
    State* set_battleground(const Player&,GameBoard&);
    State* set_favorground(const Player&,GameBoard&);
    void showPlayerCards(const Player&);
private:
	//private methods
	size_t warـanalyst();
	bool find_game_winner(const Player&);

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
