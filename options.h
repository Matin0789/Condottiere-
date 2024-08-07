#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>
#include <QMainWindow>

namespace Ui {
class Options;
}

class Options : public QDialog
{
    Q_OBJECT
signals:
    void muteAudio();
    void loadGame();
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
};

#endif // OPTIONS_H
