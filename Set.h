#ifndef SET_H
#define SET_H

#include <QDialog>
#include <string>

#include "showcards.h"
#include "enumcolor.h"


namespace Ui {
class Set;
}

class Set : public QDialog
{
    Q_OBJECT

public:
    explicit Set(QWidget *parent = nullptr);
    ~Set();

signals:
    void get_player_name(std::string);
    void get_player_old(size_t);
    void get_player_color(Color);

private slots:
    void on_btn_next_clicked();
    void on_btn_back_clicked();

private:
    Ui::Set *ui;
    std::vector<std::pair<QString, Color>> freeColors;
};

#endif // SET_H
