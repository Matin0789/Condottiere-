#include "shapes.h"
#include "ui_shapes.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

Shapes::Shapes(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Shapes)
{
    ui->setupUi(this);
}

Shapes::~Shapes()
{
    delete ui;
}
