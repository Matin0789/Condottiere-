#include "game.h"
#include "userinterface.h"

#include <iostream>

int main()
{
    try
    {
        UserInterface ui;
        Game game(ui);
        game.play();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
