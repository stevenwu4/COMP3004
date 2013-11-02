#include "ViewCoursesTestCase.h"

ViewCoursesTestCase::ViewCoursesTestCase() {}

int ViewCoursesTestCase::year() const {
    return 2009;
}

QString ViewCoursesTestCase::term() const {
    return "Fall";
}

void ViewCoursesTestCase::run(const std::vector<Course>& courseList) const {
    //Check to see that everything in courseList is correct
    emit complete(true);
}
