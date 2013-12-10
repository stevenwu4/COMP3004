#include "InstructorTaskForm.h"
#include "ui_InstructorTaskForm.h"
#include "TAEval.h"
#include "Task.h"

#include <QtGui>

InstructorTaskForm::InstructorTaskForm(QWidget *parent, TAEval *taEval) :
    QWidget(parent),
    ui(new Ui::InstructorTaskForm)
{
    ui->setupUi(this);

    this->setWindowTitle("Task Form");
    QStringList ratings = (QStringList() << "N/A" << "5/5 - Excellent" << "4/5 - Very Good" << "3/5 - Good" << "2/5 - Fair" << "1/5 - Poor");
    ui->taskEdit->setPlaceholderText("Enter the task name");
    ui->ratingBox->addItems(ratings);

    this->fillFields(taEval);
    ui->feedbackText->toPlainText();
    //ui->descriptionText->setPlainText("Enter the task description of the task here");
    //ui->feedbackText->setPlainText("Enter the task feedback here");


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
    //p->show();
}

void InstructorTaskForm::on_okButton_clicked()
{
    //check the input, send it off to the server
    //grab the server information and update the task select when we return to it
    this->close();
    //p->show();
}

void InstructorTaskForm::fillFields(TAEval *taEval)
{
    for (std::vector<Task>::const_iterator i = taEval->taskList().begin(); i != taEval->taskList().end(); ++i) {
        Task theTask = *i;
        alert(theTask.name());
    }
}

void InstructorTaskForm::alert(QString m)
{
    QMessageBox msgBox;
    msgBox.setText(m);
    msgBox.exec();
}
