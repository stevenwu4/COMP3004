#ifndef VIEWTASKSTESTCASE_H
#define VIEWTASKSTESTCASE_H

#include <QObject>
#include <vector>
#include "Task.h"
#include "Course.h"
#include "TeachingAssistant.h"

class ViewTasksTestCase : public QObject {
    Q_OBJECT

public:
    ViewTasksTestCase();

    Course course() const;
    TeachingAssistant teachingAssistant() const;

signals:
    void complete(bool success, int testCase) const;

public slots:
    void run(const std::vector<Task>& taskList) const;
};

#endif // VIEWTASKSTESTCASE_H
