#include "CreateTaskController.h"
#include "TAEval.h"
#include "CreateTaskTestCase.h"

CreateTaskController::CreateTaskController() {}

void CreateTaskController::invoke(TAEval* taEval, const CreateTaskTestCase* testCase) const {
    QObject::connect(taEval, SIGNAL(taskCreated(const Task*)), testCase, SLOT(run(const Task*)));

    QObject::connect(taEval, SIGNAL(requestTimedOut()), testCase, SLOT(timeout()));

    taEval->createTask(testCase->course(), testCase->teachingAssistant(), testCase->taskName(), testCase->taskDescription());
}
