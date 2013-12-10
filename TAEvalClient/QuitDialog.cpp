#include "QuitDialog.h"
#include "ui_QuitDialog.h"

QuitDialog::QuitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuitDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("TAEval");

    p = parent;
}

QuitDialog::~QuitDialog()
{
    delete ui;
}

void QuitDialog::on_quitButton_clicked()
{
    this->close();
    p->close();
}

void QuitDialog::on_cancelButton_clicked()
{
    this->close();
}
