#include <stdlib.h>
#include <iostream>

#include <string>
#include <iostream>

#include "userinterface.h"
#include "game.h"

void UserInterface::clearTerminal() const{
    system("clear");// for linux
    //system("cls"); // for windows
}

void UserInterface::pause(){
    getchar();
    getchar();
}

void UserInterface::showPlayerPlayedCards(const std::vector<Player>& players) const{
    clearTerminal();
    for (auto &&player : players){
        std::cout << "Player" << player.getID() << " : ";
        if (!player.getPlayedCards().empty()){
            for (auto &&card : player.getPlayedCards()){
                std::cout << card->getType() << '_'; 
            }
        }
        std::cout << std::endl;
    }
    std::cout << "--------------------" << std::endl;
}

std::string UserInterface::getCommand(const Player& player,const BattleMarker& marker) {
    std::cout << marker.getState().getName() << std::endl;
    for (auto &&card : player.getCards())
        std::cout << card->getType() << ',';
    std::cout << std::endl;
    bool flag = false;
    do
    {
        std::cout << "Player" << player.getID() << "@ : ";
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
                Game::getHelp();
            }
            else if(helpChoice == "Bishop"){
                Bishop::getHelp();
            }
            else if(helpChoice == "Drummer"){
                Drummer::getHelp();
            }
            else if(helpChoice == "Heroine"){
                Heroine::getHelp();
            }     
            else if(helpChoice == "Scarecrow"){
                Scarecrow::getHelp();
            }
            else if(helpChoice == "Spy"){
                Spy::getHelp();
            }
            else if(helpChoice == "Turncoat"){
                Turncoat::getHelp();
            }
            else if(helpChoice == "Winter"){
                Winter::getHelp();
            }
            else if(helpChoice == "Spring"){
                Spring::getHelp();
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
    bool flag = false;
    std::string choice;
    do {
        std::cout << "active states : ";
        for (auto &&stateName : gameBoard.get_active_states_name()) {
            std::cout << stateName << ", ";
        }
        std::cout << std::endl;
        std::cout << "Player" << player.getID() << ", please specify the battleground : ";
        std::cin >> choice;
        for (auto &&stateName : gameBoard.get_active_states_name()) {
            if (stateName == choice) {
                return gameBoard.getState(choice);
                flag = true;
            }
        }
        pause();
    } while (flag == false);
    
}
 
int UserInterface::get_players_number() {
    int n;
    bool flag = false;
    do
    {
        std::cout << "Please enter player numbers:";
        std::cin >> n;
        try{
            flag = Game::check_number_of_player(n);
        }
        catch(const std::out_of_range& e){
            std::cerr << e.what() << '\n';
        }
    } while (flag == false);
    return n;
   
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
    Color color;
    bool flag = true;
    do
    {
        std::cout << "please enter Player" << playerID << " Color [orange,blue,green,red,gray,brown] : ";
        std::cin >> input;
        if (input == "orange") {color = orange; flag = true; }
        else if (input == "blue") {color = blue; flag = true; }
        else if (input == "green") {color = green; flag = true; }
        else if (input == "red") {color = red; flag = true; }
        else if (input == "gray") {color = gray; flag = true; }
        else if (input == "brown") {color = brown; flag = true; }
        else {
            std::cout << "undifiend please try again!" << std::endl;
            flag = false;
        }
    } while (flag == false);
    return color;
}
