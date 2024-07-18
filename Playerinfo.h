#ifndef PLAYERINFO_H
#define PLAYERINFO_H

#include <QDialog>
#include <string>

#include "showcards.h"
#include "enumcolor.h"


namespace Ui {
class PlayerInfo;
}

class Playerinfo : public QDialog
{
    Q_OBJECT

public:
    explicit Playerinfo(QWidget *parent = nullptr);
    ~Playerinfo();

signals:
    void get_player_name(std::string);
    void get_player_old(size_t);
    void get_player_color(Color);

private slots:
    void on_btn_next_clicked();
    void on_btn_back_clicked();

private:
    Ui::Playerinfo *ui;
    std::vector<std::pair<QString, Color>> freeColors;
};

#endif // PLAYERINFO_H
