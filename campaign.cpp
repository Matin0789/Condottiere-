#include "campaign.h"
#include "ui_campaign.h"

#include "filepath.h"

Campaign::Campaign(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Campaign)
{
    ui->setupUi(this);

   // QLabel *NameLabels = new QLabel(this);
   // for (int var = 0; var < total; ++var)
   // {

   // }


    cards["Bishop"]    = "border-image:url(" + std::string(BISHOP_IMAGE)    + ")";
    cards["Drummer"]   = "border-image:url(" + std::string(DRUMMER_IMAGE)   + ")";
    cards["Heroine"]   = "border-image:url(" + std::string(HEROINE_IMAGE)   + ")";
    cards["Scarecrow"] = "border-image:url(" + std::string(SCARECROW_IMAGE) + ")";
    cards["Spring"]    = "border-image:url(" + std::string(SPRING_IMAGE)    + ")";
    cards["Winter"]    = "border-image:url(" + std::string(WINTER_IMAGE)    + ")";
    cards["Spy"]       = "border-image:url(" + std::string(SPY_IMAGE)       + ")";
    cards["Turncoat"]  = "border-image:url(" + std::string(TURNCOAT_IMAGE)  + ")";

    markers["BattleMarker"] = "border-image:url(" + std::string(BATTLE_MARKER_IMAGE)  + ")";
    markers["FavorMarker"]  = "border-image:url(" + std::string(PEACE_MARKER_IMAGE)   + ")";
    markers[""]             = "border-image:url(" + std::string(PLAYER_MARKER_IMAGE)  + ")";

}

Campaign::~Campaign()
{
    delete ui;
}
