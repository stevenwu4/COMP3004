#include "TATaskForm.h"
#include "ui_TATaskForm.h"
#include <QtGui>

TATaskForm::TATaskForm(QWidget *parent, TAEval* taEval) :
    QWidget(parent),
    ui(new Ui::TATaskForm)
{
    ui->setupUi(this);

    this->setWindowTitle("Task Form");
}

TATaskForm::~TATaskForm()
{
    delete ui;
}

void TATaskForm::on_okButton_clicked()
{
    this->close();
}

void TATaskForm::alert(QString m)
{
    QMessageBox msgBox;
    msgBox.setText(m);
    msgBox.exec();
}
