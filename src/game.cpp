#include <time.h>
#include <algorithm>
#include <stdexcept>
#include <cstddef>
#include <cmath>
#include <utility>
#include <fstream> // for files
#include <sstream> // for read file as stream

 // The file path of the game guide
#define Game_HELP_FILE      "../data/help/GameHelp.txt"
#define BISHOP_HELP_FILE    "../../data/help/BishopHelp.txt"
#define TURNCOAT_HELP_FILE  "../../data/help/TurncoatHelp.txt"
#define HEROINE_HELP_FILE   "../../data/help/HeroineHelp.txt"
#define SPRING_HELP_FILE    "../../data/help/SpringHelp.txt"
#define WINTER_HELP_FILE    "../../data/help/WinterHelp.txt"
#define SCARECROW_HELP_FILE "../../data/help/ScarecrowHelp.txt"
#define DRUMMER_HELP_FILE   "../../data/help/DrummerHelp.txt"
#define SPY_HELP_FILE       "../../data/help/SpyHelp.txt"

#define BOARD_FILE          "../data/board/"

#include "game.h"

std::string Game::help; // set help
// constructor
Game::Game(UserInterface &inputUI) : 
    cards(121),
    ui(inputUI),
    season(nullptr),
    one_point_yellow_card(10, YellowCard(1)),  
    two_point_yellow_card(8,YellowCard(2)),
    three_point_yellow_card(8,YellowCard(3)),
    four_point_yellow_card(8,YellowCard(4)),
    five_point_yellow_card(8,YellowCard(5)),
    six_point_yellow_card(8,YellowCard(6)),
    ten_point_yellow_card(8,YellowCard(10)),
    bishop(6,Bishop(BISHOP_HELP_FILE)),
    turncoat(3,Turncoat(TURNCOAT_HELP_FILE)),
    heroine(3, Heroine(HEROINE_HELP_FILE)),
    spring(3, Spring(SPRING_HELP_FILE)),
    winter(3, Winter(WINTER_HELP_FILE)),
    scarecrow(16, Scarecrow(SCARECROW_HELP_FILE)),
    drummer(6, Drummer(DRUMMER_HELP_FILE)),
    spy(12, Spy(SPY_HELP_FILE))
    gameBoard()
{
    // Read
    std::ifstream helpFile(Game_HELP_FILE);
    if (helpFile.is_open()){
        std::stringstream helpString;
        std::string tmp;
        while(getline(helpFile,tmp)){
            helpString << tmp;
        }
        Game::help = helpString.str();
        helpFile.close();
    }
    else 
        throw std::runtime_error("The game help file cannot be opened");

    srand(time(0));    // for rand function
    for (int i = 0; i < 10; i++)
    {
        cards[i] = &one_point_yellow_card[i];  // an array of yellow cards
    }
    for (int i = 0; i < 8; i++)    // point of yellow cards
    {
        cards[i + 10] = &two_point_yellow_card[i];
        cards[i + 18] = &three_point_yellow_card[i];
        cards[i + 26] = &four_point_yellow_card[i];
        cards[i + 34] = &five_point_yellow_card[i];
        cards[i + 42] = &six_point_yellow_card[i];
        cards[i + 50] = &ten_point_yellow_card[i];
    }
    for (int i = 0; i < 3; i++)     // an array of purple cards (heroine , spring , winter)
    {
        cards[i + 58] = &heroine[i];
        cards[i + 61] = &spring[i];
        cards[i + 64] = &winter[i];
    }
    for (int i = 0; i < 16; i++)  // an array of purple cards (scarecrow)
    {
        cards[i + 67] = &scarecrow[i];
    }
    for (int i = 0; i < 6; i++)
    {

        cards[i + 83] = &drummer[i];
        cards[i + 100] = &bishop[i];   // This is for the next phase of the project
    }
    for (int i = 0;i < 12;i++){
        cards[i + 106] = &spy[i];
    }
    for (int i = 0; i < 3; i++) {
        cards[i + 118] = &turncoat[i];
    }
}

std::string Game::getHelp() {    // send help texts for user
    return help;
}

size_t Game::find_war_winner(){    
    std::vector<std::vector<unsigned int>> pointCards(players.size());
    std::vector<std::pair<size_t ,const Card*>> purpleCards;
    std::vector<bool> drummer_set(players.size(),false);

    for (size_t i = 0; i < players.size(); i++)
    {
        for (auto &&card : players[i].getPlayedCards())
        {
            if (card->getType()[0] >= '0' && card->getType()[0] <= '9'){
                
                card->applyFeature(pointCards, i);
            }
            else {

                purpleCards.push_back(std::make_pair(i, card));
            }
            if (!players[i].getPlayedCards().empty())
                cards.push_back(players[i].drawn_playedCard(card->getType()));
        }
    }

    if (season) {   //check
        purpleCards.push_back(std::make_pair(players.size(), season));
        cards.push_back(season);
        season = nullptr;
    }
    std::sort(purpleCards.begin(), purpleCards.end(),    // algorithms function
        [](const std::pair<size_t ,const Card*>& pair1 , std::pair<size_t ,const Card*>& pair2) {
            return pair1.second->getPriority() < pair2.second->getPriority();
        });
    for (auto &&purpleCard : purpleCards)
    {
        if (purpleCard.second->getType() == "drummer") {
            if (drummer_set[purpleCard.first] == false) {
                purpleCard.second->applyFeature(pointCards, purpleCard.first);
            }
        }
        else{
            purpleCard.second->applyFeature(pointCards, purpleCard.first);
        }

        if (purpleCard.second->getType() == "drummer") {
            drummer_set[purpleCard.first] = true;
        }
    }

    size_t winnerID = players.size();
    unsigned int highestScore = 0;
    std::vector<std::pair<size_t, unsigned int>> scores;
    for (size_t i = 0; i < players.size(); i++)
    {
        unsigned int maxScore{0};
        for (auto &&cardPoint : pointCards[i])
        {
            maxScore += cardPoint;
        }
        scores.push_back(std::make_pair(i, maxScore));
    }

    std::sort(scores.begin(), scores.end(),
        [](const std::pair<size_t, unsigned int>& pair1, const std::pair<size_t, unsigned int>& pair2){
            return pair1.second > pair2.second;
        });
    
    if (scores[0].second != scores[1].second) {
        winnerID = scores[0].first;
    }

    for (auto &&player : players)
    {
        std::vector<const Card*> tmp(player.burnPlayedCards());
        if (!tmp.empty());
            cards.insert(cards.end(), tmp.begin(), tmp.end());
    }

    return winnerID;
    
}

bool Game::find_game_winner(const Player& player){
    size_t number_of_player_states = player.getStateNumber();
    if (number_of_player_states >= 5){
        return true;
    }
    else if (number_of_player_states >= 3){
        for (size_t i = 0; i < number_of_player_states; i++)
        {
            for (size_t j = i; j < number_of_player_states; j++)
            {
                for (size_t k = j; k < number_of_player_states; k++)
                {
                    std::vector<std::string> statesName = player.get_states_name();
                    if (gameBoard.checkAdjacency(statesName[i], statesName[j], statesName[k]))
                        return true;
                }
            }
            
        }
        
    }
    else
        return false;
    return false;
}

void Game::getPlayers() {
    int n = ui.get_players_number();
    for (size_t i = 0; i < n; i++) {
        std::string name = ui.get_player_name(i + 1);
        unsigned int age = ui.get_player_old(i + 1);
        Color color = ui.get_player_color(i + 1);
        players.push_back(Player(name, i, age, color));
    }
}

void Game::distributeCards() {
    shuffle();
    for (auto &&player : players) {
        std::vector<const Card*> playerCards(cards.begin(), cards.begin() + (10 + player.getStateNumber()));
        cards.erase(cards.begin(), cards.begin() + (10 + player.getStateNumber()));
        player.setCards(playerCards);
        ui.showPlayerCards(player);
    }
}

void Game::shuffle()  //This function is for shuffling cards
{
    std::random_shuffle(cards.begin(), cards.end()); //This is a default function in C++ that is used for shuffling
}

void Game::play()
{
    getPlayers();
    distributeCards();
    size_t currentPlayerID = 1;
    currentPlayerID = compareAge();
    while (true){
        set_battleground(players[currentPlayerID]);
        currentPlayerID = war(currentPlayerID);
        bool gameEnd = find_game_winner(players[currentPlayerID]);
        if (gameEnd){
            ui.declare_gameWinner(players[currentPlayerID]);
            break;
        }
        size_t counter = 0;
        for (auto &&player : players)
        {
            if (!player.getCards().empty()){
                counter++;
            }
        }
        if (counter <= 1){
            for (auto &&player : players)
            {
                std::vector<const Card*> tmp(player.burnCards());
                if (!tmp.empty()){
                    cards.insert(cards.end(), tmp.begin(), tmp.end());
                }
            }
            distributeCards();
        }
    }
}

bool Game::check_number_of_player(int n) {
    if (n >= 3 && n <= 6){
        return true;
    }
    else{
        throw std::out_of_range("Invalid number of players! please enter a number between 3 , 6");
        return false;
    }
}

void Game::set_battleground(const Player& currentPlayer) {
    State* battlegroud = ui.get_battleground(currentPlayer,gameBoard);
    battleMarker.setState(battlegroud);
}

int Game::war(int currentPlayerID) {     //This function starts working when the conditions are ready and the province of the battle location is selected
    std::vector<Player*> activePlayers;
    for (auto &&player : players) {
        activePlayers.push_back(&player);
    }
    size_t i = currentPlayerID;
    for (;!activePlayers.empty(); i++) {
        for (auto &&player : players)
        {
            ui.showPlayerPlayedCards(player);
        }
        ui.spliter();
        for (auto &&player : players)
        {
            ui.showPlayerStates(player);
        }
        ui.spliter();
        std::string command = ui.getCommand(*activePlayers[i],battleMarker, season);
        ui.clearTerminal();
        if (command == "pass") {       // if player select passing 
            if (activePlayers.size() == 1) currentPlayerID = activePlayers[i]->getID();
            activePlayers.erase(activePlayers.begin() + i);
            i--;
        }
        else {
            const Card* drawnCard = activePlayers[i]->drawn_card(command);
            if (drawnCard->getType() == "Turncoat"){
                cards.push_back(drawnCard);
                break;
            }
            else if (drawnCard->getType() == "Scarecrow"){
                if (!activePlayers[i]->getPlayedCards().empty()) {
                    bool flag = false;
                    do {
                        ui.showPlayerPlayedCards(*activePlayers[i]);
                        std::string choose = ui.get_card_name();
                        if (choose[0] >= '0' and choose[0] <= '9'){
                            for (const auto &card : activePlayers[i]->getPlayedCards()) {
                                if (card->getType() == choose) {
                                    const Card* drawnPlayedCard = activePlayers[i]->drawn_playedCard(choose);
                                    activePlayers[i]->push_to_playedCards(drawnCard);
                                    activePlayers[i]->push_to_cards(drawnPlayedCard);
                                    flag = true;
                                }
                            }
                        }
                        else {
                            ui << "You can only choose from yellow cards, ";
                            flag = false;
                        }
                        if (!flag) {
                            ui << "Please try again";
                            ui.pause();
                        }
                    } while (!flag);
                }
                else{
                    activePlayers[i]->push_to_playedCards(drawnCard);
                }
            }
            else if (drawnCard->is_season() == true){
                cards.push_back(season);
                season = drawnCard;
            }
            else{
                activePlayers[i]->push_to_playedCards(drawnCard);
            }
        }
        if (i >= activePlayers.size() - 1) i = -1;
    }

    size_t winnerID = find_war_winner();

    if (winnerID < players.size()) {
        currentPlayerID = winnerID;
        players[currentPlayerID].setState(&battleMarker.getState());
        ui.declare_warWinner(players[currentPlayerID]);
    }
    else {
        ui.declare_warWinner();
        battleMarker.getState().set(false);
    }
    return currentPlayerID;
}

size_t Game::compareAge()   // search in players ages
{
    if (players.empty())
    {
        throw std::runtime_error("No players in the game");
    }

    auto youngestPlayer = *std::min_element(players.begin(), players.end(), 
        [](const Player& p1, const Player& p2) {
            return p1.getAge() < p2.getAge();
        });

    return youngestPlayer.getID();   // send id of current player
}