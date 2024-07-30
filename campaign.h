#ifndef CAMPAIGN_H
#define CAMPAIGN_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

#include "options.h"
#include "Help.h"

#include "game.h"
#include "userinterface.h"
#include "enumcolor.h"
#include "purplecard.h"
#include "player.h"


namespace Ui {
class campaign;
}

class Campaign : public QDialog
{
    Q_OBJECT

public:
    explicit Campaign(QWidget *parent = nullptr);
    ~Campaign();

private slots:
    void on_pb_help_clicked();
    void on_pb_setting_clicked();

private:
    Ui::campaign *ui;
        Options *options;
        Help *help;
        QGraphicsScene *scene = new QGraphicsScene();
        QGraphicsRectItem *rect = new QGraphicsRectItem();
        QGraphicsView *view = new QGraphicsView(scene);
        Game *game;
        UserInterface *user;
};

#endif // CAMPAIGN_H
