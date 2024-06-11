#include <time.h>
#include <algorithm>
#include <stdexcept>
#include <cstddef>
#include <cmath>

#define HELP ""

//test
#include <iostream>

#include "game.h"

std::string Game::help = HELP;

Game::Game(UserInterface &inputUI) : cards(92), ui(inputUI), season(nullptr)
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

std::string Game::getHelp() {
    return help;
}

void Game::getPlayers() {
    int n = ui.get_players_number();
    for (size_t i = 0; i < n; i++)
    {
        std::string name = ui.get_player_name(i + 1);
        unsigned int age = ui.get_player_old(i + 1);
        Color color = ui.get_player_color(i + 1);
        //players.push_back(Player(name, i + 1, age, color));
    }
}

void Game::distributeCards() {
    shuffle();
}

void Game::shuffle()
{
    std::random_shuffle(cards.begin(), cards.end());
}

void Game::play()
{
    getPlayers();
    distributeCards();
    int currentPlayerID;
    currentPlayerID = 0;
    while (true){
        set_battleground(players[currentPlayerID]);
        currentPlayerID = war(currentPlayerID);
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

int Game::war(int currentPlayerID) {
    std::vector<Player*> activePlayers;
    for (auto &&player : players) {
        activePlayers.push_back(&player);
    }
    size_t i = currentPlayerID;
    while(!activePlayers.empty()){
        for (;; i++) {
            ui.showPlayerPlayedCards(players);
            std::string command = ui.getCommand(*activePlayers[i],battleMarker);
            if (command == "pass") {
                activePlayers.erase(activePlayers.begin() + i);
            }
            else {
                const Card* drawnCard = activePlayers[i]->drawn_card(command);
                if (drawnCard->getType() == "Turncoat"){
                    cards.push_back(drawnCard);
                    break;
                }
                else if (drawnCard->is_season() == true){
                    cards.push_back(season);
                    season = drawnCard;
                }
                else{
                    activePlayers[i]->push_to_playedCards(drawnCard);
                }
            }
            if (i >= activePlayers.size()) i = 0;
        }
    }
    return currentPlayerID;
}

int Game::compareAge()
{
    if (players.empty())
    {
        throw std::runtime_error("No players in the game");
    }

    const Player* youngestPlayer = &players[0]; 

    for (size_t i = 1; i < players.size(); i++)
    {
        if (players[i].getAge() < youngestPlayer->getAge())
        {
            youngestPlayer = &players[i];
        }
    }

    return (*youngestPlayer).getID();
}
