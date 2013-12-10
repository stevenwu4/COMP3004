#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "semesterselect.h"
#include <QtGui>
#include "LoginController.h"

LoginWindow::LoginWindow(QWidget *parent, TAEval* taEval) :
    QMainWindow(parent),
    _taEval(taEval),
    ui(new Ui::LoginWindow) {
    ui->setupUi(this);
    this->setWindowTitle("TAEval");
}

LoginWindow::~LoginWindow() {
    delete ui;
}

void LoginWindow::on_quitButton_clicked() {
    this->close();
}

void LoginWindow::on_loginButton_clicked() {
    LoginController* loginController = new LoginController(this, _taEval);
    loginController->invoke();
}

QString LoginWindow::usernameText() const {
    return ui->usernameText->text();
}

void LoginWindow::alert(QString m) {
    QMessageBox msgBox;
    msgBox.setText(m);
    msgBox.exec();
}

