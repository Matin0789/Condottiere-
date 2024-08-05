#include "showcards.h"
#include "ui_showcards.h"
#include "filepath.h"

#include <QColor>

showCards::showCards(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::showCards)
{
    ui->setupUi(this);
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

    cardsImageRef["Bishop"]    = "border-image:url(" + std::string(BISHOP_IMAGE)    + ")";
    cardsImageRef["Drummer"]   = "border-image:url(" + std::string(DRUMMER_IMAGE)   + ")";
    cardsImageRef["Heroine"]   = "border-image:url(" + std::string(HEROINE_IMAGE)   + ")";
    cardsImageRef["Scarecrow"] = "border-image:url(" + std::string(SCARECROW_IMAGE) + ")";
    cardsImageRef["Spring"]    = "border-image:url(" + std::string(SPRING_IMAGE)    + ")";
    cardsImageRef["Winter"]    = "border-image:url(" + std::string(WINTER_IMAGE)    + ")";
    cardsImageRef["Spy"]       = "border-image:url(" + std::string(SPY_IMAGE)       + ")";
    cardsImageRef["Turncoat"]  = "border-image:url(" + std::string(TURNCOAT_IMAGE)  + ")";
    cardsImageRef["1"]         = "border-image:url(" + std::string(ONE_IMAGE)  + ")";
    cardsImageRef["2"]         = "border-image:url(" + std::string(TWO_IMAGE)  + ")";
    cardsImageRef["3"]         = "border-image:url(" + std::string(THREE_IMAGE)  + ")";
    cardsImageRef["4"]         = "border-image:url(" + std::string(FOUR_IMAGE)  + ")";
    cardsImageRef["5"]         = "border-image:url(" + std::string(FIVE_IMAGE)  + ")";
    cardsImageRef["6"]         = "border-image:url(" + std::string(SIX_IMAGE)  + ")";
    cardsImageRef["10"]        = "border-image:url(" + std::string(TEN_IMAGE)  + ")";

}

showCards::~showCards()
{
    delete ui;
}

void showCards::getPlayer(const Player &player)
{
    //QColor playerColor;
    QString lbl_colorStyleSheet;
    switch(player.getColor()) {
    case orange :
        //playerColor.setNamedColor("orange");
        lbl_colorStyleSheet = "QLabel { background-color : orange;}";
        break;
    case blue   :
        //playerColor.setNamedColor("blue");
        lbl_colorStyleSheet = "QLabel { background-color : blue;}";
        break;
    case green  :
        //playerColor.setNamedColor("green");
        lbl_colorStyleSheet = "QLabel { background-color : green;}";
        break;
    case red    :
        //playerColor.setNamedColor("red");
        lbl_colorStyleSheet = "QLabel { background-color : red;}";
        break;
    case gray   :
        //playerColor.setNamedColor("gray");
        lbl_colorStyleSheet = "QLabel { background-color : gray;}";
        break;
    case brown  :
        //playerColor.setNamedColor("brown");
        lbl_colorStyleSheet = "QLabel { background-color : brown;}";
        break;
    default     :
        //playerColor.setNamedColor("white");
        lbl_colorStyleSheet = "QLabel { background-color : white;}";
        break;
    }
    ui->lb_color->setStyleSheet(lbl_colorStyleSheet);

    ui->btn_lets_go->setVisible(false);
    for (auto &&label : cardLabel) {
        label->setStyleSheet("border-image:url(:/Description/Graphics/Assets/zard/Back.png)");
        label->setVisible(false);
    }
    ui->lb_player_counter->setText("Player " + QString::number(player.getID() + 1));
    this->show();

    const std::vector<const Card*>& playerCards = player.getCards();
    for (int i = 0; i < playerCards.size(); ++i) {
        animation.push_back(new QPropertyAnimation(cardLabel[i], "geometry", this));
    }

    QSequentialAnimationGroup group;
    for (int i = 0; i < playerCards.size(); ++i) {
        cardLabel[i]->setVisible(true);
        QRect end(cardLabel[i]->geometry());
        cardLabel[i]->setGeometry(QRect(0 ,0, 0, 0));

        animation[i]->setDuration(300);
        animation[i]->setStartValue(QRect(0 ,0, 0, 0));
        animation[i]->setEndValue(end);
        group.addAnimation(animation[i]);
    }
    group.start();

    QEventLoop loop;
    QObject::connect(&group, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    ui->btn_lets_go->setVisible(true);
    QObject::disconnect(&group, SIGNAL(finished()), &loop, SLOT(quit()));

    QObject::connect(ui->btn_lets_go, SIGNAL(clicked(bool)), &loop, SLOT(quit()));
    loop.exec();
    QObject::disconnect(ui->btn_lets_go, SIGNAL(clicked(bool)), &loop, SLOT(quit()));


    for (int i = 0; i < playerCards.size(); ++i) {
        QRect end(cardLabel[i]->geometry());
        animation[i]->setDuration(300);
        animation[i]->setStartValue(end);
        animation[i]->setEndValue(QRect(end.left() + (end.width()/2), end.top(), 0, end.height()));
        animation[i]->start();
        QEventLoop loop;
        QObject::connect(animation[i], SIGNAL(finished()), &loop, SLOT(quit()));
        loop.exec();
        cardLabel[i]->setStyleSheet(QString::fromStdString(cardsImageRef[playerCards[i]->getType()]));

        animation[i]->setDuration(300);
        animation[i]->setStartValue(QRect(end.left() + (end.width()/2), end.top(), 0, end.height()));
        animation[i]->setEndValue(end);
        animation[i]->start();
    }
    QObject::disconnect(ui->btn_lets_go, SIGNAL(clicked(bool)), &loop, SLOT(quit()));
    ui->btn_lets_go->setVisible(false);
    QObject::connect(ui->btn_Nplayer, SIGNAL(clicked(bool)), &loop, SLOT(quit()));
    loop.exec();
    QObject::disconnect(ui->btn_Nplayer, SIGNAL(clicked(bool)), &loop, SLOT(quit()));

    for (int i = 0; i < playerCards.size(); ++i) {
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
