#include "ViewTasksTestCase.h"
#include <QTextStream>

ViewTasksTestCase::ViewTasksTestCase() {}

Course ViewTasksTestCase::course() const {
    return Course(5, "Deep Thoughts", "ENGL9999", 2007, "Winter"); //(2, "Software Enginerring", "COMP3004", 2013, "Fall")
}

TeachingAssistant ViewTasksTestCase::teachingAssistant() const {
    return TeachingAssistant(101, "Steve", "Martin", "M.A.", "English", 2); //(100, "John", "Smith", "BCS", "Computer Science", 2)
}

void ViewTasksTestCase::run(const std::vector<Task>& taskList) const {
    //Check to see that everything in task list is correct

    Task steveTask(6, "Tutorial", "organize tutorial", "Well organized!", 5);

    QTextStream out(stdout);
    out << "Number of Tasks  " << taskList.size() << endl;
    for (int i = 0; i < taskList.size(); i++){
        out << "Task Id " << taskList[i].id() << endl;
        out << "Task Name " << taskList[i].name() << endl;
        out << "Task Desc " << taskList[i].description() << endl;
        out << "Eval Desc " << taskList[i].comment() << endl;
        out << "Eval Rank " << taskList[i].rating() << endl;
    }

    bool result = (taskList.size() == 1 &&
                   match(taskList[0],steveTask));


    emit complete(result,2);
}

bool ViewTasksTestCase::match(const Task& actual, Task& expected) const {
    bool result = true;
    QTextStream out(stdout);

    if(expected.id() != actual.id()) {
        result = false;
        out << "task id from database doesn't match expected" << endl;
    }

    if(expected.name() != actual.name()) {
        result = false;
        out << "task name from database doesn't match expected" << endl;
    }

    if(expected.description() != actual.description()) {
        result = false;
        out << "task description from database doesn't match expected" << endl;
    }

    if(expected.comment() != actual.comment()) {
        result = false;
        out << "task comment from database doesn't match expected" << endl;
    }

    if(expected.rating() != actual.rating()) {
        result = false;
        out << "task rating from database doesn't match expected" << endl;
    }
    return result;
}
