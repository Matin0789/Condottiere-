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
            else if (){
                flag = true;
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
                std::cout << "Error! please try again" << std::endl;
                flag = false;
                pause();
            } 
        } while (flag == false);
        
        
    }
    
}