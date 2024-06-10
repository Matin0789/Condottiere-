#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <string>

class UserInterface
{};
class Game
{
  public:
Game(UserInterface &inputUI) : cards(92), ui(inputUI), season(nullptr)
{
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        cards[i] = &one_point_yellow_card[i];
    }
    for (int i = 0; i < 8; i++)
    {
        cards[i + 10] = &two_point_yellow_card[i];
        cards[i + 18] = &three_point_yellow_card[i];
        cards[i + 26] = &four_point_yellow_card[i];
        cards[i + 34] = &five_point_yellow_card[i];
        cards[i + 42] = &six_point_yellow_card[i];
        cards[i + 50] = &ten_point_yellow_card[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cards[i + 58] = &turncoat[i];
        cards[i + 61] = &heroine[i];
        cards[i + 64] = &spring[i];
        cards[i + 67] = &winter[i];
    }
    for (int i = 0; i < 16; i++)
    {
        cards[i + 70] = &scarecrow[i];
    }
    for (int i = 0; i < 6; i++)
    {

        cards[i + 86] = &drummer[i];
        // cards[i + 103] = &bishop[i];
    }
    /*for (int i = 0;i < 12;i++){
        cards[i + 109] = &spy[i];
    }*/
}

void distributeCards() {
    shuffle();
}

void shuffle()
{
    std::random_shuffle(cards.begin(), cards.end());
}

void play()
{
    distributeCards();
    while (true)
    {
        war();
    }
}

void Game::war() {
    
}
  private:  

	UserInterface &interface;
	GameBoard gameBoard;
	const std::array<YellowCard, 10> one_point_yellow_card = {YellowCard(1),YellowCard(1),YellowCard(1),YellowCard(1),YellowCard(1),YellowCard(1),YellowCard(1),YellowCard(1),YellowCard(1),YellowCard(1)};
	const std::array<YellowCard, 8> two_point_yellow_card = {YellowCard(2),YellowCard(2),YellowCard(2),YellowCard(2),YellowCard(2),YellowCard(2),YellowCard(2),YellowCard(2)};
	const std::array<YellowCard, 8> three_point_yellow_card = {YellowCard(3),YellowCard(3),YellowCard(3),YellowCard(3),YellowCard(3),YellowCard(3),YellowCard(3),YellowCard(3)};
	const std::array<YellowCard, 8> four_point_yellow_card = {YellowCard(4),YellowCard(4),YellowCard(4),YellowCard(4),YellowCard(4),YellowCard(4),YellowCard(4),YellowCard(4)};
	const std::array<YellowCard, 8> five_point_yellow_card = {YellowCard(5),YellowCard(5),YellowCard(5),YellowCard(5),YellowCard(5),YellowCard(5),YellowCard(5),YellowCard(5)};
	const std::array<YellowCard, 8> six_point_yellow_card = {YellowCard(6),YellowCard(6),YellowCard(6),YellowCard(6),YellowCard(6),YellowCard(6),YellowCard(6),YellowCard(6)};
	const std::array<YellowCard, 8> ten_point_yellow_card = {YellowCard(10),YellowCard(10),YellowCard(10),YellowCard(10),YellowCard(10),YellowCard(10),YellowCard(10),YellowCard(10)};
	const std::array<Turncoat, 3> turncoat;
	const std::array<Heroine, 3> heroine;
	const std::array<Spring, 3> spring;
	const std::array<Winter, 3> winter;
	const std::array<Scarecrow, 16> scarecrow;
	const std::array<Spy, 12> spy;
	const std::array<Heroine, 6> drummer;
	//const std::array<Heroine, 6> bishop;
	std::array<const Card*,104> cards;
};
class GameBoard
{
   public:
   private: 
};
class Player
{
  public:
  private:  
};
class State
{};
class Card
{
   public:
   private:
};
class Bishop
{
   public:
   private: 
};
class Drummer
{
  public:
  private:
};
class Heroine
{
   public:
   private: 
};
class PurpleCard
{
   public:
   private: 
};
class Scarecrow
{
   public:
   private: 
};
class Spy
{
   public:
   private: 
};
class Turncoat
{
   public:
   private: 
};
class Winter
{
   public:
   private:
};
class YellowCard
{
   public:
   private: 
};
class Marker
{
   public:
   private: 
};
class BattleMarker
{
   public:
   private: 
};
class Favormarker
{
   public:
   private: 
};
class PlayerMarker
{
   public:
   private: 
};



using namespace std;

int main(){
	UserInterface interface;
	Game game(interface);
	game.play();
	return 0;
	return 0;
}