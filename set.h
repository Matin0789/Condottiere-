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
    void on_pushButton_Back_clicked();

    void on_pb_set_next_clicked();

private:
    Ui::Set *ui;
    showCards *showcards;
};

#endif // SET_H
