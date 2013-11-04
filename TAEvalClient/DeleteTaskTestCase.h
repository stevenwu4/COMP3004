#ifndef DELETETASKTESTCASE_H
#define DELETETASKTESTCASE_H

#include <QObject>
#include "Task.h"

class Task;

class DeleteTaskTestCase : public QObject {
    Q_OBJECT

public:
    DeleteTaskTestCase();

    Task task() const;

signals:
    void complete(bool success,int testCase) const;

public slots:
    void run(bool success) const;
};

#endif // DELETETASKTESTCASE_H
