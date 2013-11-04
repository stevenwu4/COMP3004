#ifndef VIEWCOURSESCONTROLLER_H
#define VIEWCOURSESCONTROLLER_H

#include <QObject>

class TAEval;
class ViewCoursesTestCase;

class ViewCoursesController : public QObject {
    Q_OBJECT

public:
    ViewCoursesController();

    void invoke(TAEval* taEval, const ViewCoursesTestCase* testCase) const;
};

#endif // VIEWCOURSESCONTROLLER_H
