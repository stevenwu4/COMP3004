#include "TaskSelect.h"
#include "ui_TaskSelect.h"
#include "CourseSelect.h"
#include "semesterselect.h"
#include "QuitDialog.h"
#include "InstructorTaskForm.h"


TaskSelect::TaskSelect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskSelect)
{
    ui->setupUi(this);
    this->setWindowTitle("TAEval");

    //ui->tableView->setModel(model);


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

    SemesterSelect *semesterSelect = new SemesterSelect(this, 0);
    semesterSelect->setModal(true);
    semesterSelect->show();

    //change the semester and update the table
}

void TaskSelect::on_courseButton_clicked()
{
    //get the course list of the user logged in
    //the Ok button here creates a new task window right now, it should instead return to this one and update the fields and tables

    CourseSelect *courseSelect = new CourseSelect(this, 0);
    courseSelect->setModal(true);
    courseSelect->show();

    //change the course and update the table
}

void TaskSelect::on_createButton_clicked()
{
    //get the selected TA from the list
    //get the selected course and semester
    //create the task form with this information filled in

    InstructorTaskForm *taskForm = new InstructorTaskForm();
    taskForm->show();
    this->close();
}

void TaskSelect::on_editButton_clicked()
{
    //get the the info for the selected task
    //create the task form with this information filled in

    InstructorTaskForm *taskForm = new InstructorTaskForm();
    taskForm->show();
    this->close();
}

void TaskSelect::on_evalButton_clicked()
{
    //get the the info for the selected task
    //create the task form with this information filled in

    InstructorTaskForm *taskForm = new InstructorTaskForm();
    taskForm->show();
    this->close();
}

void TaskSelect::on_deleteButton_clicked()
{
    //delete the selected task
}

void TaskSelect::on_quitButton_clicked()
{
    //confirm quit

    QuitDialog *quit = new QuitDialog(this);
    quit->setModal(true);
    quit->show();
}
