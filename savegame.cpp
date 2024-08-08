#include "savegame.h"
#include "ui_savegame.h"

saveGame::saveGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::saveGame)
{
    ui->setupUi(this);
}

saveGame::~saveGame()
{
    delete ui;
}
