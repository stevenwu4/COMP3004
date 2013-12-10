#include "semesterselect.h"
#include "ui_semesterselect.h"
#include "CourseSelect.h"

#include <QtGui>

SemesterSelect::SemesterSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SemesterSelect)
{
    ui->setupUi(this);
    p = parent;
    this->setWindowTitle("TAEval");

    ui->semesterList->addItem("item 1");
    ui->semesterList->addItem("item 2");
}

SemesterSelect::~SemesterSelect()
{
    delete ui;
}

void SemesterSelect::on_okButton_clicked()
{
    //get course list of the selected semester
    QString s = ui->semesterList->currentItem()->text();

    alert(s+" is the selected item");

    CourseSelect *courseSelect = new CourseSelect(this);
    this->close();
    courseSelect->show();
}

void SemesterSelect::on_cancelButton_clicked()
{
    this->close();
    p->show();
}

void SemesterSelect::alert(QString m)
{
    QMessageBox msgBox;
    msgBox.setText(m);
    msgBox.exec();
}
