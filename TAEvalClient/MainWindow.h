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
    void testCaseFinished(bool success,int testCase);

private slots:
    void on_courseListButton_clicked();
    void on_taListButton_clicked();
    void on_taskListButton_clicked();
    void on_createButton_clicked();
    void on_editButton_clicked();
    void on_evaluateButton_clicked();
    void on_deleteButton_clicked();
};

#endif // MAINWINDOW_H
