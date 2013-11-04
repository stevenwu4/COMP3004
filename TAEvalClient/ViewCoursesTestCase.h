#ifndef VIEWCOURSESTESTCASE_H
#define VIEWCOURSESTESTCASE_H

#include <QObject>
#include <vector>
#include "Course.h"

class ViewCoursesTestCase : public QObject {
    Q_OBJECT

public:
    ViewCoursesTestCase();

    int year() const;
    QString term() const;

signals:
    void complete(bool success,int testCase) const;

public slots:
    void run(const std::vector<Course>& courseList) const;
};

#endif // VIEWCOURSESTESTCASE_H
