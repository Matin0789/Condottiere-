#include "campaign.h"
#include "ui_campaign.h"

#include "filepath.h"

Campaign::Campaign(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Campaign)
    , options(new Options(this))
    , help(new Help(this))
{
    ui->setupUi(this);

    connect(options , SIGNAL(muteAudio()), qobject_cast<QMainWindow*>(parent), SLOT(on_btn_sound_clicked()));
    connect(options , SIGNAL(loadGame()), qobject_cast<QMainWindow*>(parent), SLOT(on_btn_load_game_clicked()));

    cardsImageRef["Bishop"]    = "border-image:url(" + QString(BISHOP_IMAGE)    + ")";
    cardsImageRef["Drummer"]   = "border-image:url(" + QString(DRUMMER_IMAGE)   + ")";
    cardsImageRef["Heroine"]   = "border-image:url(" + QString(HEROINE_IMAGE)   + ")";
    cardsImageRef["Scarecrow"] = "border-image:url(" + QString(SCARECROW_IMAGE) + ")";
    cardsImageRef["Spring"]    = "border-image:url(" + QString(SPRING_IMAGE)    + ")";
    cardsImageRef["Winter"]    = "border-image:url(" + QString(WINTER_IMAGE)    + ")";
    cardsImageRef["Spy"]       = "border-image:url(" + QString(SPY_IMAGE)       + ")";
    cardsImageRef["Turncoat"]  = "border-image:url(" + QString(TURNCOAT_IMAGE)  + ")";
    cardsImageRef["1"]         = "border-image:url(" + QString(ONE_IMAGE)  + ")";
    cardsImageRef["2"]         = "border-image:url(" + QString(TWO_IMAGE)  + ")";
    cardsImageRef["3"]         = "border-image:url(" + QString(THREE_IMAGE)  + ")";
    cardsImageRef["4"]         = "border-image:url(" + QString(FOUR_IMAGE)  + ")";
    cardsImageRef["5"]         = "border-image:url(" + QString(FIVE_IMAGE)  + ")";
    cardsImageRef["6"]         = "border-image:url(" + QString(SIX_IMAGE)  + ")";
    cardsImageRef["10"]        = "border-image:url(" + QString(TEN_IMAGE)  + ")";


    markers["BattleMarker"] = "border-image:url(" + QString(BATTLE_MARKER_IMAGE)  + ");" + " background-color:transparent";
    markers["FavorMarker"]  = "border-image:url(" + QString(PEACE_MARKER_IMAGE)   + ");" + " background-color:transparent";
    markers["blue"]         = "border-image:url(" + QString(PLAYER_BLUE_MARKER_IMAGE)  + ");" + " background-color:transparent";
    markers["green"]        = "border-image:url(" + QString(PLAYER_GREEN_MARKER_IMAGE)  + ");" + " background-color:transparent";
    markers["red"]          = "border-image:url(" + QString(PLAYER_RED_MARKER_IMAGE)  + ");" + " background-color:transparent";
    markers["orange"]       = "border-image:url(" + QString(PLAYER_ORANGE_MARKER_IMAGE)  + ");" + " background-color:transparent";
    markers["gray"]         = "border-image:url(" + QString(PLAYER_GRAY_MARKER_IMAGE)  + ");" + " background-color:transparent";
    markers["brown"]        = "border-image:url(" + QString(PLAYER_BROWN_MARKER_IMAGE)  + ");" + " background-color:transparent";

    stateLabels["HAMEDAN"] = ui->lb_hamedan;  //This code is related to phase 3 of the project
    stateLabels["BELLA"] = ui->lb_bella;
    stateLabels["PLADACI"] = ui->lb_pladaci;
    stateLabels["ROLLO"] = ui->lb_rollo;
    stateLabels["ELINIA"] = ui->lb_elinia;
    stateLabels["CALINE"] = ui->lb_caline;
    stateLabels["BORGE"] = ui->lb_borge;
    stateLabels["OLIVADI"] = ui->lb_olivadi;
    stateLabels["ARMENTO"] = ui->lb_armento;
    stateLabels["TALMONE"] = ui->lb_talmone;
    stateLabels["ENNA"] = ui->lb_lia;      //This code is related to phase 3 of the project    //ui->lb_enna
    stateLabels["LIA"] = ui->lb_enna;        //This code is related to phase 3 of the project  //ui->lb_lia
    stateLabels["MORINA"] = ui->lb_morina;
    stateLabels["DIMASE"] = ui->lb_dimase;
    stateLabels["ATELA"] = ui->lb_atela;

    colors_lbl.push_back(ui->lb_player_1);
    colors_lbl.push_back(ui->lb_player_2);
    colors_lbl.push_back(ui->lb_player_3);
    colors_lbl.push_back(ui->lb_player_4);
    colors_lbl.push_back(ui->lb_player_5);
    colors_lbl.push_back(ui->lb_player_6);

    QVector<QLabel*> tmpPlayer1Cards;
    QVector<QLabel*> tmpPlayer2Cards;
    QVector<QLabel*> tmpPlayer3Cards;
    QVector<QLabel*> tmpPlayer4Cards;
    QVector<QLabel*> tmpPlayer5Cards;
    QVector<QLabel*> tmpPlayer6Cards;

    tmpPlayer1Cards.push_back(ui->lb_plr_1_cd_1);
    tmpPlayer1Cards.push_back(ui->lb_plr_1_cd_2);
    tmpPlayer1Cards.push_back(ui->lb_plr_1_cd_3);
    tmpPlayer1Cards.push_back(ui->lb_plr_1_cd_4);
    tmpPlayer1Cards.push_back(ui->lb_plr_1_cd_5);
    tmpPlayer1Cards.push_back(ui->lb_plr_1_cd_6);
    tmpPlayer1Cards.push_back(ui->lb_plr_1_cd_7);
    tmpPlayer1Cards.push_back(ui->lb_plr_1_cd_8);
    tmpPlayer1Cards.push_back(ui->lb_plr_1_cd_9);
    tmpPlayer1Cards.push_back(ui->lb_plr_1_cd_10);
    tmpPlayer1Cards.push_back(ui->lb_plr_1_cd_11);
    tmpPlayer1Cards.push_back(ui->lb_plr_1_cd_12);
    tmpPlayer1Cards.push_back(ui->lb_plr_1_cd_13);
    tmpPlayer1Cards.push_back(ui->lb_plr_1_cd_14);

    tmpPlayer2Cards.push_back(ui->lb_plr_2_cd_1);
    tmpPlayer2Cards.push_back(ui->lb_plr_2_cd_2);
    tmpPlayer2Cards.push_back(ui->lb_plr_2_cd_3);
    tmpPlayer2Cards.push_back(ui->lb_plr_2_cd_4);
    tmpPlayer2Cards.push_back(ui->lb_plr_2_cd_5);
    tmpPlayer2Cards.push_back(ui->lb_plr_2_cd_6);
    tmpPlayer2Cards.push_back(ui->lb_plr_2_cd_7);
    tmpPlayer2Cards.push_back(ui->lb_plr_2_cd_8);
    tmpPlayer2Cards.push_back(ui->lb_plr_2_cd_9);
    tmpPlayer2Cards.push_back(ui->lb_plr_2_cd_10);
    tmpPlayer2Cards.push_back(ui->lb_plr_2_cd_11);
    tmpPlayer2Cards.push_back(ui->lb_plr_2_cd_12);
    tmpPlayer2Cards.push_back(ui->lb_plr_2_cd_13);
    tmpPlayer2Cards.push_back(ui->lb_plr_2_cd_14);

    tmpPlayer3Cards.push_back(ui->lb_plr_3_cd_1);
    tmpPlayer3Cards.push_back(ui->lb_plr_3_cd_2);
    tmpPlayer3Cards.push_back(ui->lb_plr_3_cd_3);
    tmpPlayer3Cards.push_back(ui->lb_plr_3_cd_4);
    tmpPlayer3Cards.push_back(ui->lb_plr_3_cd_5);
    tmpPlayer3Cards.push_back(ui->lb_plr_3_cd_6);
    tmpPlayer3Cards.push_back(ui->lb_plr_3_cd_7);
    tmpPlayer3Cards.push_back(ui->lb_plr_3_cd_8);
    tmpPlayer3Cards.push_back(ui->lb_plr_3_cd_9);
    tmpPlayer3Cards.push_back(ui->lb_plr_3_cd_10);
    tmpPlayer3Cards.push_back(ui->lb_plr_3_cd_11);
    tmpPlayer3Cards.push_back(ui->lb_plr_3_cd_12);
    tmpPlayer3Cards.push_back(ui->lb_plr_3_cd_13);
    tmpPlayer3Cards.push_back(ui->lb_plr_3_cd_14);

    tmpPlayer4Cards.push_back(ui->lb_plr_4_cd_1);
    tmpPlayer4Cards.push_back(ui->lb_plr_4_cd_2);
    tmpPlayer4Cards.push_back(ui->lb_plr_4_cd_3);
    tmpPlayer4Cards.push_back(ui->lb_plr_4_cd_4);
    tmpPlayer4Cards.push_back(ui->lb_plr_4_cd_5);
    tmpPlayer4Cards.push_back(ui->lb_plr_4_cd_6);
    tmpPlayer4Cards.push_back(ui->lb_plr_4_cd_7);
    tmpPlayer4Cards.push_back(ui->lb_plr_4_cd_8);
    tmpPlayer4Cards.push_back(ui->lb_plr_4_cd_9);
    tmpPlayer4Cards.push_back(ui->lb_plr_4_cd_10);
    tmpPlayer4Cards.push_back(ui->lb_plr_4_cd_11);
    tmpPlayer4Cards.push_back(ui->lb_plr_4_cd_12);
    tmpPlayer4Cards.push_back(ui->lb_plr_4_cd_13);
    tmpPlayer4Cards.push_back(ui->lb_plr_4_cd_14);

    tmpPlayer5Cards.push_back(ui->lb_plr_5_cd_1);
    tmpPlayer5Cards.push_back(ui->lb_plr_5_cd_2);
    tmpPlayer5Cards.push_back(ui->lb_plr_5_cd_3);
    tmpPlayer5Cards.push_back(ui->lb_plr_5_cd_4);
    tmpPlayer5Cards.push_back(ui->lb_plr_5_cd_5);
    tmpPlayer5Cards.push_back(ui->lb_plr_5_cd_6);
    tmpPlayer5Cards.push_back(ui->lb_plr_5_cd_7);
    tmpPlayer5Cards.push_back(ui->lb_plr_5_cd_8);
    tmpPlayer5Cards.push_back(ui->lb_plr_5_cd_9);
    tmpPlayer5Cards.push_back(ui->lb_plr_5_cd_10);
    tmpPlayer5Cards.push_back(ui->lb_plr_5_cd_11);
    tmpPlayer5Cards.push_back(ui->lb_plr_5_cd_12);
    tmpPlayer5Cards.push_back(ui->lb_plr_5_cd_13);
    tmpPlayer5Cards.push_back(ui->lb_plr_5_cd_14);

    tmpPlayer6Cards.push_back(ui->lb_plr_6_cd_1);
    tmpPlayer6Cards.push_back(ui->lb_plr_6_cd_2);
    tmpPlayer6Cards.push_back(ui->lb_plr_6_cd_3);
    tmpPlayer6Cards.push_back(ui->lb_plr_6_cd_4);
    tmpPlayer6Cards.push_back(ui->lb_plr_6_cd_5);
    tmpPlayer6Cards.push_back(ui->lb_plr_6_cd_6);
    tmpPlayer6Cards.push_back(ui->lb_plr_6_cd_7);
    tmpPlayer6Cards.push_back(ui->lb_plr_6_cd_8);
    tmpPlayer6Cards.push_back(ui->lb_plr_6_cd_9);
    tmpPlayer6Cards.push_back(ui->lb_plr_6_cd_10);
    tmpPlayer6Cards.push_back(ui->lb_plr_6_cd_11);
    tmpPlayer6Cards.push_back(ui->lb_plr_6_cd_12);
    tmpPlayer6Cards.push_back(ui->lb_plr_6_cd_13);
    tmpPlayer6Cards.push_back(ui->lb_plr_6_cd_14);

    playersCards_lbl.push_back(tmpPlayer1Cards);
    playersCards_lbl.push_back(tmpPlayer2Cards);
    playersCards_lbl.push_back(tmpPlayer3Cards);
    playersCards_lbl.push_back(tmpPlayer4Cards);
    playersCards_lbl.push_back(tmpPlayer5Cards);
    playersCards_lbl.push_back(tmpPlayer6Cards);

    currentPlayerCards_btn.push_back(ui->btn_card_1);
    currentPlayerCards_btn.push_back(ui->btn_card_2);
    currentPlayerCards_btn.push_back(ui->btn_card_3);
    currentPlayerCards_btn.push_back(ui->btn_card_4);
    currentPlayerCards_btn.push_back(ui->btn_card_5);
    currentPlayerCards_btn.push_back(ui->btn_card_6);
    currentPlayerCards_btn.push_back(ui->btn_card_7);
    currentPlayerCards_btn.push_back(ui->btn_card_8);
    currentPlayerCards_btn.push_back(ui->btn_card_9);
    currentPlayerCards_btn.push_back(ui->btn_card_10);
    currentPlayerCards_btn.push_back(ui->btn_card_11);
    currentPlayerCards_btn.push_back(ui->btn_card_12);
    currentPlayerCards_btn.push_back(ui->btn_card_13);
    currentPlayerCards_btn.push_back(ui->btn_card_14);

}

Campaign::~Campaign()
{
    disconnect(options, SIGNAL(loadGame()), qobject_cast<QMainWindow*>(parent()), SLOT(on_btn_load_game_clicked()));
    disconnect(options, SIGNAL(muteAudio()), qobject_cast<QMainWindow*>(parent()), SLOT(on_btn_sound_clicked()));
    delete ui;
}

void Campaign::startWar(const std::vector<Player> &players, BattleMarker & battleMarker, FavorMarker & favorMarker)
{
    this->show();
    for(auto &&label : stateLabels) {
        label.second->setVisible(false);
        label.second->setStyleSheet("");
    }
    for (auto &&player : players) {
        for (auto &&state_name : player.get_states_name()) {
            stateLabels[state_name]->setVisible(true);
            stateLabels[state_name]->setStyleSheet(markers[player.getColor()]);
        }
    }
    stateLabels[battleMarker.getState().getName()]->setStyleSheet(markers["BattleMarker"]);
    stateLabels[battleMarker.getState().getName()]->setVisible(true);
    if (favorMarker.is_set()) {
        stateLabels[favorMarker.getState().getName()]->setStyleSheet(markers["FavorMarker"]);
        stateLabels[favorMarker.getState().getName()]->setVisible(true);
    }
}

std::string Campaign::getCommand(const std::vector<Player>& players, const Player & currentPlayer, const Card * season)
{
    ui->btn_showCards->setVisible(false);
    command = "";
    ui->lb_season->setVisible(false);
    ui->lb_season->setStyleSheet("");
    for(auto && currentPlayerCard_lbl :currentPlayerCards_btn) {
        currentPlayerCard_lbl->setVisible(false);
        currentPlayerCard_lbl->setStyleSheet("");
        currentPlayerCard_lbl->setText("");
    }
    for (int i = 0; i < colors_lbl.size(); i++) {
        colors_lbl[i]->setVisible(false);
        colors_lbl[i]->setStyleSheet("");
        for (auto &&card_lbl : playersCards_lbl[i]) {
            card_lbl->setVisible(false);
            card_lbl->setStyleSheet("");
            card_lbl->setText("");
        }
    }

    if (season) {
        ui->lb_season->setVisible(true);
        if (season->getType() == "Winter") {
            ui->lb_season->setStyleSheet(cardsImageRef["Winter"]);
        }
        else {
            ui->lb_season->setStyleSheet(cardsImageRef["Spring"]);
        }
    }

    for (int i = 0; i < players.size(); i++) {
        colors_lbl[i]->setVisible(true);
        colors_lbl[i]->setStyleSheet("QLabel { background-color : " + QString::fromStdString(players[i].getColor()) +";}");
        std::vector<const Card*> playerCard = players[i].getCards();
        for (int j = 0; j < playerCard.size(); j++) {
            playersCards_lbl[i][j]->setVisible(true);
            playersCards_lbl[i][j]->setStyleSheet("border-image:url(" + QString(BACK_IMAGE) + ")");
        }
        std::vector<const Card*> playerPlayedCard = players[i].getPlayedCards();
        for (int j = 0; j < playerPlayedCard.size(); j++) {
            playersCards_lbl[i][j + playerCard.size()]->setVisible(true);
            playersCards_lbl[i][j + playerCard.size()]->setStyleSheet(cardsImageRef[playerPlayedCard[j]->getType()]);
        }
    }

    QParallelAnimationGroup group;
    ui->lb_player->setStyleSheet("QLabel { background-color : " + QString::fromStdString(currentPlayer.getColor()) +";}");
    //
    std::vector<const Card*> currentPlayerPlayedCard = currentPlayer.getPlayedCards();
    for (int i = 0; i < currentPlayerPlayedCard.size(); i++) {
        currentPlayerCards_btn[i]->setVisible(true);
        currentPlayerCards_btn[i]->setStyleSheet(cardsImageRef[currentPlayerPlayedCard[i]->getType()]);
        currentPlayerCards_btn[i]->setText("PLAYED");
        animations.push_back(new QPropertyAnimation(currentPlayerCards_btn[i], "geometry", this));
        QRect end(currentPlayerCards_btn[i]->geometry());
        currentPlayerCards_btn[i]->setGeometry(currentPlayerCards_btn[0]->geometry());

        animations[i]->setDuration(400);
        animations[i]->setStartValue(currentPlayerCards_btn[0]->geometry());
        animations[i]->setEndValue(end);
        group.addAnimation(animations[i]);
    }
    std::vector<const Card*> currentPlayerCard = currentPlayer.getCards();
    for (int i = 0; i < currentPlayerCard.size(); i++) {
        currentPlayerCards_btn[i + currentPlayerPlayedCard.size()]->setVisible(true);
        currentPlayerCards_btn[i + currentPlayerPlayedCard.size()]->setStyleSheet(
            "border-image:url(" + QString(BACK_IMAGE) + ")");
        animations.push_back(new QPropertyAnimation(currentPlayerCards_btn[i + currentPlayerPlayedCard.size()], "geometry", this));
        QRect end(currentPlayerCards_btn[i + currentPlayerPlayedCard.size()]->geometry());
        currentPlayerCards_btn[i + currentPlayerPlayedCard.size()]->setGeometry(currentPlayerCards_btn[0]->geometry());

        animations[i + currentPlayerPlayedCard.size()]->setDuration(400);
        animations[i + currentPlayerPlayedCard.size()]->setStartValue(currentPlayerCards_btn[0]->geometry());
        animations[i + currentPlayerPlayedCard.size()]->setEndValue(end);
        group.addAnimation(animations[i + currentPlayerPlayedCard.size()]);
    }
    //
    QEventLoop loop;
    QObject::connect(&group, SIGNAL(finished()), &loop, SLOT(quit()));
    group.start();
    loop.exec();
    ui->btn_showCards->setVisible(true);
    QObject::disconnect(&group, SIGNAL(finished()), &loop, SLOT(quit()));
    QObject::connect(ui->btn_showCards, SIGNAL(clicked(bool)), &loop, SLOT(quit()));
    loop.exec();
    QObject::disconnect(ui->btn_showCards, SIGNAL(clicked(bool)), &loop, SLOT(quit()));

    for(auto &&animation : animations)
        delete animation;
    animations.clear();

    for (int i = 0; i < currentPlayerCard.size(); i++) {
        animations.push_back(new QPropertyAnimation(currentPlayerCards_btn[i + currentPlayerPlayedCard.size()], "geometry", this));
        QRect end(currentPlayerCards_btn[i + currentPlayerPlayedCard.size()]->geometry());
        animations[i]->setDuration(200);
        animations[i]->setStartValue(end);
        animations[i]->setEndValue(QRect(end.left() + (end.width()/2), end.top(), 0, end.height()));
        animations[i]->start();

        QObject::connect(animations[i], SIGNAL(finished()), &loop, SLOT(quit()));
        loop.exec();
        QObject::disconnect(animations[i], SIGNAL(finished()), &loop, SLOT(quit()));

        currentPlayerCards_btn[i + currentPlayerPlayedCard.size()]->setStyleSheet(cardsImageRef[currentPlayerCard[i]->getType()]);
        connect(currentPlayerCards_btn[i + currentPlayerPlayedCard.size()], SIGNAL(clicked(bool)), this, SLOT(findSelectedCard()));

        animations[i]->setDuration(200);
        animations[i]->setStartValue(QRect(end.left() + (end.width()/2), end.top(), 0, end.height()));
        animations[i]->setEndValue(end);
        animations[i]->start();
    }
    ui->btn_showCards->setVisible(false);


    connect(this, SIGNAL(checked()), &loop, SLOT(quit()));
    loop.exec();
    for (auto &&currentPlayerCard_lbl : currentPlayerCards_btn) {
        disconnect(currentPlayerCard_lbl, SIGNAL(clicked(bool)), this, SLOT(findSelectedCard()));
    }
    disconnect(this, SIGNAL(checked()), &loop, SLOT(quit()));

    for(auto &&animation : animations)
        delete animation;
    animations.clear();

    return command.toStdString();
}

std::string Campaign::scarecrow_get_card(const Player & currentPlayer)
{
    command = "";
    for(auto && currentPlayerCard_lbl :currentPlayerCards_btn) {
        currentPlayerCard_lbl->setVisible(false);
        currentPlayerCard_lbl->setStyleSheet("");
        currentPlayerCard_lbl->setText("");
    }

    std::vector<const Card*> currentPlayerPlayedCard = currentPlayer.getPlayedCards();
    bool flag = false;
    for (int i = 0; i < currentPlayerPlayedCard.size(); i++) {
        if(currentPlayerPlayedCard[i]->getType()[0] >= '0' && currentPlayerPlayedCard[i]->getType()[0] <= '9')
        {
            currentPlayerCards_btn[i]->setVisible(true);
            currentPlayerCards_btn[i]->setStyleSheet(cardsImageRef[currentPlayerPlayedCard[i]->getType()]);
            connect(currentPlayerCards_btn[i], SIGNAL(clicked(bool)), this, SLOT(findSelectedCard()));
            flag = true;
        }
    }
    if (flag == true){
        QEventLoop loop;
        connect(this, SIGNAL(checked()), &loop, SLOT(quit()));
        loop.exec();
        for (auto &&currentPlayerCard_lbl : currentPlayerCards_btn) {
            disconnect(currentPlayerCard_lbl, SIGNAL(clicked(bool)), this, SLOT(findSelectedCard()));
        }
        disconnect(this, SIGNAL(checked()), &loop, SLOT(quit()));

    }
    else {
        command = "";
    }
    return command.toStdString();
}

void Campaign::findSelectedCard()
{
    QString check = qobject_cast<QPushButton*>(sender())->styleSheet();
    for(auto&& cardImageRef : cardsImageRef) {
        if (check == cardImageRef.second) {
            command = QString::fromStdString(cardImageRef.first);
            emit checked();
            return ;
        }
    }
}

void Campaign::on_btn_pass_clicked()
{
    command = "pass";
    emit checked();
}


void Campaign::on_pushButton_138_clicked()
{
    this->hide();
    help->show();
}


void Campaign::on_pushButton_140_clicked()
{
    this->hide();
    options->show();
}

