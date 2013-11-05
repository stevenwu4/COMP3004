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

    this->setWindowTitle("TAEval Test Client");
    this->resize(640,480);
    QSize testNotificationBox(70,25);
    int infoHeight = 80;

    ui->courseListTextEdit->setFixedSize(testNotificationBox);
    ui->courseListInfotextEdit->setFixedHeight(infoHeight);
    ui->courseListInfotextEdit->setText("Makes a request for a list of courses from the Winter 2007 semester from the server. If the list received matches the test case's expected list then this test will succeed. Any other response will result in failure. Details of any failure and the list of courses are logged to the console.");

    ui->taListTextEdit->setFixedSize(testNotificationBox);
    ui->taListInfoTextEdit->setFixedHeight(infoHeight);
    ui->taListInfoTextEdit->setText("Makes a request for a list of TAs from ENGL9999 course from the server. If the list received matches the test case's expected list then this test will succeed. Any other response results in failure. Details of any failure and the list of teaching assistants are logged to the console.");

    ui->taskListTextEdit->setFixedSize(testNotificationBox);
    ui->taskListInfoTextEdit->setFixedHeight(infoHeight);
    ui->taskListInfoTextEdit->setText("Makes a request for a list of tasks from the ENGL9999 course from the server. If the list received matches the test case's expected list then this test will succeed. Any other response results in failure. Details of any failure and the list of tasks are logged to the console.");

    ui->createTextEdit->setFixedSize(testNotificationBox);
    ui->createInfoTextEdit->setFixedHeight(infoHeight);
    ui->createInfoTextEdit->setText("Makes a request to create a task for the course COMP4401. The server adds the task to the database and responds with the created task. If the created task from the server matches the test case's then this test will succeed. Any other response results in failure. Details of any failure and the create task are logged to the console");

    ui->editTextEdit->setFixedSize(testNotificationBox);
    ui->editInfoTextEdit->setFixedHeight(infoHeight);
    ui->editInfoTextEdit->setText("Makes a request to edit an existing task on the server. The server modifies the particular task and responds with the updated task. If the updated task information matches the expected task this test will succeed. Any other response results in failure. Details of any failure and the editted task are logged to the console.");

    ui->deleteTextEdit->setFixedSize(testNotificationBox);
    ui->deleteInfoTextEdit->setFixedHeight(infoHeight);
    ui->deleteInfoTextEdit->setText("Makes a request to delete a task on the server. If the task is successfully deleted or does not exist this test will succeed. Any other response results in failure. Any failures are logged to the console.");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::testCaseFinished(bool success, int testCase){
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

void MainWindow::on_deleteButton_clicked()
{
    DeleteTaskController* controller = new DeleteTaskController();
    DeleteTaskTestCase* testCase = new DeleteTaskTestCase();

    QObject::connect(testCase, SIGNAL(complete(bool,int)), this, SLOT(testCaseFinished(bool,int)));
    QObject::connect(testCase, SIGNAL(complete(bool,int)), controller, SLOT(deleteLater()));
    QObject::connect(testCase, SIGNAL(complete(bool,int)), testCase, SLOT(deleteLater()));

    controller->invoke(_taEval, testCase);
}
