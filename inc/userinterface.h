#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <string>
#include <vector>
#include <cstddef>

#include "battlemarker.h"
#include "player.h"
#include "enumcolor.h"

class GameBoard;

class UserInterface
{
private:
public:
  void clearTerminal() const;
  void pause();
  void showPlayerPlayedCards(const std::vector<Player> &) const;
  std::string getCommand(const Player&, const BattleMarker &);
  State* get_battleground(const Player&,GameBoard&);
  void showPlayerStates(const std::vector<Player> &) const;

  //
  int get_players_number();
  std::string get_player_name(size_t);
  unsigned int get_player_old(size_t);
  Color get_player_color(size_t);
  
};

#endif // USERINTERFACE