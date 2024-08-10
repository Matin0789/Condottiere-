#ifndef CAMPAIGN_H
#define CAMPAIGN_H


#include <QMainWindow>
#include <QLabel>
#include <QVector>

#include <QDialog>
#include <QGraphicsScene>           // graphic
#include <QGraphicsRectItem>         // rectangle 
#include <QGraphicsView>              // view graphic
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>        // animation
#include <QPropertyAnimation>

#include <map>

#include "options.h"
#include "Help.h"

#include "enumcolor.h"
#include "purplecard.h"
#include "player.h"

#include <QVector>


namespace Ui {
class Campaign;
}

class Campaign : public QMainWindow
{
    Q_OBJECT
signals:
    void checked();        // check signal 
public:
    explicit Campaign(QWidget *parent = nullptr);
    ~Campaign();
public slots:
    void startWar(const std::vector<Player>&, BattleMarker&, FavorMarker&);
    std::string getCommand(const std::vector<Player>&, const Player&, const Card*);
    std::string scarecrow_get_card(const Player&);
private slots:
    void findSelectedCard();
    void on_btn_pass_clicked();

    void on_pushButton_138_clicked();

    void on_pushButton_140_clicked();

private:
    Ui::Campaign *ui;         /// userinterface 
    Options *options;             /// settings 
    Help *help;
    QGraphicsScene *scene = new QGraphicsScene();         /// object of Scene
    QGraphicsRectItem *rect = new QGraphicsRectItem();         /// object of rectangle class  
    QGraphicsView *view = new QGraphicsView(scene);               /// object of graphic view 
    std::map<std::string, QString> cardsImageRef;                /// images
    std::map<std::string, QString> markers;                          /// label of markers 
    std::map<std::string, QLabel*> stateLabels;                       //// label on the states  

    QVector<QVector<QLabel*>> playersCards_lbl;                          /// vector of player cards with label 
    QVector<QLabel*> colors_lbl;                                   /// vector of color of players   with label 
    QVector<QPushButton*> currentPlayerCards_btn;                        // // cards 

    QString command;

    QVector<QPropertyAnimation*> animations;                       /// Animations 
};

#endif // CAMPAIGN_H
