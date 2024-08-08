#ifndef GAMESINFO_H
#define GAMESINFO_H

#include <QMainWindow>

namespace Ui {
class gamesInfo;
}

class gamesInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit gamesInfo(QWidget *parent = nullptr);
    ~gamesInfo();

private:
    Ui::gamesInfo *ui;
};

#endif // GAMESINFO_H
