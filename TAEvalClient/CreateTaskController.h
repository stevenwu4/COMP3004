#ifndef CREATETASKCONTROLLER_H
#define CREATETASKCONTROLLER_H

#include <QObject>

class TAEval;
class CreateTaskTestCase;

class CreateTaskController : public QObject {
    Q_OBJECT

public:
    CreateTaskController();

    void invoke(TAEval* taEval, const CreateTaskTestCase* testCase) const;
};

#endif // CREATETASKCONTROLLER_H
