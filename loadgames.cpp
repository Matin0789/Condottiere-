#include "loadgames.h"
#include "ui_loadgames.h"

loadGames::loadGames(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loadGames)
{
    ui->setupUi(this);
}

loadGames::~loadGames()
{
    delete ui;
}
