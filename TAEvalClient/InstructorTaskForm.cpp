#include "InstructorTaskForm.h"
#include "InstructorTaskFormController.h"
#include "ui_InstructorTaskForm.h"
#include "TAEval.h"
#include "Task.h"

#include <QtGui>

InstructorTaskForm::InstructorTaskForm(QWidget *parent, TAEval *taEval) :
    QWidget(parent),
    _taEval(taEval),
    ui(new Ui::InstructorTaskForm)
{
    ui->setupUi(this);

    this->setWindowTitle("Task Form");
    QStringList ratings = (QStringList() << "N/A" << "5/5 - Excellent" << "4/5 - Very Good" << "3/5 - Good" << "2/5 - Fair" << "1/5 - Poor");
    QStringList tas;
    ui->feedbackText->toPlainText();
    ui->descriptionText->toPlainText();
    ui->taskEdit->text();
    ui->ratingBox->currentText();
    ui->taBox->currentText();
    ui->semesterEdit->text();
    ui->courseEdit->text();
    for (std::vector<TeachingAssistant>::const_iterator i = _taEval->taList().begin(); i != _taEval->taList().end(); ++i)
        tas << (i->firstName() + " " + i->lastName() + " " + i->id());

    ui->taskEdit->setPlaceholderText("Enter the task name");
    ui->ratingBox->addItems(ratings);
    ui->taBox->addItems(tas);

    p = parent;
}

Task InstructorTaskForm::task() const {
    int rating = 0;

    QString rate = ui->ratingBox->currentText();

    if (rate == "N/A")
        rating = 0;
    else if (rate == "5/5 - Excelent")
        rating = 5;
    else if (rate == "4/5 - Very Good")
        rating = 4;
    else if (rate == "3/5 - Good")
        rating = 3;
    else if (rate == "2/5 - Fair")
        rating = 2;
    else
        rating = 1;

    return Task(_taEval->currentTask()->id(), ui->taskEdit->text(), ui->descriptionText->toPlainText(), ui->feedbackText->toPlainText(), rating);
}



InstructorTaskForm::~InstructorTaskForm() {
    delete ui;
}


void InstructorTaskForm::on_cancelButton_clicked()
{
    this->close();
    p->show();
}

void InstructorTaskForm::on_okButton_clicked()
{
    InstructorTaskFormController* controller = new InstructorTaskFormController(this, _taEval);
    controller->invoke();
}

void InstructorTaskForm::alert(QString m)
{
    QMessageBox msgBox;
    msgBox.setText(m);
    msgBox.exec();
}
