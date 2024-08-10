#ifndef SAVEGAME_H
#define SAVEGAME_H

#include <QMainWindow>

namespace Ui {
class saveGame;
}

class saveGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit saveGame(QWidget *parent = nullptr);
    ~saveGame();
public slots:
    void save();
signals:
    void data_save(std::string);
private slots:
    void on_btn_save_clicked();

private:
    Ui::saveGame *ui;
};

#endif // SAVEGAME_H
