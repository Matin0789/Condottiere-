#include "campaign.h"
#include "ui_campaign.h"

#include "filepath.h"

Campaign::Campaign(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::campaign)
{
    ui->setupUi(this);

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
}

Campaign::~Campaign()
{
    delete ui;
}

void Campaign::on_pb_help_clicked()
{
    hide();
    help = new Help(this);
    help->show();
}

void Campaign::on_pb_setting_clicked()
{
    hide();
    options = new Options(this);
    options->show();
}
