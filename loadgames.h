#ifndef LOADGAMES_H
#define LOADGAMES_H

#include <QMainWindow>
#include <QVector>
#include <QPushButton>

namespace Ui {
class loadGames;
}

class loadGames : public QMainWindow
{
    Q_OBJECT
public:
    explicit loadGames(QWidget *parent = nullptr);
    ~loadGames();
public slots:
    std::string load();
private:
    Ui::loadGames *ui;    //userinterface 
};

#endif // LOADGAMES_H
