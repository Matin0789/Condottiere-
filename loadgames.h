#ifndef LOADGAMES_H
#define LOADGAMES_H

#include <QMainWindow>

namespace Ui {
class loadGames;
}

class loadGames : public QMainWindow
{
    Q_OBJECT

public:
    explicit loadGames(QWidget *parent = nullptr);
    ~loadGames();

private:
    Ui::loadGames *ui;
};

#endif // LOADGAMES_H
