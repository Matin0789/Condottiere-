#ifndef CAMPAIGN_H
#define CAMPAIGN_H


#include <QMainWindow>
#include <QLabel>
#include <QVector>

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

#include <map>

#include "options.h"
#include "Help.h"

#include "enumcolor.h"
#include "purplecard.h"
#include "player.h"



namespace Ui {
class Campaign;
}

class Campaign : public QMainWindow
{
    Q_OBJECT

public:
    explicit Campaign(QWidget *parent = nullptr);
    ~Campaign();
public slots:
    void startWar(const std::vector<Player>&, BattleMarker&, FavorMarker&);
    std::string getCommand(const Player& ,const std::vector<Player*>&,const Card*);
    std::string scarecrow_get_card(const Player&);
private:

    Ui::Campaign *ui;
    Options *options;
    Help *help;
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsRectItem *rect = new QGraphicsRectItem();
    QGraphicsView *view = new QGraphicsView(scene);
    std::map<std::string, QString> cardsImageRef;
    std::map<std::string, QString> markers;
    std::map<std::string, QLabel*> stateLabels;

};

#endif // CAMPAIGN_H
