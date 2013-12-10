#ifndef TASKSELECT_H
#define TASKSELECT_H

#include <QWidget>

class TAEval;

namespace Ui {
class TaskSelect;
}

class TaskSelect : public QWidget {
    Q_OBJECT

private:
    TAEval* _taEval;
    
public:
    explicit TaskSelect(QWidget *parent, TAEval* taEval);
    ~TaskSelect();
    
private slots:
    void on_semesterButton_clicked();

    void on_courseButton_clicked();

    void on_createButton_clicked();

    void on_editButton_clicked();

    void on_evalButton_clicked();

    void on_deleteButton_clicked();

    void on_quitButton_clicked();

    void alert(QString m);

private:
    Ui::TaskSelect *ui;
};

#endif // TASKSELECT_H
