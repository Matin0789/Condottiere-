#ifndef GAMEWINNER_H
#define GAMEWINNER_H

#include <QMainWindow>

namespace Ui {
class GameWinner;
}

class GameWinner : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWinner(QWidget *parent = nullptr);
    ~GameWinner();

private:
    Ui::GameWinner *ui;
};

#endif // GAMEWINNER_H