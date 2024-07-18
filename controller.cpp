#include "controller.h"

Controller::Controller(QObject *parent)
    : QObject{parent},
    game(new Game)
{}

Controller::~Controller() {
    delete game;
}

void Controller::get_player(std::string name, size_t age, Color color)
{
    game->getPlayer(name, age, color);
}
