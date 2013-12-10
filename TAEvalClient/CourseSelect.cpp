#include "CourseSelect.h"
#include "ui_CourseSelect.h"
#include "TaskSelect.h"

#include <QtGui>

CourseSelect::CourseSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CourseSelect)
{
    ui->setupUi(this);
    p = parent;
    this->setWindowTitle("TAEval");

    ui->courseList->addItem("item A");
    ui->courseList->addItem("Item B");
}

CourseSelect::~CourseSelect()
{
    delete ui;
}

void CourseSelect::on_okButton_clicked()
{
    QString s = ui->courseList->currentItem()->text();

    alert(s+" is the item selected");

    //get list of tasks for course
    TaskSelect *tasks = new TaskSelect(0);
    this->close();
    tasks->show();
}

void CourseSelect::on_cancelButton_clicked()
{
    this->close();
    p->show();

}

void CourseSelect::alert(QString m)
{
    QMessageBox msgBox;
    msgBox.setText(m);
    msgBox.exec();
}
