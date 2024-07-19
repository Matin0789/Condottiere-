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
    explicit Playerinfo(std::vector<std::pair<QString, Color>>, size_t, QWidget *parent = nullptr);
    ~Playerinfo();

private slots:
    void on_btn_next_clicked();
    void on_btn_back_clicked();
signals:
    void get_player(std::string, size_t, Color);
private:
    Ui::Playerinfo *ui;
    std::vector<std::pair<QString, Color>> freeColors;
};

#endif // PLAYERINFO_H
