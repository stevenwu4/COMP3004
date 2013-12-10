#ifndef TASKSELECTCONTROLLER_H
#define TASKSELECTCONTROLLER_H

#include <QObject>

class TAEval;
class TaskSelect;
class Task;

class TaskSelectController : public QObject {
    Q_OBJECT

private:
    TaskSelect* _taskSelect;
    TAEval* _taEval;

public:
    TaskSelectController(TaskSelect* taskSelect, TAEval* taEval);
    void invoke(const Task& task) const;

private slots:
    void taskRetrieved();
    void timeout();
};



#endif // TASKSELECTCONTROLLER_H
