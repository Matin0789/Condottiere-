#include "campaign.h"
#include "ui_campaign.h"

#include "filepath.h"

Campaign::Campaign(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Campaign)
{
    ui->setupUi(this);
<<<<<<< HEAD
   // QLabel *NameLabels = new QLabel(this);
   // for (int var = 0; var < total; ++var)
   // {

   // }
=======

    cards["Bishop"]    = "border-image:url(" + BISHOP_IMAGE    + ")";
    cards["Drummer"]   = "border-image:url(" + DRUMMER_IMAGE   + ")";
    cards["Heroine"]   = "border-image:url(" + HEROINE_IMAGE   + ")";
    cards["Scarecrow"] = "border-image:url(" + SCARECROW_IMAGE + ")";
    cards["Spring"]    = "border-image:url(" + SPRING_IMAGE    + ")";
    cards["Winter"]    = "border-image:url(" + WINTER_IMAGE    + ")";
    cards["Spy"]       = "border-image:url(" + SPY_IMAGE       + ")";
    cards["Turncoat"]  = "border-image:url(" + TURNCOAT_IMAGE  + ")";

    markers["BattleMarker"] = "border-image:url(" + BATTLE_MARKER_IMAGE  + ")";
    markers["FavorMarker"]  = "border-image:url(" + PEACE_MARKER_IMAGE   + ")";
    markers[""]             = "border-image:url(" + PLAYER_MARKER_IMAGE  + ")";
>>>>>>> adb8dafbb721fdbea13bd93ec3fe388d0a621499
}

Campaign::~Campaign()
{
    delete ui;
}
