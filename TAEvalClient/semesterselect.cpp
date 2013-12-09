#include "semesterselect.h"
#include "ui_semesterselect.h"
#include "CourseSelect.h"

SemesterSelect::SemesterSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SemesterSelect)
{
    ui->setupUi(this);
    p = parent;
    this->setWindowTitle("TAEval");
}

SemesterSelect::~SemesterSelect()
{
    delete ui;
}

void SemesterSelect::on_okButton_clicked()
{
    //get course list of the selected semester
    CourseSelect *courseSelect = new CourseSelect(this);
    this->close();
    courseSelect->show();
}

void SemesterSelect::on_cancelButton_clicked()
{
    this->close();
    p->show();
}
