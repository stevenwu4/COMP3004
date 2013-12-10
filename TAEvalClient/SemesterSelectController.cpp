#include "SemesterSelectController.h"
#include "TAEval.h"
#include "semesterselect.h"
#include "CourseSelect.h"
#include "Term.h"

SemesterSelectController::SemesterSelectController(SemesterSelect* semesterSelect, TAEval* taEval) :
    QObject(semesterSelect),
    _semesterSelect(semesterSelect),
    _taEval(taEval) {}

void SemesterSelectController::invoke(const Term& term) const {
    QObject::connect(_taEval, SIGNAL(courseListUpdated(std::vector<Course>)), this, SLOT(termRetrieved()));

    QObject::connect(_taEval, SIGNAL(requestTimedOut()), this, SLOT(timeout()));

    _taEval->requestCourseList(term.season(), term.year());
}

void SemesterSelectController::termRetrieved() {
    QObject::disconnect(_taEval, SIGNAL(courseListUpdated(std::vector<Course>)), this, SLOT(termRetrieved()));

    QObject::disconnect(_taEval, SIGNAL(requestTimedOut()), this, SLOT(timeout()));
    CourseSelect *courseSelect = new CourseSelect(_semesterSelect, _taEval);
    _semesterSelect->close();
    courseSelect->show();
}

void SemesterSelectController::timeout() {

}
