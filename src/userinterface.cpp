#include <stdlib.h>
#include <string>
#include <iostream>
#include <stdexcept>
#include <utility> // for pair,make_pair
#include <ctype.h> // for toupper()
#include <algorithm> // for transform

#include "userinterface.h"
#include "game.h"
#include "enumcolor.h"
#include "playerInfo.h"

UserInterface::UserInterface() {
    freeColors.push_back(std::make_pair("ORANGE", orange));
    freeColors.push_back(std::make_pair("BLUE",   blue));
    freeColors.push_back(std::make_pair("GREEN",  green));
    freeColors.push_back(std::make_pair("RED",    red));
    freeColors.push_back(std::make_pair("GRAY",   gray));
    freeColors.push_back(std::make_pair("BROWN",  brown));
}

void UserInterface::clearTerminal() const {
    system("clear");// for linux
    //system("cls"); // for windows
}

void UserInterface::pause() const {
    getchar();
    getchar();
}

void UserInterface::spliter() const {
    std::cout << "----------------------------------------" << std::endl;
}

void UserInterface::operator<<(const std::string& out) const {
    std::cout << out;
}

void UserInterface::showPlayerPlayedCards(const Player& player) const{
    std::cout << "Player" << player.getID() + 1 << " : ";
    if (!player.getPlayedCards().empty()){
        for (auto &&card : player.getPlayedCards()){
            std::cout << card->getType() << '_';
        }
    }
    std::cout << std::endl;
}

std::string UserInterface::getCommand(const Player& player,const BattleMarker& marker, const Card* season) {
    std::cout << "Battleground : " << marker.getState().getName();
    if (season != nullptr)
        std::cout << "\tSeason : " << season->getType();
    std::cout << std::endl;

    for (auto &&card : player.getCards())
        std::cout << card->getType() << ", ";
    std::cout << std::endl;
    bool flag = false;
    do {
        std::cout << "@Player" << player.getID() + 1 << " : ";
        std::string choice;
        std::cin >> choice;
        if (choice == "pass"){
            flag = true;
            return "pass";
        }
        else if (choice == "help"){
            getchar();
            std::string helpChoice;
            getline(std::cin,helpChoice);
            if (helpChoice == ""){
                std::cout << Game::getHelp() << std::endl;
            }
            else if(helpChoice == "Bishop"){
                std::cout << Bishop::getHelp() << std::endl;
            }
            else if(helpChoice == "Drummer"){
                std::cout << Drummer::getHelp() << std::endl;
            }
            else if(helpChoice == "Heroine"){
                std::cout << Heroine::getHelp() << std::endl;
            }     
            else if(helpChoice == "Scarecrow"){
                std::cout << Scarecrow::getHelp() << std::endl;
            }
            else if(helpChoice == "Spy"){
                std::cout << Spy::getHelp() << std::endl;
            }
            else if(helpChoice == "Turncoat"){
                std::cout << Turncoat::getHelp() << std::endl;
            }
            else if(helpChoice == "Winter"){
                std::cout << Winter::getHelp() << std::endl;
            }
            else if(helpChoice == "Spring"){
                std::cout << Spring::getHelp() << std::endl;
            }
            else{
                std::cout << "Error! please try again" << std::endl;
                pause();
            }
        }
        else{
            for (auto &&card : player.getCards()){
                if (choice == card->getType()){
                    flag = true;
                    return card->getType();
                }     
            }
            std::cout << "Error! please try again" << std::endl;
            flag = false;
            pause();
        }
    } while (flag == false);
    return "";
}

State* UserInterface::get_battleground(const Player& player,GameBoard& gameBoard) {
    clearTerminal();
    bool flag = false;
    std::string choice;
    do {
        std::cout << "active states : ";
        for (auto &&stateName : gameBoard.get_active_states_name()) {
            std::cout << stateName << ", ";
        }
        std::cout << std::endl;
        std::cout << "Player" << player.getID() + 1 << ", please specify the battleground : ";
        std::cin >> choice;
        for (auto &&stateName : gameBoard.get_active_states_name()) {
            if (stateName == choice) {
                clearTerminal();
                return gameBoard.getState(choice);
                flag = true;
            }
        }
    } while (flag == false);
    throw std::runtime_error("UserInterface::get__battleground bad choice");
}

State* UserInterface::get_favorground(const Player& player,GameBoard& gameBoard) {
    clearTerminal();
    bool flag = false;
    std::string choice;
    do {
        std::cout << "active states : ";
        for (auto &&stateName : gameBoard.get_active_states_name()) {
            std::cout << stateName << ", ";
        }
        std::cout << "OUT";
        std::cout << std::endl;
        std::cout << "Player" << player.getID() + 1 << ", please specify the favorground : ";
        std::cin >> choice;
        for (auto &&stateName : gameBoard.get_active_states_name()) {
            if (stateName == choice) {
                clearTerminal();
                return gameBoard.getState(choice);
                flag = true;
            }
        }
        if (choice == "OUT") {
            clearTerminal();
            return nullptr;
            flag = true;
        }
    } while (flag == false);
    throw std::runtime_error("UserInterface::get__favorground bad choice");
}
void UserInterface::showPlayerStates(const Player& player) const{
    std::cout << "Player" << player.getID() + 1 << " : ";
    if (!player.get_states_name().empty()){
        for (auto &&stateName : player.get_states_name()){
            std::cout << stateName << ", "; 
        }
    }
    std::cout << std::endl;
}

void UserInterface::showPlayerCards(const Player& player) const{
    clearTerminal();
    std::cout << "Player" << player.getID() + 1 << "'s cards are about to be shown.\nPlease hand over the system to him.";
    pause();
    clearTerminal();
    for (auto &&card : player.getCards()){
        std::cout << card->getType() << ", ";
    }
    pause();
}

std::string UserInterface::get_card_name() {
    std::string choose;
    std::cin >> choose;
    clearTerminal();
    return choose;
}

int UserInterface::get_players_number() {
    Set set;
    set.show();
}

std::string UserInterface::get_player_name(size_t playerID) {
    std::cout << "please enter Player" << playerID << " name : ";
    std::string name;
    std::cin >> name;
    return name;
}

unsigned int UserInterface::get_player_old(size_t playerID) {
    std::cout << "please enter Player" << playerID << " old : ";
    unsigned int old;
    std::cin >> old;
    return old;
}

Color  UserInterface::get_player_color(size_t playerID) {
    std::string input;
    Color choiceColor;
    bool flag =true;
    do
    {
        std::cout << "please enter Player" << playerID;
        std::cout << " [";    
        for (auto &&color : freeColors)
        {
            std::cout << color.first << ',';
        }
        std::cout << "] : ";

        std::cin >> input;
        std::transform(input.begin(), input.end(), input.begin(), ::toupper); 
        for (size_t i = 0; i < freeColors.size(); i++)
        {
            if (input == freeColors[i].first) {
                flag = true;
                choiceColor = freeColors[i].second;
                freeColors.erase(freeColors.begin() + i);
                return choiceColor;
            }
        }
        std::cout << "undifiend please try again!" << std::endl;
        flag = false;
    } while (flag == false);
    return choiceColor;
}

void UserInterface::declare_warWinner(const Player& player) const{
    clearTerminal();
    std::cout << "It was a hard battle. Player" << player.getID() + 1 << " wins the battle and captures the state";
    pause();
}

void UserInterface::declare_warWinner() const{
    clearTerminal();
    std::cout << "It was a hard battle. The battle was inconclusive and no player captured the state";
    pause();
}

void UserInterface::declare_gameWinner(const Player& player) const{
    clearTerminal();
    std::cout << "The game finished\nPlayer"<< player.getID() + 1 << " won the game";
    pause();
}
