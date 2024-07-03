#include "game.h"
#include "userinterface.h"

int main()
{
    UserInterface ui;
    Game game(ui);
    game.play();
    return 0;
}
