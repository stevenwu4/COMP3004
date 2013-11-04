#include "EditTaskController.h"
#include "TAEval.h"
#include "EditTaskTestCase.h"

EditTaskController::EditTaskController() {}

void EditTaskController::invoke(TAEval* taEval, const EditTaskTestCase* testCase) const {
    QObject::connect(taEval, SIGNAL(taskEdited(const Task*)), testCase, SLOT(run(const Task*)));

    taEval->editTask(testCase->task());
}
