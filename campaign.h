#ifndef CAMPAIGN_H
#define CAMPAIGN_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

#include "options.h"
#include "Helpspage.h"

#include "userinterface.h"
#include "enumcolor.h"
#include "purplecard.h"
#include "player.h"

namespace Ui {
class campaign;
}

class campaign : public QDialog
{
    Q_OBJECT

public:
    explicit campaign(QWidget *parent = nullptr);
    ~campaign();

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
};

#endif // CAMPAIGN_H
