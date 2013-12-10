#include "LoginController.h"
#include "TAEval.h"
#include "loginwindow.h"
#include "semesterselect.h"

LoginController::LoginController(LoginWindow* loginWindow, TAEval* taEval) :
    QObject(loginWindow),
    _loginWindow(loginWindow),
    _taEval(taEval) {}

void LoginController::invoke() const {
    QObject::connect(_taEval, SIGNAL(loginComplete(int)), this, SLOT(loginFinished(int)));

    QObject::connect(_taEval, SIGNAL(requestTimedOut()), this, SLOT(loginTimedOut()));

    _taEval->requestLogin(_loginWindow->usernameText());
}

void LoginController::loginFinished(int result) {
    qDebug() << "FUCK\n";

    if (result == 1 || result == 2) {
        _taEval->setUserType(result);

        QObject::connect(_taEval, SIGNAL(termListUpdated(std::vector<Term>)), this, SLOT(termListReady()));
        _taEval->requestTermList();
    } else {
        //LOGIN FAILED
        _loginWindow->alert("Username not found");
    }
}

void LoginController::termListReady() {
    QObject::disconnect(_taEval, SIGNAL(requestTimedOut()), this, SLOT(loginTimedOut()));
    SemesterSelect* semesterSelect = new SemesterSelect(_loginWindow, _taEval);
    _loginWindow->close();
    semesterSelect->show();
}

void LoginController::loginTimedOut() {

}
