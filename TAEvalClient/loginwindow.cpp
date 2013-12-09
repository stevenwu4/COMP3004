#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "semesterselect.h"
#include <QtGui>
LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(0),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("TAEval");
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_quitButton_clicked()
{
    this->close();
}

void LoginWindow::on_loginButton_clicked()
{
    //get the semester list of the user logged in
    SemesterSelect *semesterSelect = new SemesterSelect(this);
    this->close();
    semesterSelect->show();
}
