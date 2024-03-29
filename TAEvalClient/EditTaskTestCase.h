#ifndef EDITTASKTESTCASE_H
#define EDITTASKTESTCASE_H

#include <QObject>
#include <QString>
#include "Course.h"
#include "TeachingAssistant.h"

class Task;

class EditTaskTestCase : public QObject {
    Q_OBJECT

public:
    EditTaskTestCase();

    Task task() const;
    bool match(const Task*, Task&) const;

signals:
    void complete(bool success,int testCase) const;

public slots:
    void run(const Task* task) const;
    void timeout() const;
};

#endif // EDITTASKTESTCASE_H
