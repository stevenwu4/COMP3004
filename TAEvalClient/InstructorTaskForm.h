#ifndef INSTRUCTORTASKFORM_H
#define INSTRUCTORTASKFORM_H

#include <QWidget>

class TAEval;

namespace Ui {
class InstructorTaskForm;
}

class InstructorTaskForm : public QWidget
{
    Q_OBJECT

public:
    explicit InstructorTaskForm(QWidget *parent, TAEval *taEval);
    ~InstructorTaskForm();

private slots:


    void on_cancelButton_clicked();

    void on_okButton_clicked();

    void fillFields(TAEval*);

    void alert(QString);

private:
    Ui::InstructorTaskForm *ui;
    QWidget *p;
};

#endif // INSTRUCTORTASKFORM_H
