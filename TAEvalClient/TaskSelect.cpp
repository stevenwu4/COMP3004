#include "TaskSelect.h"
#include "ui_TaskSelect.h"
#include "CourseSelect.h"
#include "semesterselect.h"
#include "QuitDialog.h"
#include "DeleteDialog.h"
#include "InstructorTaskForm.h"
#include "TaskSelectController.h"
#include "CreateTaskController.h"
#include "Task.h"
#include "TAEval.h"

#include <QtGui>

TaskSelect::TaskSelect(QWidget *parent, TAEval* taEval) :
    QWidget(parent),
    _taEval(taEval),
    ui(new Ui::TaskSelect)
{
    ui->setupUi(this);
    this->setWindowTitle("TAEval");
    int rows = 2;
    int cols = 3;
    QStandardItemModel *model = new QStandardItemModel(rows,cols,this);

    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Teaching Assistant")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Task")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Rating")));

    QStandardItem *taName = new QStandardItem(QString("John Romero"));
    QStandardItem *taskName = new QStandardItem(QString("Make Tests"));
    QStandardItem *rating = new QStandardItem(QString("4/5"));

    QStandardItem *taName1 = new QStandardItem(QString("John Carmack"));
    QStandardItem *taskName1 = new QStandardItem(QString("Mark Tests"));
    QStandardItem *rating1 = new QStandardItem(QString("5/5"));

    QStandardItem *taName2 = new QStandardItem(QString("John Blake"));
    QStandardItem *taskName2 = new QStandardItem(QString("Mark Assignments"));
    QStandardItem *rating2 = new QStandardItem(QString("3/5"));

    model->setItem(0,0, taName);
    model->setItem(0,1,taskName);
    model->setItem(0,2,rating);

    model->setItem(1,0, taName1);
    model->setItem(1,1,taskName1);
    model->setItem(1,2,rating1);

    model->setItem(2,0, taName2);
    model->setItem(2,1,taskName2);
    model->setItem(2,2,rating2);



    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableView->horizontalHeader()->setDefaultSectionSize(142);

    ui->tableView->setModel(model);

    ui->courseEdit->setText(_taEval->currentCourse()->name());

    ui->semesterEdit->setText(_taEval->currentCourse()->term()+_taEval->currentCourse()->year());

    alert("asdf");
    //if the current user is a TA then hide create/edit/evaluate/delete buttons
}

TaskSelect::~TaskSelect()
{
    delete ui;
}

void TaskSelect::on_semesterButton_clicked()
{
    //get the course list of the user logged in
    //the semester select dialog will ask the user to select a course again

    //SemesterSelect *semesterSelect = new SemesterSelect(this);
    //semesterSelect->setModal(true);
    //semesterSelect->show();

    //change the semester and update the table
}

void TaskSelect::on_courseButton_clicked()
{
    //get the course list of the user logged in
    //the Ok button here creates a new task window right now, it should instead return to this one and update the fields and tables

    //CourseSelect *courseSelect = new CourseSelect(this);
    //courseSelect->setModal(true);
    //courseSelect->show();

    //change the course and update the table
}

void TaskSelect::on_createButton_clicked()
{
    //get the selected TA from the list
    //get the selected course and semester
    //create the task form with this information filled in
    /*
    QItemSelectionModel *selectionModel = ui->tableView->selectionModel();

    QModelIndexList list = selectionModel->selectedRows();

    QModelIndex index = model->index(list[0],0,QModelIndex());

    ui->tableView->model()->data(index).toString();
    */
    CreateTaskController* controller = new CreateTaskController(this, _taEval);
    for (std::vector<TeachingAssistant>::const_iterator i = _taEval->taList().begin(); i != _taEval->taList().end(); ++i) {
        if("Sean" == i->firstName())
            controller->invoke(*i);
    }
    /*
    //_taEval->createTask();
    this->ui->semesterEdit->text();
    ui->semesterEdit->text();
    ui->courseEdit->text();
    */

    /*
    InstructorTaskForm *taskForm = new InstructorTaskForm();
    taskForm->show();
    this->close();
    */
}

void TaskSelect::on_editButton_clicked()
{
    //get the the info for the selected task
    //create the task form with this information filled in
    /*
    if((int)ui->tableView->currentIndex() >= 0) {
        TaskSelectController* controller = new TaskSelectController(this, _taEval);
        controller->invoke(_taEval->taskList()[ui->tableView->currentIndex().row()]);
    } else {
    alert("No task selected");
    }
    */
    /*
    InstructorTaskForm *taskForm = new InstructorTaskForm();
    taskForm->show();
    this->close();
    */
}

void TaskSelect::on_evalButton_clicked()
{
    //get the the info for the selected task
    //create the task form with this information filled in


    /*
    InstructorTaskForm *taskForm = new InstructorTaskForm();
    taskForm->show();
    this->close();
    */
}

void TaskSelect::on_deleteButton_clicked()
{
    //confirm delete the selected task
    DeleteDialog *del = new DeleteDialog(this);
    del->setModal(true);
    del->show();
}

void TaskSelect::on_quitButton_clicked()
{
    //confirm quit

    QuitDialog *quit = new QuitDialog(this);
    quit->setModal(true);
    quit->show();
}

void TaskSelect::alert(QString m)
{
    QMessageBox msgBox;
    msgBox.setText(m);
    msgBox.exec();
}
