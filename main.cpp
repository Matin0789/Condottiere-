#include "mainwindow.h"

#include <QApplication>
#include <QMediaPlayer>
#include <QAudioOutput>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();                  // Lets Gooooooo

    return a.exec();
}
