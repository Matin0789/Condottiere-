#ifndef GAMEWINNER_H
#define GAMEWINNER_H

#include <QMainWindow>
#include<QLabel>

#include "player.h"

namespace Ui {
class GameWinner;
}

class GameWinner : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWinner(QWidget *parent = nullptr);
    ~GameWinner();
public slots:
    void declare(const std::vector<Player>&, const Player&);

private slots:
    void on_pushButton_4_clicked();
    
    void on_pushButton_3_clicked();
private:
    Ui::GameWinner *ui;
    std::map<std::string, QString> markers;
    std::map<std::string, QLabel*> stateLabels;
};

#endif // GAMEWINNER_H
