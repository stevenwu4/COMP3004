#include "ViewTeachingAssistantsController.h"
#include "TAEval.h"
#include "ViewTeachingAssistantsTestCase.h"

ViewTeachingAssistantsController::ViewTeachingAssistantsController() {}

void ViewTeachingAssistantsController::invoke(TAEval* taEval, const ViewTeachingAssistantsTestCase* testCase) const {
    QObject::connect(taEval, SIGNAL(teachingAssistantListUpdated(const std::vector<TeachingAssistant>&)), testCase, SLOT(run(const std::vector<TeachingAssistant>&)));

    QObject::connect(taEval, SIGNAL(requestTimedOut()), testCase, SLOT(timeout()));

    taEval->requestTeachingAssistantList(testCase->course());
}
