#ifndef DELETETASKCONTROLLER_H
#define DELETETASKCONTROLLER_H

#include <QObject>

class TAEval;
class DeleteTaskTestCase;

class DeleteTaskController : public QObject {
    Q_OBJECT

public:
    DeleteTaskController();

    void invoke(TAEval* taEval, const DeleteTaskTestCase* testCase) const;
};

#endif // DELETETASKCONTROLLER_H
