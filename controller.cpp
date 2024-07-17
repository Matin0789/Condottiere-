#include "controller.h"

Controller::Controller(QObject *parent)
    : QObject{parent},
    game(new Game)
{}
