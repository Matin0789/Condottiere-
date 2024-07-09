#ifndef START_H
#define START_H

#include <QDialog>
#include "set.h"
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
    void on_pushButton_start_clicked();

private:
    Ui::Start *ui;
    Set *set ;
};

#endif // START_H
