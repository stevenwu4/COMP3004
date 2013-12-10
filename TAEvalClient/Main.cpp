#include <QtGui/QApplication>
#include <QTimer>
#include "loginwindow.h"
#include "TAEval.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    TAEval* taEval = new TAEval();

    LoginWindow loginWindow(0, taEval);
    loginWindow.show();

    //Make sure taEval is deleted after the application is about to quit
    QObject::connect(&app, SIGNAL(aboutToQuit()), taEval, SLOT(deleteLater()));

    QTimer::singleShot(0, taEval, SLOT(initialize()));
    
    return app.exec();
}
