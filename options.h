#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>

//#include "game.h"


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
    void on_pb_save_clicked();

    void on_pb_load_clicked();

    void on_pb_audio_clicked();

    void on_pb_quit_clicked();

    void on_pb_Continue_clicked();

private:
    Ui::Options *ui;
    //Game game;
};

#endif // OPTIONS_H
