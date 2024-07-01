#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "game.h"
#include "userinterface.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/Condottiere/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    UserInterface interface;  // set object
    Game game(interface);  //relationship
    game.play();  //start game

    return app.exec();
}
