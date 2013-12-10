#ifndef INSTRUCTORTASKFORM_H
#define INSTRUCTORTASKFORM_H

#include <QWidget>
#include "Task.h"

class TAEval;

namespace Ui {
class InstructorTaskForm;
}

class InstructorTaskForm : public QWidget {
    Q_OBJECT

private:
    TAEval* _taEval;

public:
    explicit InstructorTaskForm(QWidget *parent, TAEval *taEval);
    ~InstructorTaskForm();

    Task task() const;

private slots:


    void on_cancelButton_clicked();

    void on_okButton_clicked();

    void alert(QString);

private:
    Ui::InstructorTaskForm *ui;
    QWidget *p;
};

#endif // INSTRUCTORTASKFORM_H
