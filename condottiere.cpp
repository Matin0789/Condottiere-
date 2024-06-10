#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <string>
#include <unordered_map>
#include <algorithm>


#define BEL "BELLA"
#define CAL "CALINE"
#define ENN "ENNA"
#define ATE "ATELA"
#define PLA "PLADACI"
#define BOR "BORGE"
#define DIM "DIMASE"
#define MOR "MORINA"
#define OLI "OLIVADI"
#define ROL "ROLLO"
#define TAL "TALIMONE"
#define ARM "ARMENTO"
#define LIA "LIA"
#define ELI "ELINIA"

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
	std::vector<Card*> cards;
};
class GameBoard
{
   public:
   bool GameBoard::checkAdjacency(const State* state1,const State* state2,const State* state3) {
    std::string name1{state1->getName()},name2{state2->getName()},name3{state3->getName()};
    return (adjacency[name1][name2] && adjacency[name1][name3] && adjacency[name2][name3]);
}

const std::unordered_map<std::string, State>& GameBoard::getStates() const { return state; }
   private:
	const std::unordered_map<std::string, State> state = {
		{BEL, State(BEL)},
		{CAL, State(CAL)},
		{ENN, State(ENN)},
		{ATE, State(ATE)},
		{PLA, State(PLA)},
		{BOR, State(BOR)},
		{DIM, State(DIM)},
		{MOR, State(MOR)},
		{OLI, State(OLI)},
		{ROL, State(ROL)},
		{TAL, State(TAL)},
		{ARM, State(ARM)},
		{LIA, State(LIA)},
		{ELI, State(ELI)}
	};
	std::map<std::string,std::map<std::string,bool>> adjacency = {
		{BEL,	{{CAL, 1}, {ENN, 0}, {ATE, 0}, {PLA, 1}, {BOR, 1}, {DIM, 0}, {MOR, 0}, {OLI, 0}, {ROL, 0}, {TAL, 0}, {ARM, 0}, {LIA, 0}, {ELI, 0}}},
		{CAL,	{{ENN, 1}, {ATE, 1}, {PLA, 1}, {BOR, 1}, {DIM, 0}, {MOR, 0}, {OLI, 0}, {ROL, 0}, {TAL, 0}, {ARM, 0}, {LIA, 0}, {ELI, 0}, {BEL, 1}}},
		{ENN,	{{ATE, 1}, {PLA, 0}, {BOR, 1}, {DIM, 1}, {MOR, 0}, {OLI, 0}, {ROL, 0}, {TAL, 0}, {ARM, 0}, {LIA, 0}, {ELI, 0}, {BEL, 1}, {CAL, 0}}},
		{ATE,	{{PLA, 0}, {BOR, 0}, {DIM, 1}, {MOR, 0}, {OLI, 0}, {ROL, 0}, {TAL, 0}, {ARM, 0}, {LIA, 0}, {ELI, 0}, {BEL, 0}, {CAL, 1}, {ENN, 1}}},
		{PLA,	{{BOR, 1}, {DIM, 0}, {MOR, 1}, {OLI, 0}, {ROL, 1}, {TAL, 0}, {ARM, 0}, {LIA, 0}, {ELI, 0}, {BEL, 1}, {CAL, 1}, {ENN, 0}, {ATE, 0}}},
		{BOR,	{{DIM, 1}, {MOR, 1}, {OLI, 1}, {ROL, 0}, {TAL, 0}, {ARM, 0}, {LIA, 0}, {ELI, 0}, {BEL, 1}, {CAL, 1}, {ENN, 1}, {ATE, 0}, {PLA, 1}}},
		{DIM,	{{MOR, 1}, {OLI, 1}, {ROL, 0}, {TAL, 0}, {ARM, 0}, {LIA, 0}, {ELI, 0}, {BEL, 0}, {CAL, 0}, {ENN, 1}, {ATE, 1}, {PLA, 0}, {BOR, 1}}},
		{MOR,	{{OLI, 1}, {ROL, 1}, {TAL, 1}, {ARM, 1}, {LIA, 0}, {ELI, 0}, {BEL, 0}, {CAL, 0}, {ENN, 0}, {ATE, 0}, {PLA, 1}, {BOR, 1}, {DIM, 0}}},
		{OLI,	{{ROL, 0}, {TAL, 0}, {ARM, 1}, {LIA, 1}, {ELI, 0}, {BEL, 0}, {CAL, 0}, {ENN, 0}, {ATE, 0}, {PLA, 0}, {BOR, 1}, {DIM, 1}, {MOR, 1}}},
		{ROL,	{{TAL, 1}, {ARM, 0}, {LIA, 0}, {ELI, 1}, {BEL, 0}, {CAL, 0}, {ENN, 0}, {ATE, 0}, {PLA, 1}, {BOR, 0}, {DIM, 0}, {MOR, 1}, {OLI, 0}}},
		{TAL,	{{ARM, 1}, {LIA, 0}, {ELI, 1}, {BEL, 0}, {CAL, 0}, {ENN, 0}, {ATE, 0}, {PLA, 0}, {BOR, 0}, {DIM, 0}, {MOR, 1}, {OLI, 0}, {ROL, 1}}},
		{ARM,	{{LIA, 1}, {ELI, 0}, {BEL, 0}, {CAL, 0}, {ENN, 0}, {ATE, 0}, {PLA, 0}, {BOR, 0}, {DIM, 0}, {MOR, 1}, {OLI, 1}, {ROL, 0}, {TAL, 1}}},
		{LIA,	{{ELI, 0}, {BEL, 0}, {CAL, 0}, {ENN, 0}, {ATE, 0}, {PLA, 0}, {BOR, 0}, {DIM, 0}, {MOR, 0}, {OLI, 1}, {ROL, 0}, {TAL, 0}, {ARM, 1}}},
		{ELI,	{{BEL, 0}, {CAL, 0}, {ENN, 0}, {ATE, 0}, {PLA, 0}, {BOR, 0}, {DIM, 0}, {MOR, 0}, {OLI, 0}, {ROL, 1}, {TAL, 1}, {ARM, 0}, {LIA, 0}}},
	};
};
class Player
{
  public:
  std::string getName() const {
    return name;
}

int getID() const {
    return ID;
};

unsigned int getPoint() const {
    return point;
}

void setPoint(unsigned int point) {
    this->point;
}

const std::vector<Card*>& getPlayedCards() const {
    return playedCards;
}

const std::vector<Card*>& getCards() const {
    return cards;
}
  private:  
   string name;
   int ID;
   unsigned int point;

};
class State
{};
class Card
{
   public:
 Card::Card(unsigned int inputPoint,unsigned int inputPriority) : point(inputPoint), priority(inputPriority) {}

unsigned int getPriority() const {
    return priority;
}

unsigned int getPoint() const {
    return point ;
}

bool is_season() const{
    return false;
}

void setPoint(unsigned int) {
   this->point = point ; 
}
   private:
   unsigned int priority;
   unsigned int point;
};
class PurpleCard
{
   public:
   private: 
};
class Bishop
{
   public:
   Bishop() : PurpleCard(0,"Bishop",1) {

}

std::string Bishop::getHelp() {
    return help;
}
   private: 
   string help;
};
class Drummer
{
  public:
  Drummer::Drummer() : PurpleCard(0,"Drummer",3){
    
}

std::string getHelp() {
    return help;
}
  private:
  string help;
};
class Heroine
{
   public:
   Heroine::Heroine() : PurpleCard(10,"Heroine",5){
}

std::string getHelp() {
    return help;
}
   private: 
   string  help;
};
class Scarecrow
{
   public:
   Scarecrow() : PurpleCard(0,"Scarecrow",0){

}

std::string getHelp() {
    return help;
}
   private: 
   string help;
};
class Spy
{
   public:
    Spy() : PurpleCard(1,"Spy",5){
    help = HELP;
}

std::string getHelp() {
    return help;
}
   private: 
   string help;
};
class Turncoat
{
   public:
   Turncoat() : PurpleCard(0,"Turncoat",0){
    help = HELP;
}

std::string getHelp() {
    return help;
}
   private: 
   string help;
};
class Winter
{
   public:
   Winter() : Season(0,"Winter",2){
  help = HELP ;
}

std::string getHelp(){
    return help;
}
   private:
   string help;
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