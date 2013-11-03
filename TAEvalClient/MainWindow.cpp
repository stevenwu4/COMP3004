#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "TAEval.h"
#include <iostream>
#include <QtGui>
#include <QTimer>
#include "ViewCoursesController.h"
#include "ViewCoursesTestCase.h"
#include "ViewTeachingAssistantsController.h"
#include "ViewTeachingAssistantsTestCase.h"
#include "ViewTasksController.h"
#include "ViewTasksTestCase.h"
#include "CreateTaskController.h"
#include "CreateTaskTestCase.h"
#include "EditTaskController.h"
#include "EditTaskTestCase.h"
#include "DeleteTaskController.h"
#include "DeleteTaskTestCase.h"

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

void MainWindow::testCaseFinished(bool success, int testCase){
    std::cerr << "Test Case Finished: ";

    //Update the GUI here
    QPalette pass = ui->courseListTextEdit->palette();
    pass.setColor(QPalette::Base, QColor(0,255,0));
    QPalette fail = ui->courseListTextEdit->palette();
    fail.setColor(QPalette::Base, QColor(255,0,0));

    switch (testCase) {
    case 0:
        if(success) {
            ui->courseListTextEdit->setText("SUCCESS");
            ui->courseListTextEdit->setPalette(pass);
        } else {
            ui->courseListTextEdit->setText("FAILED");
            ui->courseListTextEdit->setPalette(fail);
        }
        break;
    case 1:
        if(success) {
            ui->taListTextEdit->setText("SUCCESS");
            ui->taListTextEdit->setPalette(pass);
        } else {
            ui->taListTextEdit->setText("FAILED");
            ui->taListTextEdit->setPalette(fail);
        }
        break;
    case 2:
        if(success) {
            ui->taskListTextEdit->setText("SUCCESS");
            ui->taskListTextEdit->setPalette(pass);
        } else {
            ui->taskListTextEdit->setText("FAILED");
            ui->taskListTextEdit->setPalette(fail);
        }
        break;
    case 3:
        if(success) {
            ui->createTextEdit->setText("SUCCESS");
            ui->createTextEdit->setPalette(pass);
        } else {
            ui->createTextEdit->setText("FAILED");
            ui->createTextEdit->setPalette(fail);
        }
        break;
    case 4:
        if(success) {
            ui->editTextEdit->setText("SUCCESS");
            ui->editTextEdit->setPalette(pass);
        } else {
            ui->editTextEdit->setText("FAILED");
            ui->editTextEdit->setPalette(fail);
        }
        break;
    case 5:
        if(success) {
            ui->editTextEdit->setText("SUCCESS");
            ui->editTextEdit->setPalette(pass);
        } else {
            ui->editTextEdit->setText("FAILED");
            ui->editTextEdit->setPalette(fail);
        }
        break;
    case 6:
        if(success) {
            ui->deleteTextEdit->setText("SUCCESS");
            ui->deleteTextEdit->setPalette(pass);
        } else {
            ui->deleteTextEdit->setText("FAILED");
            ui->deleteTextEdit->setPalette(fail);
        }
        break;
    }
}

void MainWindow::on_courseListButton_clicked() {
    ViewCoursesController* controller = new ViewCoursesController();
    ViewCoursesTestCase* testCase = new ViewCoursesTestCase();

    QObject::connect(testCase, SIGNAL(complete(bool,int)), this, SLOT(testCaseFinished(bool,int)));
    QObject::connect(testCase, SIGNAL(complete(bool,int)), controller, SLOT(deleteLater()));
    QObject::connect(testCase, SIGNAL(complete(bool,int)), testCase, SLOT(deleteLater()));

    controller->invoke(_taEval, testCase);
}

void MainWindow::on_taListButton_clicked()
{
    ViewTeachingAssistantsController* controller = new ViewTeachingAssistantsController();
    ViewTeachingAssistantsTestCase* testCase = new ViewTeachingAssistantsTestCase();

    QObject::connect(testCase, SIGNAL(complete(bool,int)), this, SLOT(testCaseFinished(bool,int)));
    QObject::connect(testCase, SIGNAL(complete(bool,int)), controller, SLOT(deleteLater()));
    QObject::connect(testCase, SIGNAL(complete(bool,int)), testCase, SLOT(deleteLater()));

    controller->invoke(_taEval, testCase);
}

void MainWindow::on_taskListButton_clicked()
{
    ViewTasksController* controller = new ViewTasksController();
    ViewTasksTestCase* testCase = new ViewTasksTestCase();

    QObject::connect(testCase, SIGNAL(complete(bool,int)), this, SLOT(testCaseFinished(bool,int)));
    QObject::connect(testCase, SIGNAL(complete(bool,int)), controller, SLOT(deleteLater()));
    QObject::connect(testCase, SIGNAL(complete(bool,int)), testCase, SLOT(deleteLater()));

    controller->invoke(_taEval, testCase);
}

void MainWindow::on_createButton_clicked()
{
    CreateTaskController* controller = new CreateTaskController();
    CreateTaskTestCase* testCase = new CreateTaskTestCase();

    QObject::connect(testCase, SIGNAL(complete(bool,int)), this, SLOT(testCaseFinished(bool,int)));
    QObject::connect(testCase, SIGNAL(complete(bool,int)), controller, SLOT(deleteLater()));
    QObject::connect(testCase, SIGNAL(complete(bool,int)), testCase, SLOT(deleteLater()));

    controller->invoke(_taEval, testCase);
}

void MainWindow::on_editButton_clicked()
{
    EditTaskController* controller = new EditTaskController();
    EditTaskTestCase* testCase = new EditTaskTestCase();

    QObject::connect(testCase, SIGNAL(complete(bool,int)), this, SLOT(testCaseFinished(bool,int)));
    QObject::connect(testCase, SIGNAL(complete(bool,int)), controller, SLOT(deleteLater()));
    QObject::connect(testCase, SIGNAL(complete(bool,int)), testCase, SLOT(deleteLater()));

    controller->invoke(_taEval, testCase);
}

void MainWindow::on_evaluateButton_clicked()
{
    EditTaskController* controller = new EditTaskController();
    EditTaskTestCase* testCase = new EditTaskTestCase();

    QObject::connect(testCase, SIGNAL(complete(bool,int)), this, SLOT(testCaseFinished(bool,int)));
    QObject::connect(testCase, SIGNAL(complete(bool,int)), controller, SLOT(deleteLater()));
    QObject::connect(testCase, SIGNAL(complete(bool,int)), testCase, SLOT(deleteLater()));

    controller->invoke(_taEval, testCase);
}

void MainWindow::on_deleteButton_clicked()
{
    DeleteTaskController* controller = new DeleteTaskController();
    DeleteTaskTestCase* testCase = new DeleteTaskTestCase();

    QObject::connect(testCase, SIGNAL(complete(bool,int)), this, SLOT(testCaseFinished(bool,int)));
    QObject::connect(testCase, SIGNAL(complete(bool,int)), controller, SLOT(deleteLater()));
    QObject::connect(testCase, SIGNAL(complete(bool,int)), testCase, SLOT(deleteLater()));

    controller->invoke(_taEval, testCase);
}
