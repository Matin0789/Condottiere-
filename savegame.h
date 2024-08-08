#ifndef SAVEGAME_H
#define SAVEGAME_H

#include <QMainWindow>

namespace Ui {
class saveGame;
}

class saveGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit saveGame(QWidget *parent = nullptr);
    ~saveGame();

private:
    Ui::saveGame *ui;
};

#endif // SAVEGAME_H
