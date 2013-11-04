#include "CreateTaskController.h"
#include "TAEval.h"
#include "CreateTaskTestCase.h"

CreateTaskController::CreateTaskController() {}

void CreateTaskController::invoke(TAEval* taEval, const CreateTaskTestCase* testCase) const {
    QObject::connect(taEval, SIGNAL(taskCreated(const Task*)), testCase, SLOT(run(const Task*)));

    taEval->createTask(testCase->course(), testCase->teachingAssistant(), testCase->taskName(), testCase->taskDescription());
}
