#ifndef START_H
#define START_H

#include <QDialog>
#include <limits>
#include <vector>
#include "game.h"
#include "userinterface.h"
#include "controller.h"
#include "setplayer.h"

namespace Ui {
class Start;
}

class Start : public QDialog
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = nullptr);
    ~Start();
public slots:
    void get_player(std::string, size_t, Color);
signals:
    void set_player(std::string, size_t, Color);
    void end();
private slots:

    void on_btn_next_clicked();

    void on_btn_back_clicked();

    //void on_le_number_cursorPositionChanged(int arg1);

private:
    Ui::Start *ui;
    Setplayer *setplayer;
    size_t playersNumber;
    size_t playerID;
    std::vector<std::pair<QString, Color>> freeColors;
};

#endif // START_H
