#include "semesterselect.h"
#include "ui_semesterselect.h"
#include "CourseSelect.h"
#include "TAEval.h"
#include "SemesterSelectController.h"
#include <QtGui>

SemesterSelect::SemesterSelect(QWidget *parent, TAEval* taEval) :
    QDialog(parent),
    _taEval(taEval),
    ui(new Ui::SemesterSelect) {
    ui->setupUi(this);
    p = parent;

    ui->semesterList->clear();

    for (std::vector<Term>::const_iterator i = _taEval->termList().begin(); i != _taEval->termList().end(); ++i) {
        ui->semesterList->addItem(i->season() + " " + QString::number(i->year()));
    }

    this->setWindowTitle("TAEval");
}

SemesterSelect::~SemesterSelect() {
    delete ui;
}

void SemesterSelect::on_okButton_clicked() {
    SemesterSelectController* semesterController = new SemesterSelectController(this, _taEval);
    semesterController->invoke(_taEval->termList()[ui->semesterList->currentRow()]);
}

void SemesterSelect::on_cancelButton_clicked() {
    this->close();
    p->show();
}

void SemesterSelect::alert(QString m)
{
    QMessageBox msgBox;
    msgBox.setText(m);
    msgBox.exec();
}
