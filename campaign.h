#ifndef CAMPAIGN_H
#define CAMPAIGN_H

#include <QMainWindow>
#include <QLabel>
#include <QVector>


namespace Ui {
class Campaign;
}

class Campaign : public QMainWindow
{
    Q_OBJECT

public:
    explicit Campaign(QWidget *parent = nullptr);
    ~Campaign();

private:
    Ui::Campaign *ui;
    //QVector<QLabel*> Nameoflabels;

};

#endif // CAMPAIGN_H
