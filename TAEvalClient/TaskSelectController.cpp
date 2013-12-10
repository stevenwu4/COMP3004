#include "TaskSelectController.h"
#include "TaskSelect.h"
#include "TAEval.h"
#include "InstructorTaskForm.h"
#include "TATaskForm.h"
#include "semesterselect.h"
#include "CourseSelect.h"
#include "Task.h"

TaskSelectController::TaskSelectController(TaskSelect* taskSelect, TAEval* taEval) :
    QObject(taskSelect),
    _taskSelect(taskSelect),
    _taEval(taEval) {}

void TaskSelectController::invoke(const Task& task) const
{

    /*
    QObject::connect(_taEval, SIGNAL(taskUpdated(const Task*)), this, SLOT(taskRetrieved()));

    QObject::connect(_taEval, SIGNAL(requestTimedOut()), this, SLOT(timeout()));

    _taEval->updateTask
    */
}

void TaskSelectController::taskRetrieved()
{
    QObject::disconnect(_taEval, SIGNAL(taskListUpdated(std::vector<Task>)), this, SLOT(taskRetrieved()));

    QObject::disconnect(_taEval, SIGNAL(requestTimedOut()), this, SLOT(timeout()));

    InstructorTaskForm *taskForm = new InstructorTaskForm(_taskSelect, _taEval);
    _taskSelect->close();
    taskForm->show();
}


void TaskSelectController::timeout()
{

}
