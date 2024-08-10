#include "showcards.h"
#include "ui_showcards.h"
#include "filepath.h"

#include <QColor>

showCards::showCards(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::showCards)
{
    ui->setupUi(this);          ////  this code for add label of cards to my vector
    this->cardLabel.push_back(ui->lb_card_1);     
    this->cardLabel.push_back(ui->lb_card_2);
    this->cardLabel.push_back(ui->lb_card_3);
    this->cardLabel.push_back(ui->lb_card_4);
    this->cardLabel.push_back(ui->lb_card_5);
    this->cardLabel.push_back(ui->lb_card_6);
    this->cardLabel.push_back(ui->lb_card_7);
    this->cardLabel.push_back(ui->lb_card_8);
    this->cardLabel.push_back(ui->lb_card_9);
    this->cardLabel.push_back(ui->lb_card_10);
    this->cardLabel.push_back(ui->lb_card_11);
    this->cardLabel.push_back(ui->lb_card_12);
    this->cardLabel.push_back(ui->lb_card_13);
    this->cardLabel.push_back(ui->lb_card_14);
 ///////
   //// set photo of cards 
    cardsImageRef["Bishop"]    = "border-image:url(" + std::string(BISHOP_IMAGE)    + ")";
    cardsImageRef["Drummer"]   = "border-image:url(" + std::string(DRUMMER_IMAGE)   + ")";
    cardsImageRef["Heroine"]   = "border-image:url(" + std::string(HEROINE_IMAGE)   + ")";
    cardsImageRef["Scarecrow"] = "border-image:url(" + std::string(SCARECROW_IMAGE) + ")";
    cardsImageRef["Spring"]    = "border-image:url(" + std::string(SPRING_IMAGE)    + ")";
    cardsImageRef["Winter"]    = "border-image:url(" + std::string(WINTER_IMAGE)    + ")";
    cardsImageRef["Spy"]       = "border-image:url(" + std::string(SPY_IMAGE)       + ")";
    cardsImageRef["Turncoat"]  = "border-image:url(" + std::string(TURNCOAT_IMAGE)  + ")";
    cardsImageRef["WhiteRakhsh"] = "border-image:url(" + std::string(WHITERAKHSH_IMAGE) + ")";           //This code is related to phase 3 of the project
    cardsImageRef["WhiteSeals"] = "border-image:url(" + std::string(WHITESEALS_IMAGE) + ")";            //This code is related to phase 3 of the project
    cardsImageRef["ShirinAghl"] = "border-image:url(" + std::string(SHIRINAGHL_IMAGE) + ")";           //This code is related to phase 3 of the project
    cardsImageRef["1"]         = "border-image:url(" + std::string(ONE_IMAGE)  + ")";
    cardsImageRef["2"]         = "border-image:url(" + std::string(TWO_IMAGE)  + ")";
    cardsImageRef["3"]         = "border-image:url(" + std::string(THREE_IMAGE)  + ")";
    cardsImageRef["4"]         = "border-image:url(" + std::string(FOUR_IMAGE)  + ")";
    cardsImageRef["5"]         = "border-image:url(" + std::string(FIVE_IMAGE)  + ")";
    cardsImageRef["6"]         = "border-image:url(" + std::string(SIX_IMAGE)  + ")";
    cardsImageRef["10"]        = "border-image:url(" + std::string(TEN_IMAGE)  + ")";

    // set animation object
    audioPlayer = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    audioPlayer->setAudioOutput(audioOutput);
    audioPlayer->setSource(QUrl::fromLocalFile("../../Description/Graphics/Sounds/distribute.mp3"));  // sound of game 
    audioOutput->setVolume(100);
    audioPlayer->setLoops(QMediaPlayer::Infinite);  // pause
    audioPlayer->setPlaybackRate(3.0);
}

// distructor
showCards::~showCards()
{
    delete ui;
    delete audioOutput;
    delete audioPlayer;
}

    // this function is for set player informations

void showCards::getPlayer(const Player &player)
{ 
    ui->lb_color->setStyleSheet("QLabel { background-color : " + QString::fromStdString(player.getColor()) +";}");  // set color player

    ui->btn_lets_go->setVisible(false);
    for (auto &&label : cardLabel) {
        label->setStyleSheet("border-image:url(:/Description/Graphics/Assets/zard/Back.png)");   // path of yellow cards 
        label->setVisible(false);
    }
    ui->lb_player_counter->setText("Player " + QString::number(player.getID() + 1));  // players id
    this->show();

    const std::vector<const Card*>& playerCards = player.getCards();    // sent cards by function of player class
    for (int i = 0; i < playerCards.size(); ++i) {
        animation.push_back(new QPropertyAnimation(cardLabel[i], "geometry", this));
    }
   
      // set animation for show cards    
    QSequentialAnimationGroup group;
    for (int i = 0; i < playerCards.size(); ++i) {
        cardLabel[i]->setVisible(true);
        QRect end(cardLabel[i]->geometry());
        cardLabel[i]->setGeometry(QRect(0 ,0, 0, 0));             // ///  animation for show cards 
 
        animation[i]->setDuration(200);
        animation[i]->setStartValue(QRect(0 ,0, 0, 0));           // ///  animation for show cards 
        animation[i]->setEndValue(end);
        group.addAnimation(animation[i]);

    }

    QObject::connect(&group, SIGNAL(finished()), audioPlayer, SLOT(stop()));       ///signal and slots 
    QEventLoop loop;
    QObject::connect(&group, SIGNAL(finished()), &loop, SLOT(quit()));           /// signal and slots
    audioPlayer->play();
    group.start();
    loop.exec();
    ui->btn_lets_go->setVisible(true);                      //change page  
    QObject::disconnect(&group, SIGNAL(finished()), &loop, SLOT(quit()));           /// signal and slots
    QObject::disconnect(&group, SIGNAL(finished()), audioPlayer, SLOT(stop()));        /// signal and slots
    QObject::connect(ui->btn_lets_go, SIGNAL(clicked(bool)), &loop, SLOT(quit()));
    loop.exec();
    QObject::disconnect(ui->btn_lets_go, SIGNAL(clicked(bool)), &loop, SLOT(quit())); /// signal and slots


    for (int i = 0; i < playerCards.size(); ++i) {
        QRect end(cardLabel[i]->geometry());
        animation[i]->setDuration(200);               // speed of show cards 
        animation[i]->setStartValue(end);        //time 
        animation[i]->setEndValue(QRect(end.left() + (end.width()/2), end.top(), 0, end.height()));
        animation[i]->start();
        QEventLoop loop;
        QObject::connect(animation[i], SIGNAL(finished()), &loop, SLOT(quit()));
        loop.exec();
        cardLabel[i]->setStyleSheet(QString::fromStdString(cardsImageRef[playerCards[i]->getType()]));

        animation[i]->setDuration(200);
        animation[i]->setStartValue(QRect(end.left() + (end.width()/2), end.top(), 0, end.height()));
        animation[i]->setEndValue(end);
        animation[i]->start();
    }
    QObject::disconnect(ui->btn_lets_go, SIGNAL(clicked(bool)), &loop, SLOT(quit()));
    ui->btn_lets_go->setVisible(false);
    QObject::connect(ui->btn_Nplayer, SIGNAL(clicked(bool)), &loop, SLOT(quit()));          /// signal and slots
    loop.exec();
    QObject::disconnect(ui->btn_Nplayer, SIGNAL(clicked(bool)), &loop, SLOT(quit()));  /// signal and slots

    for (int i = 0; i < playerCards.size(); ++i) {      /// this loop for end of animations cards 
        delete animation[i];
    }
    animation.clear();
    this->hide();
}

void showCards::on_btn_Nplayer_clicked()
{

}

void showCards::on_cb_show_player_list_activated(int index)
{

}

void showCards::on_btn_lets_go_clicked()
{

}
