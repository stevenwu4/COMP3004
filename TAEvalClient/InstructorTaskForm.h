#ifndef INSTRUCTORTASKFORM_H
#define INSTRUCTORTASKFORM_H

#include <QWidget>

namespace Ui {
class InstructorTaskForm;
}

class InstructorTaskForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit InstructorTaskForm(QWidget *parent = 0);
    ~InstructorTaskForm();
    
private slots:


    void on_cancelButton_clicked();

    void on_okButton_clicked();

private:
    Ui::InstructorTaskForm *ui;
    QWidget *p;
};

#endif // INSTRUCTORTASKFORM_H
