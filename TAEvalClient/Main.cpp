#include <QtGui/QApplication>
#include <QTimer>
#include "MainWindow.h"
#include "TAEval.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    TAEval* taEval = new TAEval();

    MainWindow window(taEval);
    window.show();

    //Here is where we should introduce a Controller object or something that
    //sets up the signals and slots between window (our GUI) and taEval (our model) for updating gui
    //elements and performing model updates

    //Make sure taEval is deleted after the application is about to quit
    QObject::connect(&app, SIGNAL(aboutToQuit()), taEval, SLOT(deleteLater()));

    QTimer::singleShot(0, taEval, SLOT(initialize()));
    QTimer::singleShot(0, &window, SLOT(pretendWeClickedATestCaseButton()));
    
    return app.exec();
}
