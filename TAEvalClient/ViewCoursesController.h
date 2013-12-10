#ifndef VIEWCOURSESCONTROLLER_H
#define VIEWCOURSESCONTROLLER_H

#include <QObject>

class TAEval;

class ViewCoursesController : public QObject {
    Q_OBJECT

public:
    ViewCoursesController();

    void invoke() const;
};

#endif // VIEWCOURSESCONTROLLER_H
