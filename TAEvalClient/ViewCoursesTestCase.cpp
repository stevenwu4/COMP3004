#include "ViewCoursesTestCase.h"
#include <QTextStream>
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

    QTextStream out(stdout);
    out << "Number of Courses  " << courseList.size() << endl;
    for (int i = 0; i < courseList.size(); i++){
        out << "Course Id " << courseList[i].id() << endl;
        out << "Course Name " << courseList[i].name() << endl;
        out << "Course Code " << courseList[i].code() << endl;
        out << "Year " << courseList[i].year() << endl;
        out << "Term " << courseList[i].term() << endl;
    }



    emit complete(result,0);
}
