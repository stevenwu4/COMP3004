#ifndef INSTRUCTORTASKFORMCONTROLLER_H
#define INSTRUCTORTASKFORMCONTROLLER_H

#include <QObject>

class TAEval;
class InstructorTaskForm;
class Course;

class InstructorTaskFormController : public QObject {
    Q_OBJECT

private:
    InstructorTaskForm* _taskForm;
    TAEval* _taEval;

public:
    InstructorTaskFormController(InstructorTaskForm* taskForm, TAEval* taEval);
    void invoke() const;

private slots:
    void finished();
    void timeout();
};

#endif // INSTRUCTORTASKFORMCONTROLLER_H
