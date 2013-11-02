#ifndef VIEWTASKSCONTROLLER_H
#define VIEWTASKSCONTROLLER_H

#include <QObject>

class TAEval;
class ViewTasksTestCase;

class ViewTasksController : public QObject {
    Q_OBJECT

public:
    ViewTasksController();

    void invoke(TAEval* taEval, const ViewTasksTestCase* testCase) const;
};

#endif // VIEWTASKSCONTROLLER_H
