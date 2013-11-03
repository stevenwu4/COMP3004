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
    void testCaseFinished(bool success);

private slots:
    void on_courseListButton_clicked();
};

#endif // MAINWINDOW_H
