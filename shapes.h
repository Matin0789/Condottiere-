#ifndef SHAPES_H
#define SHAPES_H

#include <QDialog>

#include "enumcolor.h"
#include "purplecard.h"
#include "userinterface.h"

namespace Ui {
class Shapes;
}

class Shapes : public QDialog
{
    Q_OBJECT

public:
    explicit Shapes(QWidget *parent = nullptr);
    ~Shapes();

private:
    Ui::Shapes *ui;
    enumcolor *color;  // marker colors
    PurpleCard *purplecard;         // cards
    UserInterface *userinterface;         // ui
};

#endif // SHAPES_H
