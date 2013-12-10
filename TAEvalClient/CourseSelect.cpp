#include "CourseSelect.h"
#include "ui_CourseSelect.h"
#include "TaskSelect.h"
#include "CourseSelectController.h"
#include "TAEval.h"
#include "Course.h"
#include <QtGui>

CourseSelect::CourseSelect(QWidget *parent, TAEval* taEval) :
    QDialog(parent),
    _taEval(taEval),
    ui(new Ui::CourseSelect) {
    ui->setupUi(this);
    p = parent;

    for (std::vector<Course>::const_iterator i = _taEval->courseList().begin(); i != _taEval->courseList().end(); ++i) {
        ui->courseList->addItem(i->code());
    }

    this->setWindowTitle("TAEval");
}

CourseSelect::~CourseSelect() {
    delete ui;
}

void CourseSelect::on_okButton_clicked() {
    CourseSelectController* controller = new CourseSelectController(this, _taEval);
    controller->invoke(_taEval->courseList()[ui->courseList->currentRow()]);
}

void CourseSelect::on_cancelButton_clicked() {
    this->close();
    p->show();
}

void CourseSelect::alert(QString m)
{
    QMessageBox msgBox;
    msgBox.setText(m);
    msgBox.exec();
}
