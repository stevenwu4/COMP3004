#include "ViewTasksTestCase.h"
#include <QTextStream>

ViewTasksTestCase::ViewTasksTestCase() {}

Course ViewTasksTestCase::course() const {
    return Course(2, "Software Enginerring", "COMP3004", 2013, "Fall");
}

TeachingAssistant ViewTasksTestCase::teachingAssistant() const {
    return TeachingAssistant(100, "John", "Smith", "BCS", "Computer Science", 2);
}

void ViewTasksTestCase::run(const std::vector<Task>& taskList) const {
    //Check to see that everything in task list is correct
    QTextStream out(stdout);
    out << "Number of Tasks  " << taskList.size() << endl;
    for (int i = 0; i < taskList.size(); i++){
        out << "Task Id " << taskList[i].id() << endl;
        out << "Task Name " << taskList[i].name() << endl;
        out << "Task Desc " << taskList[i].description() << endl;
        out << "Eval Desc " << taskList[i].comment() << endl;
        out << "Eval Rank " << taskList[i].rating() << endl;
    }
    emit complete(false,2);
}
