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
         //  this functions is for buttons 
    void on_btn_save_clicked();    //save   
    void on_btn_Continue_clicked();     // continue
    void on_btn_load_games_clicked();      //loads 
    void on_btn_audio_clicked();           // audio
    void on_btn_quit_clicked();           //quit 

private:
    Ui::Options *ui;        /// objects of userinterface 
};

#endif // OPTIONS_H
