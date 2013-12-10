#ifndef CREATETASKCONTROLLER_H
#define CREATETASKCONTROLLER_H

#include <QObject>

class TAEval;
class TaskSelect;
class TeachingAssistant;

class CreateTaskController : public QObject {
    Q_OBJECT

private:
    TaskSelect* _taskSelect;
    TAEval* _taEval;

public:
    CreateTaskController(TaskSelect* taskSelect, TAEval* taEval);
    void invoke(const TeachingAssistant&) const;

private slots:
    void taskCreated();
    void timeout();
};

#endif // CREATETASKCONTROLLER_H
