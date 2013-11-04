#ifndef CREATETASKTESTCASE_H
#define CREATETASKTESTCASE_H

#include <QObject>
#include <QString>
#include "Course.h"
#include "TeachingAssistant.h"

class Task;

class CreateTaskTestCase : public QObject {
    Q_OBJECT

public:
    CreateTaskTestCase();

    Course course() const;
    TeachingAssistant teachingAssistant() const;
    QString taskName() const;
    QString taskDescription() const;
    bool match(const Task*, Task&) const;

signals:
    void complete(bool success,int testCase) const;

public slots:
    void run(const Task* task) const;
};

#endif // CREATETASKTESTCASE_H
