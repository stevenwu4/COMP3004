#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "TAEval.h"
#include <iostream>
#include <QtGui>
#include <QTimer>
#include "ViewCoursesController.h"
#include "ViewCoursesTestCase.h"

MainWindow::MainWindow(TAEval* taEval) :
    QMainWindow(0),
    _taEval(taEval),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    //this->setFixedSize(QWidget::minimumSizeHint());
    QSize testNotificationBox(70,25);
    int infoHeight = 50;

    ui->courseListTextEdit->setFixedSize(testNotificationBox);
    ui->courseListInfotextEdit->setFixedHeight(infoHeight);
    ui->courseListInfotextEdit->setText("Attempt to retreive a list of courses from the server.");

    ui->taListTextEdit->setFixedSize(testNotificationBox);
    ui->taListInfoTextEdit->setFixedHeight(infoHeight);
    ui->taListInfoTextEdit->setText("Attempt to retreive a list of TAs from the server.");

    ui->taskListTextEdit->setFixedSize(testNotificationBox);
    ui->taskListInfoTextEdit->setFixedHeight(infoHeight);
    ui->taskListInfoTextEdit->setText("Attempt to retreive a list of tasks from the server.");

    ui->createTextEdit->setFixedSize(testNotificationBox);
    ui->createInfoTextEdit->setFixedHeight(infoHeight);
    ui->createInfoTextEdit->setText("Attempt to create a task on the server.");

    ui->editTextEdit->setFixedSize(testNotificationBox);
    ui->editInfoTextEdit->setFixedHeight(infoHeight);
    ui->editInfoTextEdit->setText("Attempt to edit a task on the server.");

    ui->evaluateTextEdit->setFixedSize(testNotificationBox);
    ui->evaluateInfoTextEdit->setFixedHeight(infoHeight);
    ui->evaluateInfoTextEdit->setText("Attempt to evaluate or edit an evaluation on the server.");

    ui->deleteTextEdit->setFixedSize(testNotificationBox);
    ui->deleteInfoTextEdit->setFixedHeight(infoHeight);
    ui->deleteInfoTextEdit->setText("Attempt to delete a task on the server.");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::testCaseFinished(bool success){
    std::cerr << "Test cCase Finished: ";

    //Update the GUI here
    QPalette pass = ui->courseListTextEdit->palette();
    pass.setColor(QPalette::Base, QColor(0,255,0));
    QPalette fail = ui->courseListTextEdit->palette();
    fail.setColor(QPalette::Base, QColor(255,0,0));

    if(success) {
        ui->courseListTextEdit->setText("SUCCESS");
        ui->courseListTextEdit->setPalette(pass);
    } else {
        ui->courseListTextEdit->setText("FAILED");
        ui->courseListTextEdit->setPalette(fail);
    }
}

void MainWindow::on_courseListButton_clicked() {
    ViewCoursesController* controller = new ViewCoursesController();
    ViewCoursesTestCase* testCase = new ViewCoursesTestCase();

    QObject::connect(testCase, SIGNAL(complete(bool)), this, SLOT(testCaseFinished(bool)));
    QObject::connect(testCase, SIGNAL(complete(bool)), controller, SLOT(deleteLater()));
    QObject::connect(testCase, SIGNAL(complete(bool)), testCase, SLOT(deleteLater()));

    controller->invoke(_taEval, testCase);
}
