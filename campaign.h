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

private:

    Ui::Campaign *ui;
    Options *options;
    Help *help;
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsRectItem *rect = new QGraphicsRectItem();
    QGraphicsView *view = new QGraphicsView(scene);
    std::map<std::string, std::string> cards;
    std::map<std::string, std::string> markers;
    //QVector<QLabel*> Nameoflabels;

};

#endif // CAMPAIGN_H
