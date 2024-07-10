#ifndef SET_H
#define SET_H

#include <QDialog>

namespace Ui {
class Set;
}

class Set : public QDialog
{
    Q_OBJECT

public:
    explicit Set(QWidget *parent = nullptr);
    ~Set();

private slots:
    void on_pushButton_Back_clicked();

private:
    Ui::Set *ui;

};

#endif // SET_H
