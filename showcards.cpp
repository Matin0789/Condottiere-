#include "showcards.h"
#include "ui_showcards.h"
#include "filepath.h"

#include <QThread>

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

    for (auto &&label : cardLabel) {
        label->setVisible(false);
    }
    ui->lb_player_counter->setText("Player " + QString::number(player.getID() + 1));
    this->show();

    QEventLoop loop;
    /*QObject::connect(ui->btn_lets_go, SIGNAL(clicked(bool)), &loop, SLOT(quit()));
    loop.exec();
    QObject::disconnect(ui->btn_lets_go, SIGNAL(clicked(bool)), &loop, SLOT(quit()));*/

    const std::vector<const Card*>& playerCards = player.getCards();
    for (int i = 0; i < playerCards.size(); ++i) {
        cardLabel[i]->setStyleSheet(QString::fromStdString(cardsImageRef[playerCards[i]->getType()]));
        cardLabel[i]->setVisible(true);
        QThread::msleep(10);
    }

    QObject::connect(ui->btn_Nplayer, SIGNAL(clicked(bool)), &loop, SLOT(quit()));
    loop.exec();
    QObject::disconnect(ui->btn_Nplayer, SIGNAL(clicked(bool)), &loop, SLOT(quit()));
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
