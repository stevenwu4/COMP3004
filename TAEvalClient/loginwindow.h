#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>

class TAEval;

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow {
    Q_OBJECT

private:
    TAEval* _taEval;
    
public:
    explicit LoginWindow(QWidget *parent, TAEval* taEval);
    ~LoginWindow();
    QString usernameText() const;

    void alert(QString m);

private slots:
    void on_quitButton_clicked();
    void on_loginButton_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
