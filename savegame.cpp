#include "savegame.h"
#include "ui_savegame.h"

#include "filepath.h"

#include <iomanip>
#include <fstream>

saveGame::saveGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::saveGame)
{
    ui->setupUi(this);
}

saveGame::~saveGame()
{
    delete ui;
}

void saveGame::save()
{
    this->show();
    std::ofstream file(SAVE_CONFIG, std::ios::app);           /// connection txt file input or output
    QEventLoop loop;
    connect(ui->btn_save, SIGNAL(clicked(bool)), &loop, SLOT(quit()));           /// signal and slots  
    loop.exec();
    disconnect(ui->btn_save, SIGNAL(clicked(bool)), &loop, SLOT(quit()));
    file << ui->lineEdit_name->text().toStdString() << std::endl;               ///   name 
    this->hide();
    emit data_save(SAVE_FILE(ui->lineEdit_name->text().toStdString()));
}

void saveGame::on_btn_save_clicked()
{

}

