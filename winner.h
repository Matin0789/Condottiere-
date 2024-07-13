#ifndef WINNER_H
#define WINNER_H

#include <QDialog>

namespace Ui {
class Winner;
}

class Winner : public QDialog
{
    Q_OBJECT

public:
    explicit Winner(QWidget *parent = nullptr);
    ~Winner();

private:
    Ui::Winner *ui;
};

#endif // WINNER_H
