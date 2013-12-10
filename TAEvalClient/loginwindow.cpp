#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "semesterselect.h"
#include "QuitDialog.h"
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
    QuitDialog *quit = new QuitDialog(this);
    quit->setModal(true);
    quit->show();
}

void LoginWindow::on_loginButton_clicked()
{

    QString username = ui->usernameText->text();
    //check if the username is correct
    if(username.isEmpty()) {
        alert(username+" is not a valid username.");
    } else {
        //get the semester list of the user logged in
        SemesterSelect *semesterSelect = new SemesterSelect(this);
        this->close();
        semesterSelect->show();
    }
}

void LoginWindow::alert(QString m)
{
    QMessageBox msgBox;
    msgBox.setText(m);
    msgBox.exec();
}
