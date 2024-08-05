#include "campaign.h"
#include "ui_campaign.h"

#include "filepath.h"

Campaign::Campaign(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Campaign)
{
    ui->setupUi(this);

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

    markers["BattleMarker"] = "border-image:url(" + QString(BATTLE_MARKER_IMAGE)  + ")";
    markers["FavorMarker"]  = "border-image:url(" + QString(PEACE_MARKER_IMAGE)   + ")";
    markers[""]             = "border-image:url(" + QString(PLAYER_MARKER_IMAGE)  + ")";

    stateLabels["BELLA"] = ui->lb_bella;
    stateLabels["PLADACI"] = ui->lb_pladaci;
    stateLabels["ROLLO"] = ui->lb_rollo;
    stateLabels["ELINIA"] = ui->lb_elinia;
    stateLabels["CALINE"] = ui->lb_caline;
    stateLabels["BORGE"] = ui->lb_borge;
    stateLabels["OLIVADI"] = ui->lb_olivadi;
    stateLabels["ARMENTO"] = ui->lb_armento;
    stateLabels["TALMONE"] = ui->lb_talmone;
    stateLabels["ENNA"] = ui->lb_enna;
    stateLabels["LIA"] = ui->lb_lia;
    stateLabels["MORINA"] = ui->lb_morina;
    stateLabels["DIMASE"] = ui->lb_dimase;
    stateLabels["ATELA"] = ui->lb_atela;
}

Campaign::~Campaign()
{
    delete ui;
}
