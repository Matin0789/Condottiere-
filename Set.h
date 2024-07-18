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
    explicit Set(std::vector<std::pair<QString, Color>>, size_t, QWidget *parent = nullptr);
    ~Set();

private slots:
    void on_btn_next_clicked();
    void on_btn_back_clicked();
signals:
    void get_player(std::string, size_t, Color);
private:
    Ui::Set *ui;
    std::vector<std::pair<QString, Color>> freeColors;
};

#endif // SET_H
