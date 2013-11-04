#include "CreateTaskTestCase.h"
#include "Task.h"
#include <QTextStream>

CreateTaskTestCase::CreateTaskTestCase() {}

Course CreateTaskTestCase::course() const {
    return Course(4, "Virtual Reality", "COMP4401", 2007, "Winter"); //(3434, "Software Enginerring", "COMP3004", 2013, "Fall")
}

TeachingAssistant CreateTaskTestCase::teachingAssistant() const {
    return TeachingAssistant(104, "Palmer", "Luckey", "BSc", "Computer Science", 4); //(7707, "John", "Smith", "BCS", "Computer Science", 2)
}

QString CreateTaskTestCase::taskName() const {
    return "Marking Project"; //Grade Midterms
}

QString CreateTaskTestCase::taskDescription() const {
    return "evaluate projects";
}

void CreateTaskTestCase::run(const Task* task) const {
    //Check to see that everything in the new task is correct

    Task palmerTask(1,"Marking Project","evaluate projects", NULL, -1);
    QTextStream out (stdout);
    out << task->id() << endl;
    out << task->name() << endl;
    out << task->description() << endl;
    out << task->comment() << endl;
    out << task->rating() << endl;

    bool result = (match(task,palmerTask));

    emit complete(result,3);
}

bool CreateTaskTestCase::match(const Task* actual, Task& expected) const{
    bool result = true;
    QTextStream out (stdout);

    /* //can't check id since it increments when button is pressed and this client allows multiple tasks with same name
    if(expected.id() != actual->id()) {
        result = false;
        out << "task id from database doesn't match expected" << endl;
    }
    */

    if(expected.name() != actual->name()) {
        result = false;
        out << "task name from database doesn't match expected" << endl;
    }

    if(expected.description() != actual->description()) {
        result = false;
        out << "task description from database doesn't match expected" << endl;
    }

    if(expected.comment() != actual->comment()) {
        result = false;
        out << "evaluation comment from database doesn't match expected" << endl;
    }

    if(expected.rating() != actual->rating()) {
        result = false;
        out << "evaluation rating from database doesn't match expected" << endl;
    }

    return result;
}

