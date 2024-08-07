#ifndef HELP_H
#define HELP_H

#include <QDialog>

#include "game.h"
#include "userinterface.h"

namespace Ui {
class Help;
}

class Help : public QDialog
{
    Q_OBJECT

public:
    explicit Help(QWidget *parent = nullptr);
    ~Help();

private slots:

    void on_btn_ok_clicked();

    void on_ptn_back_clicked();

    void on_cb_help_list_activated(int index);

    void on_cb_help_list_currentTextChanged(const QString &arg1);

private:
    Ui::Help *ui;
    std::map<std::string, QString> cardsImageRef;
};

#endif // HELP_H
