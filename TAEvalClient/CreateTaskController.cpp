#include "CreateTaskController.h"
#include "TAEval.h"
#include "TaskSelect.h"
#include "InstructorTaskForm.h"


CreateTaskController::CreateTaskController(TaskSelect* taskSelect, TAEval* taEval) :
    QObject(taskSelect),
    _taskSelect(taskSelect),
    _taEval(taEval) {}

void CreateTaskController::invoke(const TeachingAssistant& ta) const
{
    QObject::connect(_taEval, SIGNAL(taskCreated(bool)), this, SLOT(taskCreated()));

    QObject::connect(_taEval, SIGNAL(requestTimedOut()), this, SLOT(timeout()));

    _taEval->createTask(*_taEval->currentCourse(),ta , "", "");

}

void CreateTaskController::taskCreated()
{
    QObject::disconnect(_taEval, SIGNAL(taskCreated(bool)), this, SLOT(taskCreated()));

    QObject::disconnect(_taEval, SIGNAL(requestTimedOut()), this, SLOT(timeout()));

    InstructorTaskForm *taskForm = new InstructorTaskForm(_taskSelect, _taEval);
    _taskSelect->close();
    taskForm->show();

}


void CreateTaskController::timeout()
{

}
