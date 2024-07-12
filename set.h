#ifndef SET_H
#define SET_H

#include <QDialog>

#include "showcards.h"

namespace Ui {
class Set;
}

class Set : public QDialog
{
    Q_OBJECT

public:
    explicit Set(QWidget *parent = nullptr);
    ~Set();

private slots:


    void on_pb_next_pressed();

private:
    Ui::Set *ui;
    showCards *showcards;
};

#endif // SET_H
