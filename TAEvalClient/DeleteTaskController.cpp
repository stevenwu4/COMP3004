#include "DeleteTaskController.h"
#include "TAEval.h"
#include "DeleteTaskTestCase.h"

DeleteTaskController::DeleteTaskController() {}

void DeleteTaskController::invoke(TAEval* taEval, const DeleteTaskTestCase* testCase) const {
    QObject::connect(taEval, SIGNAL(taskDeleted(bool)), testCase, SLOT(run(bool)));

    QObject::connect(taEval, SIGNAL(requestTimedOut()), testCase, SLOT(timeout()));

    taEval->deleteTask(testCase->task());
}
