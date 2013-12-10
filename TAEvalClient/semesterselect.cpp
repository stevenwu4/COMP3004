#include "semesterselect.h"
#include "ui_semesterselect.h"
#include "CourseSelect.h"
#include "TAEval.h"
#include "SemesterSelectController.h"

SemesterSelect::SemesterSelect(QWidget *parent, TAEval* taEval) :
    QDialog(parent),
    _taEval(taEval),
    ui(new Ui::SemesterSelect) {
    ui->setupUi(this);
    p = parent;

    for (std::vector<Term>::const_iterator i = _taEval->termList().begin(); i != _taEval->termList().end(); ++i) {
        ui->semesterList->addItem(i->season() + " " + i->year());
    }

    this->setWindowTitle("TAEval");
}

SemesterSelect::~SemesterSelect() {
    delete ui;
}

void SemesterSelect::on_okButton_clicked() {
    SemesterSelectController* semesterController = new SemesterSelectController(this, _taEval);
    semesterController->invoke();
    ui->semesterList->currentItem()->text();
}

void SemesterSelect::on_cancelButton_clicked()
{
    this->close();
    p->show();
}
