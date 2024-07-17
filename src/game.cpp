#include <time.h>
#include <algorithm>
#include <stdexcept>
#include <cstddef>
#include <cmath>
#include <utility>
#include <fstream> // for files
#include <sstream> // for read file as stream
#include <typeinfo>

#include "game.h"
#include "filepath.h"

std::string Game::help; // set help
// constructor
Game::Game() :
    season(nullptr),
    gameBoard(BOARD_FILE)
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

    cards.push_back(season);
    season = nullptr;

    for (auto &&card : cards)
    {
        delete card;
    }
}

std::string Game::getHelp() {    // send help texts for user
    return help;
}

size_t Game::warـanalyst(){    
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
        if (typeid(*purpleCard.second) == typeid(Drummer)) {
            if (drummer_set[purpleCard.first] == false) {
                purpleCard.second->applyFeature(pointCards, purpleCard.first);
                drummer_set[purpleCard.first] = true;
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

void Game::getPlayers() {
    int n /*= ui->get_players_number()*/;
    for (size_t i = 0; i < n; i++) {
        std::string name /*= ui->get_player_name(i + 1)*/;
        unsigned int age /*= ui->get_player_old(i + 1)*/;
        Color color /*= ui->get_player_color(i + 1)*/;
        players.push_back(Player(name, i, age, color));
    }
}

void Game::distributeCards() {
    shuffle();
    for (auto &&player : players) {
        std::vector<const Card*> playerCards(cards.begin(), cards.begin() + (10 + player.getStateNumber()));
        cards.erase(cards.begin(), cards.begin() + (10 + player.getStateNumber()));
        player.setCards(playerCards);
        //ui->showPlayerCards(player);
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
    size_t favorSetterID = players.size();
    size_t battleSetterID = currentPlayerID;
    while (true){
        if (favorSetterID < players.size()) {
            set_favorground(players[favorSetterID]);
        }
        set_battleground(players[battleSetterID]);
        std::pair<size_t, std::pair<size_t, size_t>> war_return_value = war(currentPlayerID);
        currentPlayerID = war_return_value.first;
        favorSetterID = war_return_value.second.first;
        battleSetterID = war_return_value.second.second;

        bool gameEnd = find_game_winner(players[currentPlayerID]);
        if (gameEnd){
            //ui->declare_gameWinner(players[currentPlayerID]);
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

void Game::set_battleground(const Player& currentPlayer) {
    //State* battleground = ui->get_battleground(currentPlayer,gameBoard);
    //battleMarker.setState(battleground);
}

void Game::set_favorground(const Player& currentPlayer) {
    //State* favorground = ui->get_favorground(currentPlayer,gameBoard);
    //favorMarker.setState(favorground);
}

bool Game::save(std::string filePath) const {
    std::ofstream file(filePath, std::ios::binary | std::ios::trunc | std::ios::app);
    if (!file) {
        throw std::runtime_error("file " + filePath + " cannot be open in game");
    }

    // save cards
    size_t size = cards.size();
    file.write(reinterpret_cast<const char*>(&size), sizeof(size_t));
    for (auto &&card : cards) {
        size_t capacity = card->getType().capacity();
        file.write(reinterpret_cast<const char*>(&capacity), sizeof(size_t));
        std::string cardName = card->getType();
        file.write(reinterpret_cast<const char*>(&cardName), capacity);
    }
    bool season_set = false;
    if (season){
        season_set = true;
        file.write(reinterpret_cast<const char*>(&season_set), sizeof(bool));
        std::string season_type = season->getType();
        size_t capacity = season_type.capacity();
        file.write(reinterpret_cast<const char*>(&capacity), sizeof(size_t));
        file.write(reinterpret_cast<const char*>(&season_type), capacity);
    }
    else {
        season_set = false;
        file.write(reinterpret_cast<const char*>(&season_set), sizeof(bool));
    }

    // save ui object
    //size_t size_UI = sizeof(*ui);
    //file.write(reinterpret_cast<const char*>(&size_UI), sizeof(size_t));
    //file.write(reinterpret_cast<const char*>(&*ui), size_UI);


    file.close();

    // save gameboard
    size_t gameBoard_size = sizeof(gameBoard);
    file.write(reinterpret_cast<const char*>(&gameBoard_size), sizeof(size_t));
    file.write(reinterpret_cast<const char*>(&gameBoard), gameBoard_size);
    // save markers
    favorMarker.save(filePath);
    battleMarker.save(filePath);

    size_t players_size = players.size();
    file.write(reinterpret_cast<const char*>(&players_size), sizeof(size_t));
    for (auto &&player : players) {
        player.save(filePath);
    }

    return true;
}

bool Game::load(std::string filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        throw std::runtime_error("file " + filePath + " cannot be open in game");
    }

    // read cards
    size_t size;
    file.read(reinterpret_cast<char*>(&size), sizeof(size_t));
    for (size_t i = 0; i < size; i++)
    {
        size_t capacity;
        file.read(reinterpret_cast<char*>(&capacity), sizeof(size_t));
        std::string cardName;
        file.read(reinterpret_cast<char*>(&cardName), sizeof(capacity));
        if (cardName == "1")
            cards.push_back(new YellowCard(1));
        else if (cardName == "2")
            cards.push_back(new YellowCard(2));
        else if (cardName == "3")
            cards.push_back(new YellowCard(3));
        else if (cardName == "4")
            cards.push_back(new YellowCard(4));
        else if (cardName == "5")
            cards.push_back(new YellowCard(5));
        else if (cardName == "6")
            cards.push_back(new YellowCard(6));
        else if (cardName == "10")
            cards.push_back(new YellowCard(10));
        else if (cardName == "Heroine")
            cards.push_back(new Heroine(HEROINE_HELP_FILE));
        else if (cardName == "Turncoat")
            cards.push_back(new Turncoat(TURNCOAT_HELP_FILE));
        else if (cardName == "Scarecrow")
            cards.push_back(new Scarecrow(SCARECROW_HELP_FILE));
        else if (cardName == "Drummer")
            cards.push_back(new Drummer(DRUMMER_HELP_FILE));
        else if (cardName == "Bishop")
            cards.push_back(new Bishop(BISHOP_HELP_FILE));
        else if (cardName == "Spy")
            cards.push_back(new Spy(SPY_HELP_FILE));
        else 
            throw std::runtime_error("card" + cardName + " not found");
    }

    bool season_set;
    file.read(reinterpret_cast<char*>(&season_set), sizeof(bool));
    if (season_set){
        size_t capacity;
        file.read(reinterpret_cast<char*>(&capacity), sizeof(size_t));
        std::string season_type;
        file.read(reinterpret_cast<char*>(&season_type), capacity);
        if (season_type == "Spring")
            season = new Spring(SPRING_HELP_FILE);
        else if (season_type == "Winter")
            season = new Winter(WINTER_HELP_FILE);
    }
    // read ui object
    //size_t size_UI;
    //file.read(reinterpret_cast<char*>(&size_UI), sizeof(size_t));
    //file.read(reinterpret_cast<char*>(&*ui), size_UI);
    // read gameboard
    size_t gameBoard_size;
    file.read(reinterpret_cast<char*>(&gameBoard_size), sizeof(size_t));
    file.read(reinterpret_cast<char*>(&gameBoard), gameBoard_size);

    file.close();
    
    // read markers
    favorMarker.load(filePath, gameBoard);
    battleMarker.load(filePath, gameBoard);

    // read players
    size_t players_size;
    file.read(reinterpret_cast<char*>(&players_size), sizeof(size_t));
    players.clear();
    for (size_t i = 0; i < players_size; i++)
    {
        Player tmp(" ", players_size, 0, Color::white);
        tmp.load(filePath, gameBoard);
        players.push_back(tmp);
    }

    return true;
}
std::pair<size_t, std::pair<size_t, size_t>> Game::war(int currentPlayerID) {     //This function starts working when the conditions are ready and the province of the battle location is selected
    std::vector<Player*> activePlayers;
    for (auto &&player : players) {
        activePlayers.push_back(&player);
    }
    size_t i = currentPlayerID;
    size_t battleSetterID = players.size();
    size_t favorSetterID = players.size();
    std::vector<size_t> spyCounter(players.size());
    for (;!activePlayers.empty(); i++) {
        for (auto &&player : players)
        {
            //ui->showPlayerPlayedCards(player);
        }
        for (auto &&player : players)
        {
            //ui->showPlayerStates(player);
        }
        std::string command /*= ui->getCommand(*activePlayers[i],battleMarker, season)*/;
        if (command == "pass") {       // if player select passing 
            if (activePlayers.size() == 1) currentPlayerID = activePlayers[i]->getID();
            activePlayers.erase(activePlayers.begin() + i);
            i--;
        }
        else {
            const Card* drawnCard = activePlayers[i]->drawn_card(command);
            if (typeid(*drawnCard) == typeid(Turncoat)){
                cards.push_back(drawnCard);
                break;
            }
            else if (typeid(*drawnCard) == typeid(Scarecrow)){
                if (!activePlayers[i]->getPlayedCards().empty()) {
                    bool flag = false;
                    do {
                        //ui->showPlayerPlayedCards(*activePlayers[i]);
                        std::string choose /*= ui->get_card_name()*/;
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
                            //*ui << "You can only choose from yellow cards, ";
                            flag = false;
                        }
                        if (!flag) {
                            //*ui << "Please try again";
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
                if (typeid(*drawnCard) == typeid(Bishop)) {
                    battleSetterID = activePlayers[i]->getID();
                }
                else if (typeid(*drawnCard) == typeid(Spy)) {
                    spyCounter[activePlayers[i]->getID()]++;
                }
                activePlayers[i]->push_to_playedCards(drawnCard);
            }
        }
        if (i >= activePlayers.size() - 1) i = -1;
    }

    size_t winnerID = warـanalyst();

    if (winnerID < players.size()) {
        currentPlayerID = winnerID;
        players[currentPlayerID].setState(&battleMarker.getState());
        //ui->declare_warWinner(players[currentPlayerID]);
    }
    else {
        //ui->declare_warWinner();
        battleMarker.getState().set(false);
    }
    
    favorSetterID = (std::max_element(spyCounter.begin(), spyCounter.end()) - spyCounter.begin());
    std::pair<size_t, std::pair<size_t, size_t>> r; // first currentplayerID, second.first favorSetterID, second.second battleSetterID
    r.first = currentPlayerID;
    r.second.first = favorSetterID;
    if (battleSetterID < players.size()){
        r.second.second = battleSetterID;
    }
    else {
        r.second.second = currentPlayerID;
    }
    return r;
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
