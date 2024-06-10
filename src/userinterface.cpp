#include <stdlib.h>
#include <iostream>

#include <string>
#include <iostream>

#include "userinterface.h"
#include "game.h"

std::string UserInterface::getCommand(const Player& player,const BattleMarker& marker) {
    std::cout << marker.getState().getName() << std::endl;
    for (auto &&card : player.getCards())
        cout << card.getType()
    
    std::cout << "Player" << player.getID() << "@ : ";
    
}