#include <QtCore/QCoreApplication>
#include "Server.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Server* server = new Server();

    //Make sure the app is shut down properly once the server signals finished
    QObject::connect(server, SIGNAL(finished()), &app, SLOT(quit()));

    //Make sure server is deleted after the application is about to quit
    QObject::connect(&app, SIGNAL(aboutToQuit()), server, SLOT(deleteLater()));
    
    QTimer::singleShot(0, server, SLOT(run()));

    return app.exec();
}
