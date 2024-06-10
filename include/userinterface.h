#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <string>
#include <vector>

#include "battlemarker.h"

class Player;

class UserInterface {
 private:

 public:
  void showPlayerCards(const std::vector<Player>&);
  std::string getCommand(const Player&,const BattleMarker&);
  void clearTerminal();
};

#endif // USERINTERFACE