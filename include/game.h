#ifndef GAME_H
#define GAME_H

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
#include "yellowCard.h"
#include "season.h"

#include "marker.h"
#include "playermarker.h"
#include "favormarker.h"
#include "battlemarker.h"


class Game {

public:
	void play();
    void war();
private:
	void shuffle();
	void distributeCards(); 
    void burnCards();  
};

#endif // GAME_H