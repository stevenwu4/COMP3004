#include "InstructorTaskForm.h"
#include "ui_InstructorTaskForm.h"

InstructorTaskForm::InstructorTaskForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructorTaskForm)
{
    ui->setupUi(this);

    this->setWindowTitle("Task Form");
    p = parent;
}

InstructorTaskForm::~InstructorTaskForm()
{
    delete ui;
}


void InstructorTaskForm::on_cancelButton_clicked()
{
    //go back to task form
    this->close();
    p->show();
}

void InstructorTaskForm::on_okButton_clicked()
{
    //check the input, send it off to the server
    //grab the server information and update the task select when we return to it
    this->close();
    p->show();
}
