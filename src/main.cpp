#include <iostream>

#include "game.h"
#include "userinterface.h"

using namespace std;

int main(){
	UserInterface interface;
	Game game(interface);
	game.play();
	return 0;
}