#ifndef SETPLAYER_H
#define SETPLAYER_H

#include <QDialog>
#include <string>
#include <map>

#include "showcards.h"
#include "enumcolor.h"


namespace Ui {
class Setplayer;
}

class Setplayer : public QDialog
{
    Q_OBJECT

public:
    explicit Setplayer(std::map<QString, Color>, size_t, QWidget *parent = nullptr);
    ~Setplayer();

private slots:
    void on_btn_next_clicked();
    void on_btn_back_clicked();
signals:
    void get_player(std::string, size_t, Color);
private:
    Ui::Setplayer *ui;
    std::map<QString, Color> freeColors;
};

#endif // SETPLAYER_H
