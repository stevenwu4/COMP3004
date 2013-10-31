#include "ViewCoursesController.h"
#include "TAEval.h"
#include "ViewCoursesTestCase.h"

ViewCoursesController::ViewCoursesController() {}

void ViewCoursesController::invoke(TAEval* taEval, const ViewCoursesTestCase* testCase) const {
    QObject::connect(taEval, SIGNAL(courseListUpdated(const std::vector<Course>&)), testCase, SLOT(run(const std::vector<Course>&)));

    taEval->requestCourseList(testCase->term(), testCase->year());
}

