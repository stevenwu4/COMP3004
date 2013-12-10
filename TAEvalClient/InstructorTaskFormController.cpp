#include "InstructorTaskFormController.h"
#include "TAEval.h"
#include "InstructorTaskForm.h"
#include "TaskSelect.h"
#include "Course.h"

InstructorTaskFormController::InstructorTaskFormController(InstructorTaskForm* taskForm, TAEval* taEval) :
    QObject(taskForm),
    _taskForm(taskForm),
    _taEval(taEval) {}

void InstructorTaskFormController::invoke() const {
    QObject::connect(_taEval, SIGNAL(taskEdited(const Task*)), this, SLOT(finished()));

    QObject::connect(_taEval, SIGNAL(requestTimedOut()), this, SLOT(timeout()));

    _taEval->editTask(_taskForm->task());
}

void InstructorTaskFormController::finished() {
    QObject::disconnect(_taEval, SIGNAL(taskEdited(const Task*)), this, SLOT(finished()));
    QObject::disconnect(_taEval, SIGNAL(requestTimedOut()), this, SLOT(timeout()));

    TaskSelect *taskSelect = new TaskSelect(_taskForm, _taEval);
    _taskForm->close();
    taskSelect->show();
}

void InstructorTaskFormController::timeout() {

}
