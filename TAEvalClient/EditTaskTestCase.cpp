#include "EditTaskTestCase.h"
#include "Task.h"
#include <QTextStream>

EditTaskTestCase::EditTaskTestCase() {}

Task EditTaskTestCase::task() const {
    return Task(234, "Do Something", "Do it well", "Good job", 5); //(234, "Do Something", "Do it well", "Good job", 5)
}

void EditTaskTestCase::run(const Task* task) const {
    //Check to see that everything is edited properly

    Task edittedTask = Task(234, "Do Something", "Do it well", "Good job", 5);

    //dereferencing task crashes the client?

    /*
    QTextStream out (stdout);
    out << task->name() << endl;
    out << task->description() << endl;
    out << task->comment() << endl;
    out << task->rating() << endl;
    */
    //bool result = (match(task,edittedTask));

    bool result;
    emit complete(result,4);

    //the following complete signal is redundant, we rolled edit and evaluate into one button
    //emit complete(result,5);
}
/*
bool EditTaskTestCase::match(const Task* actual, Task& expected) const {
    bool result = true;

    QTextStream out (stdout);

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
}*/
