#include "game.h"
#include "userinterface.h"

using namespace std;

int main(){
	UserInterface interface;  // set object
	Game game(interface);  //relationship
	game.play();  //start game 
	return 0;
}
