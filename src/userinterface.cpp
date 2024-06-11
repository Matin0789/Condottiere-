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

void UserInterface::showPlayerCards(const std::vector<Player>& players) const{
    clearTerminal();
    for (auto &&player : players){
        std::cout << "Player" << player.getID() << " : ";
        if (!player.getPlayedCards().empty()){
            for (auto &&card : player.getPlayedCards()){
                std::cout << card->getType() << '_'; 
            }
            std::cout << std::endl;
        }
    }
    std::cout << "--------------------";
}

std::string UserInterface::getCommand(const Player& player,const BattleMarker& marker) {
    //std::cout << marker.getState().getName() << std::endl;
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
            getline(std::cin,helpChoice,'\n');
            if (helpChoice == ""){
                flag = true;
            }
            else if(helpChoice == "Bishop"){
                Bishop::getHelp();
            }
            else if(helpChoice == "Drummer"){
                Drummer::getHelp();
                flag = true;
            }
            else if(helpChoice == "Heroine"){
                Heroine::getHelp();
                flag = true;
            }     
            else if(helpChoice == "Scarecrow"){
                Scarecrow::getHelp();
                flag = true;
            }
            else if(helpChoice == "Spy"){
                Spy::getHelp();
                flag = true;
            }
            else if(helpChoice == "Turncoat"){
                Turncoat::getHelp();
                flag = true;
            }
            else if(helpChoice == "Winter"){
                Winter::getHelp();
                flag = true;
            }
            else if(helpChoice == "Spring"){
                Spring::getHelp();
                flag = true;
            }
            else{
                std::cout << "Error! please try again" << std::endl;
                flag = false;
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
    std::cout << "please enter name Player" << playerID << " name : ";
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
    bool flag = false;
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
