#include "CourseSelectController.h"
#include "TAEval.h"
#include "CourseSelect.h"
#include "TaskSelect.h"
#include "Course.h"

CourseSelectController::CourseSelectController(CourseSelect* courseSelect, TAEval* taEval) :
    QObject(courseSelect),
    _courseSelect(courseSelect),
    _taEval(taEval),
    _course(0) {}

void CourseSelectController::invoke(const Course& course) {
    QObject::connect(_taEval, SIGNAL(requestTimedOut()), this, SLOT(timeout()));
    _taEval->setCurrentCourse(const_cast<Course*>(&course));
    QObject::connect(_taEval, SIGNAL(teachingAssistantListUpdated(std::vector<TeachingAssistant>)), this, SLOT(taListRetrieved()));

    _course = &course;
    _taEval->requestTeachingAssistantList(course);
}

void CourseSelectController::taListRetrieved() {
    QObject::disconnect(_taEval, SIGNAL(teachingAssistantListUpdated(std::vector<TeachingAssistant>)), this, SLOT(taListRetrieved()));
    QObject::connect(_taEval, SIGNAL(taskListUpdated(std::vector<Task>)), this, SLOT(courseRetrieved()));
    _taEval->requestTaskList(*_course);
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
