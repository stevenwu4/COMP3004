#include "ViewCoursesTestCase.h"
#include <QTextStream>
ViewCoursesTestCase::ViewCoursesTestCase() {}

int ViewCoursesTestCase::year() const {
    return 2007; //2009
}

QString ViewCoursesTestCase::term() const {
    return "Winter"; //Fall
}

void ViewCoursesTestCase::run(const std::vector<Course>& courseList) const {
    //Check to see that everything in courseList is correct
    Course comp4002(3, "3D Game Engines", "COMP4002", 2007, "Winter");
    Course comp4401(4, "Virtual Reality", "COMP4401", 2007, "Winter");
    Course engl9999(5, "Deep Thoughts", "ENGL9999", 2007, "Winter");
    Course engl3304(6, "Comedic Writing", "ENGL3304", 2007, "Winter");

    QTextStream out(stdout);
    out << "\nVIEW COURSES TEST CASE:\n";
    out << "Number of Courses  " << courseList.size() << endl;
    for (size_t i = 0; i < courseList.size(); i++){
        out << "Course Id " << courseList[i].id() << endl;
        out << "Course Name " << courseList[i].name() << endl;
        out << "Course Code " << courseList[i].code() << endl;
        out << "Year " << courseList[i].year() << endl;
        out << "Term " << courseList[i].term() << endl;
    }

    bool result =
        (courseList.size() == 4 &&
        match(courseList[0],comp4002) &&
        match(courseList[1],comp4401) &&
        match(courseList[2],engl9999) &&
        match(courseList[3],engl3304));

    emit complete(result, 0);
}

void ViewCoursesTestCase::timeout() const {
    QTextStream out(stdout);
    out << "TEST CASE TIMED OUT!\n";

    emit complete(false, 0);
}

bool ViewCoursesTestCase::match(const Course& actual, Course& expected) const {
    bool result = true;
    QTextStream out(stdout);

    if(expected.id() != actual.id()) {
        result = false;
        out << "course id from database doesn't match expected" << endl;
    }

    if(expected.name() != actual.name()) {
        result = false;
        out << "course name from database doesn't match expected" << endl;
    }

    if(expected.code() != actual.code()) {
        result = false;
        out << "course code from database doesn't match expected" << endl;
    }

    if(expected.year() != actual.year()) {
        result = false;
        out << "course year from database doesn't match expected" << endl;
    }

    if(expected.term() != actual.term()) {
        result = false;
        out << "course term from database doesn't match expected" << endl;
    }

    return result;
}
