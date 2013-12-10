#include "SemesterSelectController.h"
#include "TAEval.h"
#include "semesterselect.h"
#include "CourseSelect.h"

SemesterSelectController::SemesterSelectController(SemesterSelect* semesterSelect, TAEval* taEval) :
    QObject(semesterSelect),
    _semesterSelect(semesterSelect),
    _taEval(taEval) {}

void SemesterSelectController::invoke() const {
    QObject::connect(_taEval, SIGNAL(courseListUpdated(std::vector<Course>)), this, SLOT(termRetrieved()));

    QObject::connect(_taEval, SIGNAL(requestTimedOut()), this, SLOT(timeout()));

    _taEval->requestCourseList("term", 1991);
}

void SemesterSelectController::termRetrieved() {
    //get course list of the selected semester
    CourseSelect *courseSelect = new CourseSelect(_semesterSelect, _taEval);
    _semesterSelect->close();
    courseSelect->show();
}

void SemesterSelectController::timeout() {

}
