#ifndef CAMPAIGN_H
#define CAMPAIGN_H

<<<<<<< HEAD
#include <QMainWindow>
#include <QLabel>
#include <QVector>
=======
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

#include <map>

#include "options.h"
#include "Help.h"

#include "game.h"
#include "userinterface.h"
#include "enumcolor.h"
#include "purplecard.h"
#include "player.h"
>>>>>>> adb8dafbb721fdbea13bd93ec3fe388d0a621499


namespace Ui {
class Campaign;
}

class Campaign : public QMainWindow
{
    Q_OBJECT

public:
    explicit Campaign(QWidget *parent = nullptr);
    ~Campaign();

private:
<<<<<<< HEAD
    Ui::Campaign *ui;
    //QVector<QLabel*> Nameoflabels;

=======
    Ui::campaign *ui;
        Options *options;
        Help *help;
        QGraphicsScene *scene = new QGraphicsScene();
        QGraphicsRectItem *rect = new QGraphicsRectItem();
        QGraphicsView *view = new QGraphicsView(scene);
        Game *game;
        UserInterface *user;
        map<std::string, std::string> cards;
        map<std::string, std::string> markers;
>>>>>>> adb8dafbb721fdbea13bd93ec3fe388d0a621499
};

#endif // CAMPAIGN_H
