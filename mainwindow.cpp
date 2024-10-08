#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "battlemarker.h"
#include "favormarker.h"
#include "filepath.h"

#include <QMessageBox>
#include <QPixmap>
#include <QMediaPlayer>
#include <QAudioOutput>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    game(new Game),
    battleground_page(new Locateinfo("BattleMarker", this)),
    favorground_page(new Locateinfo( "FavorMarker", this)),                 // ///  set classes 
    start(new Start(this)),
    setplayer(new Setplayer(this)),
    campaign(new Campaign(this)),
    warWinner_page(new Winner(this)),
    gameWinner_page(new GameWinner(this)),
    showcards(new showCards(this)),
    load_page(new loadGames(this)),
    save_page(new saveGame(this))
{
    ui->setupUi(this);
    this->setWindowTitle("Condottiere");

    ui->btn_sound->setStyleSheet("border-image:url(:/Description/Graphics/photos/volume.png);background-color:transparent");       // change stylesheets

    player = new QMediaPlayer;                 // play media 
    audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile("../../Description/Graphics/Sounds/background_music.mp3"));       // path of music of game    // 
    audioOutput->setVolume(1);                          // set volume 
    player->play();                                   // start music
    player->setLoops(QMediaPlayer::Infinite);             // pause 
}

MainWindow::~MainWindow()
{
    delete battleground_page;
    delete favorground_page;
    delete start;
    delete setplayer;
    delete ui;
    delete game;                                            // distructor of objects 
    delete showcards;
    delete campaign;
    delete player;
    delete audioOutput;
    delete gameWinner_page;
    delete warWinner_page;
}

void MainWindow::on_btn_Start_clicked()
{
    hide();
    delete game;
    game = new Game;

    QObject::connect(game, &Game::get_players_number, start, &Start::get_players_number);
    QObject::connect(game, &Game::get_player_page_show, setplayer, &Setplayer::page_show);
    QObject::connect(setplayer, &Setplayer::get_player, game, &Game::get_player);
    QObject::connect(game, &Game::set_battleground, battleground_page, &Locateinfo::set_ground);
    QObject::connect(game, &Game::set_favorground,  favorground_page,  &Locateinfo::set_ground);
    QObject::connect(game, &Game::showPlayerCards, showcards, &showCards::getPlayer);
    QObject::connect(game, &Game::startWar, campaign, &Campaign::startWar);
    QObject::connect(game, &Game::endWar, campaign, &Campaign::hide);
    QObject::connect(game, &Game::getCommand, campaign, &Campaign::getCommand);
    QObject::connect(game, &Game::scarecrow_get_card, campaign, &Campaign::scarecrow_get_card);
    QObject::connect(game, &Game::declare_gameWinner, gameWinner_page, &GameWinner::declare);
    QObject::connect(game, &Game::declare_warWinner, warWinner_page, &Winner::declare);

    QObject::connect(this, SIGNAL(getLoadFile()), load_page, SLOT(load()));
    QObject::connect(save_page, &saveGame::data_save, game, &Game::save);
    QObject::connect(warWinner_page, SIGNAL(save()), save_page, SLOT(save()));

    game->start();

    QObject::disconnect(this, SIGNAL(getLoadFile()), load_page, SLOT(load()));
    QObject::disconnect(save_page, &saveGame::data_save, game, &Game::save);
    QObject::disconnect(warWinner_page, SIGNAL(save()), save_page, SLOT(show()));

    QObject::disconnect(game, &Game::get_players_number, start, &Start::get_players_number);
    QObject::disconnect(game, &Game::get_player_page_show, setplayer, &Setplayer::page_show);
    QObject::disconnect(setplayer, &Setplayer::get_player, game, &Game::get_player);
    QObject::disconnect(game, &Game::set_battleground, battleground_page, &Locateinfo::set_ground );
    QObject::disconnect(game, &Game::set_favorground,  favorground_page,  &Locateinfo::set_ground );
    QObject::disconnect(game, &Game::showPlayerCards, showcards, &showCards::getPlayer);
    QObject::disconnect(game, &Game::showPlayerCards, showcards, &showCards::getPlayer);
    QObject::disconnect(game, &Game::startWar, campaign, &Campaign::startWar);
    QObject::disconnect(game, &Game::endWar, campaign, &Campaign::hide);
    QObject::disconnect(game, &Game::getCommand, campaign, &Campaign::getCommand);
    QObject::disconnect(game, &Game::scarecrow_get_card, campaign, &Campaign::scarecrow_get_card);
    QObject::disconnect(game, &Game::declare_gameWinner, gameWinner_page, &GameWinner::declare);
    QObject::disconnect(game, &Game::declare_warWinner, warWinner_page, &Winner::declare);
}

void MainWindow::on_btn_exit_clicked()
{
    exit(EXIT_SUCCESS);
}

void MainWindow::on_btn_load_game_clicked()
{
    hide();
    delete game;
    game = new Game;
                                                                 // connect and disconnect of classes and objects  // 
    QObject::connect(game, &Game::get_players_number, start, &Start::get_players_number);
    QObject::connect(game, &Game::get_player_page_show, setplayer, &Setplayer::page_show);
    QObject::connect(setplayer, &Setplayer::get_player, game, &Game::get_player);
    QObject::connect(game, &Game::set_battleground, battleground_page, &Locateinfo::set_ground);
    QObject::connect(game, &Game::set_favorground,  favorground_page,  &Locateinfo::set_ground);
    QObject::connect(game, &Game::showPlayerCards, showcards, &showCards::getPlayer);
    QObject::connect(game, &Game::startWar, campaign, &Campaign::startWar);
    QObject::connect(game, &Game::getCommand, campaign, &Campaign::getCommand);
    QObject::connect(game, &Game::scarecrow_get_card, campaign, &Campaign::scarecrow_get_card);
    QObject::connect(game, &Game::declare_gameWinner, gameWinner_page, &GameWinner::declare);
    QObject::connect(game, &Game::declare_warWinner, warWinner_page, &Winner::declare);

    QObject::connect(this, SIGNAL(getLoadFile()), load_page, SLOT(load()));
    QObject::connect(save_page, &saveGame::data_save, game, &Game::save);
    QObject::connect(warWinner_page, SIGNAL(save()), save_page, SLOT(show()));

    game->load(SAVE_FILE(emit getLoadFile()));
    game->start();

    QObject::disconnect(this, SIGNAL(getLoadFile()), load_page, SLOT(load()));
    QObject::disconnect(save_page, &saveGame::data_save, game, &Game::save);
    QObject::disconnect(warWinner_page, SIGNAL(save()), save_page, SLOT(show()));

    QObject::disconnect(game, &Game::get_players_number, start, &Start::get_players_number);
    QObject::disconnect(game, &Game::get_player_page_show, setplayer, &Setplayer::page_show);
    QObject::disconnect(setplayer, &Setplayer::get_player, game, &Game::get_player);
    QObject::disconnect(game, &Game::set_battleground, battleground_page, &Locateinfo::set_ground );
    QObject::disconnect(game, &Game::set_favorground,  favorground_page,  &Locateinfo::set_ground );
    QObject::disconnect(game, &Game::showPlayerCards, showcards, &showCards::getPlayer);
    QObject::disconnect(game, &Game::showPlayerCards, showcards, &showCards::getPlayer);
    QObject::disconnect(game, &Game::startWar, campaign, &Campaign::startWar);
    QObject::disconnect(game, &Game::getCommand, campaign, &Campaign::getCommand);
    QObject::disconnect(game, &Game::scarecrow_get_card, campaign, &Campaign::scarecrow_get_card);
    QObject::disconnect(game, &Game::declare_gameWinner, gameWinner_page, &GameWinner::declare);
    QObject::disconnect(game, &Game::declare_warWinner, warWinner_page, &Winner::declare);
}

void MainWindow::on_btn_sound_clicked()
{
    static bool enable = true;
    if (enable == true){
        ui->btn_sound->setStyleSheet("border-image:url(:/Description/Graphics/photos/mute.png);background-color:transparent");       // stylesheets of mute button   //path
        player->pause();
        enable = false; 
    }
    else {
        ui->btn_sound->setStyleSheet("border-image:url(:/Description/Graphics/photos/volume.png);background-color:transparent");    // stylesheets of unmute button   //path
        player->play();
        enable = true;
    }
}
