#include "DeleteDialog.h"
#include "ui_DeleteDialog.h"

DeleteDialog::DeleteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteDialog)
{
    ui->setupUi(this);
    p = parent;
}

DeleteDialog::~DeleteDialog()
{
    delete ui;
}

void DeleteDialog::on_confirmButton_clicked()
{
    //really send the delete request
    this->close();
}

void DeleteDialog::on_cancelButton_clicked()
{
    this->close();
}
