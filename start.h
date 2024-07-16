#ifndef START_H
#define START_H

#include <QDialog>
#include "playerInfo.h"
namespace Ui {
class Start;
}

class Start : public QDialog
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = nullptr);
    ~Start();

private slots:

    void on_btn_next_clicked();

    void on_btn_back_clicked();

private:
    Ui::Start *ui;
    Playerinfo *playerinfo ;
};

#endif // START_H
