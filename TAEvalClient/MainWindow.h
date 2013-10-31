#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class TAEval;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
    MainWindow(TAEval* taEval);
    ~MainWindow();
    
private:
    TAEval* _taEval;
    Ui::MainWindow *ui;

public slots:
    void pretendWeClickedATestCaseButton();
    void testCaseFinished(bool success);
};

#endif // MAINWINDOW_H
