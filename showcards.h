#ifndef SHOWCARDS_H
#define SHOWCARDS_H

#include <QDialog>

namespace Ui {
class showCards;
}

class showCards : public QDialog
{
    Q_OBJECT

public:
    explicit showCards(QWidget *parent = nullptr);
    ~showCards();

private:
    Ui::showCards *ui;
};

#endif // SHOWCARDS_H
