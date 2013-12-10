#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H

#include <QObject>

class TAEval;
class LoginWindow;

class LoginController : public QObject {
    Q_OBJECT

private:
    LoginWindow* _loginWindow;
    TAEval* _taEval;

public:
    LoginController(LoginWindow* loginWindow, TAEval* taEval);
    void invoke() const;

private slots:
    void loginFinished(int result);
    void termListReady();
    void loginTimedOut();
};

#endif // LOGINCONTROLLER_H
