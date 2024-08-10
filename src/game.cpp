#include <time.h>
#include <algorithm>
#include <stdexcept>
#include <cstddef>
#include <cmath>
#include <utility>
#include <fstream> // for files
#include <sstream> // for read file as stream
#include <QDebug>
#include <iomanip>

#include "game.h"
#include "filepath.h"

std::string Game::help; // set help
// constructor
Game::Game(QObject *parent) :
    QObject{parent},
    season(nullptr),
    gameBoard(BOARD_FILE),
    is_load(false)
{
    srand(time(0));    // for rand function

    // Read help from file
    std::ifstream helpFile(Game_HELP_FILE);
    if (helpFile.is_open()) {
        std::stringstream helpString;
        std::string tmp;
        while(getline(helpFile,tmp)){
            helpString << '\n' << tmp;
        }
        Game::help = helpString.str();
        helpFile.close();
    }
    else
        throw std::runtime_error("The game help file cannot be opened");
    //
    
    freeColors["ORANGE"] =  orange;
    freeColors["BLUE"]   =  blue;
    freeColors["GREEN"]  =  green;
    freeColors["RED"]    =  red;
    freeColors["GRAY"]   =  gray;
    freeColors["BROWN"]  =  brown;

    for (int i = 0; i < 10; i++)
    {
        cards.push_back(new YellowCard(1));  // an array of yellow cards
    }
    for (int i = 0; i < 8; i++)    // point of yellow cards
    {
        cards.push_back(new YellowCard(2));
        cards.push_back(new YellowCard(3));
        cards.push_back(new YellowCard(4));
        cards.push_back(new YellowCard(5));
        cards.push_back(new YellowCard(6));
        cards.push_back(new YellowCard(10));
    }
    for (int i = 0; i < 3; i++)     // an array of purple cards (heroine , spring , winter)
    {
        cards.push_back(new Heroine(HEROINE_HELP_FILE));
        cards.push_back(new Spring(SPRING_HELP_FILE));
        cards.push_back(new Winter(WINTER_HELP_FILE));
        cards.push_back(new Turncoat(TURNCOAT_HELP_FILE));
    }
    for (int i = 0; i < 16; i++)  // an array of purple cards (scarecrow)
    {
        cards.push_back(new Scarecrow(SCARECROW_HELP_FILE));
    }
    for (int i = 0; i < 6; i++)
    {

        cards.push_back(new Drummer(DRUMMER_HELP_FILE));
        cards.push_back(new Bishop(BISHOP_HELP_FILE));
    }
    for (int i = 0;i < 12;i++){
        cards.push_back(new Spy(SPY_HELP_FILE));
    }
    for (int i = 0;i < 1;i++){
        cards.push_back(new WhiteSeal(WHITESEALS_HELP_FILE));
        cards.push_back(new ShirinAghl(SHIRINAGHL_HELP_FILE));
    }
    for (int i = 0;i < 2;i++){
        cards.push_back(new WhiteRakhsh(WHITERAKHSH_HELP_FILE));

    }
}

Game::~Game() {
    for (auto &&player : players)
    {
        std::vector<const Card*> tmp(player.burnCards());
        if (!tmp.empty()){
            cards.insert(cards.end(), tmp.begin(), tmp.end());
        }
    }
    for (auto &&player : players)
    {
        std::vector<const Card*> tmp(player.burnPlayedCards());
        if (!tmp.empty()){
            cards.insert(cards.end(), tmp.begin(), tmp.end());
        }
    }

    if (season) {
        cards.push_back(season);
        season = nullptr;
    }

    for (auto &&card : cards)
    {
        delete card;
    }
    cards.clear();

}

std::string Game::getHelp() {    // send help texts for user
    return help;
}

size_t Game::warـanalyst(){    
    std::vector<std::vector<unsigned int>> pointCards(players.size());
    std::vector<std::pair<size_t ,const Card*>> purpleCards;
    std::vector<bool> drummer_set(players.size(),false);   //This code is related to phase 3 of the project

    for (size_t i = 0; i < players.size(); i++)
    {
        const std::vector<const Card*> playerPlayedCards = players[i].getPlayedCards();
        for (auto &&card : playerPlayedCards)
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
        if (purpleCard.second->getType() == "Heroine") {        //This code is related to phase 3 of the project
            if(season) {                                                 //This code is related to phase 3 of the project
                if (season->getType() == "Spring") {                              //This code is related to phase 3 of the project
                    pointCards[purpleCard.first].push_back(purpleCard.second->getPoint()+3);                  //This code is related to phase 3 of the project
                }
            }
        }
        else{
            purpleCard.second->applyFeature(pointCards, purpleCard.first);
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

void Game::get_player(std::string name, size_t age, Color color) {
    for (auto &&freeColor : freeColors) {
        if(freeColor.second == color){
            freeColors.erase(freeColors.find(freeColor.first));
            break;
        }
    }
    players.push_back(Player(name, players.size(), age, color));
}

void Game::distributeCards() {
    shuffle();
    for (auto &&player : players) {
        std::vector<const Card*> playerCards(cards.begin(), cards.begin() + (10 + player.getStateNumber()));
        cards.erase(cards.begin(), cards.begin() + (10 + player.getStateNumber()));
        player.setCards(playerCards);
    }
    for (auto &&player : players) {
        emit showPlayerCards(player);
    }
}

void Game::shuffle()  //This function is for shuffling cards
{
    std::random_shuffle(cards.begin(), cards.end()); //This is a default function in C++ that is used for shuffling
}

void Game::start()
{
    if (!is_load) {
        size_t players_number = emit get_players_number();
        for (size_t i = 0; i < players_number; i++) {
            emit get_player_page_show(freeColors, i);
        }
        distributeCards();
        currentPlayerID = 1;
        currentPlayerID = compareAge();
        favorSetterID = players.size();
        battleSetterID = currentPlayerID;
    }
    while (true){
        if (favorSetterID < players.size()) {
            favorMarker.setState(emit set_favorground(players ,players[favorSetterID], gameBoard, favorMarker));
        }
        battleMarker.setState(emit set_battleground(players, players[battleSetterID], gameBoard, favorMarker));

        war(currentPlayerID);

        bool gameEnd = find_game_winner(players[currentPlayerID]);
        if (gameEnd){
            emit declare_gameWinner(players, players[currentPlayerID]);
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

bool Game::check_number_of_player(std::string n) {
    if (n >= "3" && n <= "6" && n.size() <= 1) {
        return true;
    }
    else{
        throw std::out_of_range("Invalid number of players! please enter a number between 3 , 6");
        return false;
    }
}

void Game::save(std::string filePath) {
    std::ofstream file(filePath, std::ios::trunc);
    if(!file){
        throw std::runtime_error("file cannot be save");
    }

    //qInfo() << "save ok";
    // save battle data

    // file.write(reinterpret_cast<const char*>(&currentPlayerID), sizeof(size_t));
    // file.write(reinterpret_cast<const char*>(&battleSetterID), sizeof(size_t));
    // file.write(reinterpret_cast<const char*>(&favorSetterID), sizeof(size_t));
    file << currentPlayerID << ' ' << battleSetterID << ' ' << favorSetterID << std::endl;

    // save cards
    // binary
    // size_t size = cards.size();
    // file.write(reinterpret_cast<const char*>(&size), sizeof(size_t));
    // for (auto &&card : cards) {
    //     size_t capacity = card->getType().capacity();
    //     file.write(reinterpret_cast<const char*>(&capacity), sizeof(size_t));
    //     std::string cardName = card->getType();
    //     file.write(reinterpret_cast<const char*>(&cardName[0]), capacity);
    // }
    // bool season_set = false;
    // if (season){
    //     season_set = true;
    //     file.write(reinterpret_cast<const char*>(&season_set), sizeof(bool));
    //     std::string season_type = season->getType();
    //     size_t capacity = season_type.capacity();
    //     file.write(reinterpret_cast<const char*>(&capacity), sizeof(size_t));
    //     file.write(reinterpret_cast<const char*>(&season_type), capacity);
    // }
    // else {
    //     season_set = false;
    //     file.write(reinterpret_cast<const char*>(&season_set), sizeof(bool));
    // }

    // txt
    size_t size = cards.size();
    file << size << ' ';
    for (auto &&card : cards) {
        std::string cardName = card->getType();
        file << '\"' << cardName << '\"' << ' ';
    }
    file << std::endl;

    bool season_set = false;
    season_set = season ? true:false;
    file << season_set;
    if (season_set){
        std::string season_type = season->getType();
        file << ' ' << season_type;
    }
    file << std::endl;

    size_t players_size = players.size();
    // file.write(reinterpret_cast<const char*>(&players_size), sizeof(size_t));
    file << players_size << std::endl;

    file.close();

    for (auto &&player : players) {
        player.save(filePath);
    }

    // save gameboard
    gameBoard.save(filePath);
    // save markers




}

void Game::load(std::string filePath) {
    std::ifstream file(filePath);
    if (!file) {
        throw std::runtime_error("file " + filePath + " cannot be open in game");
    }

    for (auto &&player : players)
    {
        std::vector<const Card*> tmp(player.burnCards());
        if (!tmp.empty()){
            cards.insert(cards.end(), tmp.begin(), tmp.end());
        }
    }
    for (auto &&player : players)
    {
        std::vector<const Card*> tmp(player.burnPlayedCards());
        if (!tmp.empty()){
            cards.insert(cards.end(), tmp.begin(), tmp.end());
        }
    }

    if (season) {
        cards.push_back(season);
        season = nullptr;
    }

    for (auto &&card : cards)
    {
        delete card;
    }
    cards.clear();
    ////////////////////////////////////



    // read battle data
    // file.read(reinterpret_cast<char*>(&currentPlayerID), sizeof(size_t));
    // file.read(reinterpret_cast<char*>(&battleSetterID), sizeof(size_t));
    // file.read(reinterpret_cast<char*>(&favorSetterID), sizeof(size_t));
    file >> currentPlayerID >> battleSetterID >> favorSetterID;

    // read cards
    size_t size;
    //file.read(reinterpret_cast<char*>(&size), sizeof(size_t));
    file >> size;
    for (size_t i = 0; i < size; i++)
    {
        // size_t capacity;
        // file.read(reinterpret_cast<char*>(&capacity), sizeof(size_t));
        std::string cardName;
        //file.read(reinterpret_cast<char*>(&cardName[0]), sizeof(capacity));
        file >> quoted(cardName);
        if (cardName == "1") {
            cards.push_back(new YellowCard(1));
        }
        else if (cardName == "2") {
            cards.push_back(new YellowCard(2));
        }
        else if (cardName == "3") {
            cards.push_back(new YellowCard(3));
        }
        else if (cardName == "4") {
            cards.push_back(new YellowCard(4));
        }
        else if (cardName == "5") {
            cards.push_back(new YellowCard(5));
        }
        else if (cardName == "6") {
            cards.push_back(new YellowCard(6));
        }
        else if (cardName == "10") {
            cards.push_back(new YellowCard(10));
        }
        else if (cardName == "Heroine") {
            cards.push_back(new Heroine(HEROINE_HELP_FILE));
        }
        else if (cardName == "Turncoat") {
            cards.push_back(new Turncoat(TURNCOAT_HELP_FILE));
        }
        else if (cardName == "Scarecrow") {
            cards.push_back(new Scarecrow(SCARECROW_HELP_FILE));
        }
        else if (cardName == "Drummer") {
            cards.push_back(new Drummer(DRUMMER_HELP_FILE));
        }
        else if (cardName == "Bishop") {
            cards.push_back(new Bishop(BISHOP_HELP_FILE));
        }
        else if (cardName == "Spy") {
            cards.push_back(new Spy(SPY_HELP_FILE));
        }
        else if (cardName == "Winter") {
            cards.push_back(new Winter(WINTER_HELP_FILE));
        }
        else if (cardName == "Spring") {
            cards.push_back(new Spring(SPRING_HELP_FILE));
        }
        else if (cardName == "WhiteRakhsh") {
            cards.push_back(new WhiteRakhsh(WHITERAKHSH_HELP_FILE));
        }
        else if (cardName == "WhiteSeal") {
            cards.push_back(new WhiteSeal(WHITESEALS_HELP_FILE));
        }
        else if (cardName == "ShirinAghl") {
            cards.push_back(new ShirinAghl(SHIRINAGHL_HELP_FILE));
        }
        else  {
            throw std::runtime_error("card" + cardName + " not found");
        }
    }

    bool season_set;
    //file.read(reinterpret_cast<char*>(&season_set), sizeof(bool));
    file >> season_set;
    if (season_set){
        // size_t capacity;
        // file.read(reinterpret_cast<char*>(&capacity), sizeof(size_t));
        std::string season_type;
        // file.read(reinterpret_cast<char*>(&season_type), capacity);
        file >> quoted(season_type);
        if (season_type == "Spring")
            season = new Spring(SPRING_HELP_FILE);
        else if (season_type == "Winter")
            season = new Winter(WINTER_HELP_FILE);
    }

    // read players
    size_t players_size;
    //file.read(reinterpret_cast<char*>(&players_size), sizeof(size_t));
    file >> players_size;
    file.close();

    players.clear();
    for (size_t i = 0; i < players_size; i++)
    {
        Player tmp(" ", i, 0, Color::white);
        tmp.load(filePath, gameBoard);
        players.push_back(tmp);
    }


    // read gameboard
    gameBoard.load(filePath);

    is_load = true;
}

void Game::war(int currentPlayerID) {     //This function starts working when the conditions are ready and the province of the battle location is selected
    emit startWar(players, battleMarker, favorMarker);
    std::vector<Player*> activePlayers;
    for (auto &&player : players) {
        activePlayers.push_back(&player);
    }
    size_t i = currentPlayerID;
    size_t battleSetterID;
    size_t favorSetterID = players.size();
    std::vector<std::pair<size_t, size_t>> spyCounter(players.size());
    size_t checkTurncoatApply = players.size();                    //This code is related to phase 3 of the project
    size_t checkWhiteRakhshApply = players.size();                      //This code is related to phase 3 of the project
    for(size_t i = 0;i < players.size(); i++) {
        spyCounter[i].first = players[i].getID();
        spyCounter[i].second = 0;
    }
    for (;!activePlayers.empty(); i++) {
        std::string command = emit getCommand(players, *activePlayers[i], season);
        if (command == "pass") {       // if player select passing 
            if (activePlayers.size() == 1) currentPlayerID = activePlayers[i]->getID();
            activePlayers.erase(activePlayers.begin() + i);
            i--;
        }
        else {
            const Card* drawnCard = activePlayers[i]->drawn_card(command);
            if (drawnCard->getType() == "Turncoat"){                 //This code is related to phase 3 of the project
                cards.push_back(drawnCard);                             //This code is related to phase 3 of the project
                if(activePlayers.size() == players.size()) {                    //This code is related to phase 3 of the project
                  checkTurncoatApply = activePlayers[i-1]->getID();                       //This code is related to phase 3 of the project
                }
                break;
            }
            else if(drawnCard->getType() == "WhiteRakhsh") {            //This code is related to phase 3 of the project          
                checkWhiteRakhshApply = activePlayers[i]->getID();          //This code is related to phase 3 of the project
                break;
            }
            else if (drawnCard->getType() == "WhiteSeal") {
                for(auto && player: players) {
                    cards.push_back(player.burnPlayedCards());
                }
            }
            else if (drawnCard->getType() == "ShirinAghl") {
                drawnCard->shirinAghlFeature(*activePlayers[i]);
            }
                
            else if (drawnCard->getType() == "Scarecrow"){
                if (!activePlayers[i]->getPlayedCards().empty()) {
                    std::string choose = emit scarecrow_get_card(*activePlayers[i]);
                    if (choose[0] >= '0' and choose[0] <= '9'){
                        for (const auto &card : activePlayers[i]->getPlayedCards()) {
                            if (card->getType() == choose) {
                                const Card* drawnPlayedCard = activePlayers[i]->drawn_playedCard(choose);
                                activePlayers[i]->push_to_playedCards(drawnCard);
                                activePlayers[i]->push_to_cards(drawnPlayedCard);
                            }
                        }
                    }
                    else {
                        activePlayers[i]->push_to_playedCards(drawnCard);
                    }
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
                if (drawnCard->getType() == "Bishop") {
                    
                    favorSetterID = activePlayers[i]->getID();
                }
                else if (drawnCard->getType() == "Spy") {
                    spyCounter[activePlayers[i]->getID()].second++;
                }
                activePlayers[i]->push_to_playedCards(drawnCard);
            }
        }
        if (i >= activePlayers.size() - 1) i = -1;
    }
    size_t winnerID ;
    if (checkWhiteRakhshApply < players.size()) {
        winnerID = checkWhiteRakhshApply ;
    }
    else {
        winnerID = warـanalyst();
    }
    if (winnerID < players.size()) {
        currentPlayerID = winnerID;
        players[currentPlayerID].setState(&battleMarker.getState());
    }
    else {
        battleMarker.getState().set(false);
    }
    


    std::sort(spyCounter.begin(), spyCounter.end(),
              [](const std::pair<size_t,size_t>& p1, const std::pair<size_t,size_t>& p2) {
        return p1.second > p2.second;
    });

    if (spyCounter[0].second != 0) {
        if (spyCounter[0].second == spyCounter[1].second){
           battleSetterID = currentPlayerID;
        }
        else {
            battleSetterID = spyCounter[0].first;
        }
    }    
    else if (checkTurncoatApply < players.size() ) {
        battleSetterID = checkTurncoatApply ;
    }
    else {
        battleSetterID = currentPlayerID;
    }

    this->currentPlayerID = currentPlayerID;
    this->favorSetterID = favorSetterID;
    this->battleSetterID = battleSetterID;

    emit endWar();

    if (winnerID < players.size()) {
        emit declare_warWinner(players[currentPlayerID], battleMarker);
    }
    else {
        emit declare_warWinner(players[currentPlayerID], battleMarker, false);
    }
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
