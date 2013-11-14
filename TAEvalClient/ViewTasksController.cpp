#include "ViewTasksController.h"
#include "TAEval.h"
#include "ViewTasksTestCase.h"

ViewTasksController::ViewTasksController() {}

void ViewTasksController::invoke(TAEval* taEval, const ViewTasksTestCase* testCase) const {
    QObject::connect(taEval, SIGNAL(taskListUpdated(const std::vector<Task>&)), testCase, SLOT(run(const std::vector<Task>&)));

    QObject::connect(taEval, SIGNAL(requestTimedOut()), testCase, SLOT(timeout()));

    taEval->requestTaskList(testCase->course(), testCase->teachingAssistant());
}
