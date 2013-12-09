#include "TATaskForm.h"
#include "ui_TATaskForm.h"

TATaskForm::TATaskForm(QWidget *parent) :
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
