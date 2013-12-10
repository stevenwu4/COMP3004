#include "CourseSelect.h"
#include "ui_CourseSelect.h"
#include "TaskSelect.h"

CourseSelect::CourseSelect(QWidget *parent, TAEval* taEval) :
    QDialog(parent),
    _taEval(taEval),
    ui(new Ui::CourseSelect) {
    ui->setupUi(this);
    p = parent;
    this->setWindowTitle("TAEval");
}

CourseSelect::~CourseSelect() {
    delete ui;
}

void CourseSelect::on_okButton_clicked() {
    //get list of tasks for course
    TaskSelect *tasks = new TaskSelect(0);
    this->close();
    tasks->show();
}

void CourseSelect::on_cancelButton_clicked() {
    this->close();
    p->show();

}

void CourseSelect::timeout() {

}
