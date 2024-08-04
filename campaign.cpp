#include "campaign.h"
#include "ui_campaign.h"

#include "filepath.h"

Campaign::Campaign(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Campaign)
{
    ui->setupUi(this);

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

    markers["BattleMarker"] = "border-image:url(" + std::string(BATTLE_MARKER_IMAGE)  + ")";
    markers["FavorMarker"]  = "border-image:url(" + std::string(PEACE_MARKER_IMAGE)   + ")";
    markers[""]             = "border-image:url(" + std::string(PLAYER_MARKER_IMAGE)  + ")";

}

Campaign::~Campaign()
{
    delete ui;
}
