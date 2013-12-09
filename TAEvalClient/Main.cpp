#include <QtGui/QApplication>
#include <QTimer>
#include "MainWindow.h"
#include "loginwindow.h"
#include "TATaskForm.h"
#include "TAEval.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    TAEval* taEval = new TAEval();

    //MainWindow window(taEval);
    //window.show();
    LoginWindow *loginWindow = new LoginWindow(0);
    loginWindow->show();

    TATaskForm *taTaskForm = new TATaskForm(0);
    taTaskForm->show();


    //Make sure taEval is deleted after the application is about to quit
    QObject::connect(&app, SIGNAL(aboutToQuit()), taEval, SLOT(deleteLater()));

    QTimer::singleShot(0, taEval, SLOT(initialize()));
    
    return app.exec();
}
