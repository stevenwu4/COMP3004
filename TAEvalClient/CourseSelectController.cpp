#include "CourseSelectController.h"
#include "TAEval.h"
#include "CourseSelect.h"
#include "TaskSelect.h"
#include "Course.h"

CourseSelectController::CourseSelectController(CourseSelect* courseSelect, TAEval* taEval) :
    QObject(courseSelect),
    _courseSelect(courseSelect),
    _taEval(taEval) {}

void CourseSelectController::invoke(const Course& course) const {
    QObject::connect(_taEval, SIGNAL(taskListUpdated(std::vector<Task>)), this, SLOT(courseRetrieved()));

    QObject::connect(_taEval, SIGNAL(requestTimedOut()), this, SLOT(timeout()));

    _taEval->requestTaskList(course);
}

void CourseSelectController::courseRetrieved() {
    QObject::disconnect(_taEval, SIGNAL(taskListUpdated(std::vector<Task>)), this, SLOT(courseRetrieved()));
    QObject::disconnect(_taEval, SIGNAL(requestTimedOut()), this, SLOT(timeout()));

    TaskSelect *taskSelect = new TaskSelect(_courseSelect, _taEval);
    _courseSelect->close();
    taskSelect->show();
}

void CourseSelectController::timeout() {

}
