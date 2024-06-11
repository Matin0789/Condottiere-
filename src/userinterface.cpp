#include <stdlib.h>
#include <iostream>

#include <string>
#include <iostream>

#include "userinterface.h"
#include "game.h"

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


std::vector<Player> getPlayer()
{
    system("cls");
    int n;
    bool flag = true;
    do
    {
        std::cout << "Please enter your number of players: ";
        std::cin >> n;
        if(n>=3 && n<=6)
        {
            std::vector<Player> players;
            for (int i = 0; i < n; i++) 
            {
                std::string name;
                std::cout << "Enter the name for player " << (i + 1) << ": ";
                std::cin >> name;

                int age;
                std::cout << "Enter the age for player " << (i + 1) << ": ";
                std::cin >> age;

                Color color;
                std::cout << "Choose a color for player " << (i + 1) << " (0: orange, 1: blue, 2: green, 3: red, 4: gray, 5: brown): ";
                int colorChoice;
                 std::cin >> colorChoice;
                switch (colorChoice) {

                case 0: flag=true; color = Color::oranage; break;
                case 1: flag=true; color = Color::blue; break;
                case 2: flag=true; color = Color::green; break;
                case 3: flag=true; color = Color::red; break;
                case 4: flag=true; color = Color::gray; break;
                case 5: flag=true; color = Color::brown; break;
                default:
                    std::cout << "Invalid color choice, please try again." << std::endl;
                    break;
            }
            }
            return players;
        }
        else
        {
         flag=true;
        }

    }while (flag==false);
          
}

