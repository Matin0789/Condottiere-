#ifndef CAMPAIGN_H
#define CAMPAIGN_H

#include <QDialog>

namespace Ui {
class campaign;
}

class campaign : public QDialog
{
    Q_OBJECT

public:
    explicit campaign(QWidget *parent = nullptr);
    ~campaign();

private:
    Ui::campaign *ui;
};

#endif // CAMPAIGN_H
