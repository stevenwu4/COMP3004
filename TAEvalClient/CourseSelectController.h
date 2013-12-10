#ifndef COURSESELECTCONTROLLER_H
#define COURSESELECTCONTROLLER_H

#include <QObject>

class TAEval;
class CourseSelect;
class Course;

class CourseSelectController : public QObject {
    Q_OBJECT

private:
    CourseSelect* _courseSelect;
    TAEval* _taEval;

public:
    CourseSelectController(CourseSelect* semesterSelect, TAEval* taEval);
    void invoke(const Course& course) const;

private slots:
    void courseRetrieved();
    void timeout();
};

#endif // COURSESELECTCONTROLLER_H
