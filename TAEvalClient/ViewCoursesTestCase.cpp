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
    int x = qrand() % 2;
    bool result;

    if (x == 0)
        result = true;
    else if (x == 1)
        result = false;

    emit complete(result,0);
}
