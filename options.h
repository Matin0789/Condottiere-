#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>

#include "game.h"
#include "userinterface.h"

namespace Ui {
class Options;
}

class Options : public QDialog
{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = nullptr);
    ~Options();

private slots:


    void on_btn_save_clicked();

    void on_btn_Continue_clicked();

    void on_btn_load_games_clicked();

    void on_btn_audio_clicked();

    void on_btn_quit_clicked();

private:
    Ui::Options *ui;
    Game *game;
    UserInterface *user;
};

#endif // OPTIONS_H
