#include "ShirinAghl.h"
#include "player.h"
#include "yellowcard.h"
#include "card.h"

#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>


std::string ShirinAghl::help;

ShirinAghl::ShirinAghl(std::string helpFilePath) : PurpleCard(0,"ShirinAghl",3){
    std::ifstream helpFile(helpFilePath);
    if (helpFile.is_open()){
        std::stringstream helpString;
        std::string tmp;
        while(getline(helpFile,tmp)){
            helpString << '\n' << tmp;
        }
        help = helpString.str();
        helpFile.close();
    }
    else 
        throw std::runtime_error("The ShirinAghl help file cannot be opened");


        equalCard = nullptr;
}

std::string ShirinAghl::getHelp() {
    return help;
}

void ShirinAghl::applyFeature(std::vector<std::vector<unsigned int>>& playersCardPoints, int currentPlayerID) const {
    equalCard->applyFeature( playersCardPoints, currentPlayerID) ;
    delete equalCard ;
    equalCard = nullptr;
}

void ShirinAghl::shirinAghlFeature(const Player &player) {
    size_t i = rand() % player.getPlayedCards().size() ; 
    std::string equalCard  = player.getPlayedCards()[i]->getType();
        if (cardName == "1") {
            equalCard = new YellowCard(1);
        }
        else if (cardName == "2") {
            equalCard = new YellowCard(2);
        }
        else if (cardName == "3") {
            equalCard = new YellowCard(3);
        }
        else if (cardName == "4") {
            equalCard = new YellowCard(4);
        }
        else if (cardName == "5") {
            equalCard = new YellowCard(5);
        }
        else if (cardName == "6") {
            equalCard = new YellowCard(6);
        }
        else if (cardName == "10") {
            equalCard = new YellowCard(10);
        }
        else if (cardName == "Heroine") {
            equalCard = new Heroine(HEROINE_HELP_FILE);
        }
        else if (cardName == "Turncoat") {
            equalCard = new Turncoat(TURNCOAT_HELP_FILE);
        }
        else if (cardName == "Scarecrow") {
            equalCard = new Scarecrow(SCARECROW_HELP_FILE);
        }
        else if (cardName == "Drummer") {
            equalCard = new Drummer(DRUMMER_HELP_FILE);
        }
        else if (cardName == "Bishop") {
            equalCard = new Bishop(BISHOP_HELP_FILE);
        }
        else if (cardName == "Spy") {
            equalCard = new Spy(SPY_HELP_FILE);
        }
        else if (cardName == "Winter") {
            equalCard = new Winter(WINTER_HELP_FILE);
        }
        else if (cardName == "Spring") {
            equalCard = new Spring(SPRING_HELP_FILE);
        }
        else if (cardName == "WhiteRakhsh") {
            equalCard = new WhiteRakhsh(WHITERAKHSH_HELP_FILE);
        }
        else if (cardName == "WhiteSeal") {
            equalCard = new WhiteSeal(WHITESEALS_HELP_FILE);
        }
        else if (cardName == "ShirinAghl") {
            equalCard = new ShirinAghl(SHIRINAGHL_HELP_FILE);
        }
}

 std::string getType() const {
    if(equalCard){
        return equalCard->getType();
    }
    else {
       return PurpleCard::getType();
    }
 }
