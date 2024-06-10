#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <string>
#include <vector>

#include "battlemarker.h"
#include "player.h"

class UserInterface {
 private:

 public:
  void showPlayerCards(const std::vector<Player>&) const;
  std::string getCommand(const Player&,const BattleMarker&);
  void clearTerminal();
  void pause();
};

#endif // USERINTERFACE