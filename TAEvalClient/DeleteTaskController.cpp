#include "DeleteTaskController.h"
#include "TAEval.h"
#include "DeleteTaskTestCase.h"

DeleteTaskController::DeleteTaskController() {}

void DeleteTaskController::invoke(TAEval* taEval, const DeleteTaskTestCase* testCase) const {
    QObject::connect(taEval, SIGNAL(taskDeleted(bool)), testCase, SLOT(run(bool)));

    taEval->deleteTask(testCase->task());
}
