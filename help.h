#ifndef HELP_H
#define HELP_H

#include <QDialog>

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
    void on_cb_help_list_activated(int index);

    void on_pb_ok_clicked();

    void on_pb_go_back_clicked();

private:
    Ui::Help *ui;
};

#endif // HELP_H
