#ifndef EDITTASKCONTROLLER_H
#define EDITTASKCONTROLLER_H

#include <QObject>

class TAEval;
class EditTaskTestCase;

class EditTaskController : public QObject {
    Q_OBJECT

public:
    EditTaskController();

    void invoke(TAEval* taEval, const EditTaskTestCase* testCase) const;
};

#endif // EDITTASKCONTROLLER_H
