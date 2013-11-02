#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "TAEval.h"
#include <iostream>
#include <QTimer>
#include "ViewCoursesController.h"
#include "ViewCoursesTestCase.h"

MainWindow::MainWindow(TAEval* taEval) :
    QMainWindow(0),
    _taEval(taEval),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::pretendWeClickedATestCaseButton() {
    ViewCoursesController* controller = new ViewCoursesController();
    ViewCoursesTestCase* testCase = new ViewCoursesTestCase();

    QObject::connect(testCase, SIGNAL(complete(bool)), this, SLOT(testCaseFinished(bool)));
    QObject::connect(testCase, SIGNAL(complete(bool)), controller, SLOT(deleteLater()));
    QObject::connect(testCase, SIGNAL(complete(bool)), testCase, SLOT(deleteLater()));

    controller->invoke(_taEval, testCase);
}

void MainWindow::testCaseFinished(bool success){
    std::cerr << "Test Case Finished: " << ((success) ? "SUCCESS" : "FAILED");

    //Update the GUI here

   // QTimer::singleShot(0, this, SLOT(pretendWeClickedATestCaseButton()));
}
