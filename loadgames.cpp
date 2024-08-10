#include "loadgames.h"
#include "ui_loadgames.h"

#include "filepath.h"

#include <stdexcept>
#include <fstream>
#include <iomanip>

loadGames::loadGames(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loadGames)
{
    ui->setupUi(this);
}

loadGames::~loadGames()
{
    delete ui;
}

std::string loadGames::load()                   /// this function is for show load games 
{

    std::ifstream file(SAVE_CONFIG);
    if (!file)
        throw std::runtime_error("save config file cannot be open");       // exception handeling       // if runtime error 
    std::string saveName;
    while(file >> quoted(saveName)) {
        ui->comboBox->addItem(QString::fromStdString(saveName));
    }

    this->show();

    QEventLoop loop;

    connect(ui->btn_load, SIGNAL(clicked(bool)), &loop, SLOT(quit()));         // signal and slots 
    loop.exec();
    connect(ui->btn_load, SIGNAL(clicked(bool)), &loop, SLOT(quit()));         // signal and slots 

    this->hide();

    return ui->comboBox->currentText().toStdString();
}
