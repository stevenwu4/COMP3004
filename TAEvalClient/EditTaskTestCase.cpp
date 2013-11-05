#include "EditTaskTestCase.h"
#include "Task.h"
#include <QTextStream>

EditTaskTestCase::EditTaskTestCase() {}

Task EditTaskTestCase::task() const {
    return Task(1, "Marking Exam", "correct midterm", "Good job", 5); //(234, "Do Something", "Do it well", "Good job", 5)
}

void EditTaskTestCase::run(const Task* task) const {
    QTextStream out (stdout);

    //Check to see that everything is edited properly
    if (!task) {
        out << "Task not found in database\n";
        emit complete(false, 4);
        return;
    }

    Task edittedTask = Task(1, "Marking Exam", "correct midterm", "Good job", 5);

    out << "\nEDIT TASK TEST CASE:\n";
    out << task->name() << endl;
    out << task->description() << endl;
    out << task->comment() << endl;
    out << task->rating() << endl;
    
    bool result = (match(task,edittedTask));

    emit complete(result,4);
}

void EditTaskTestCase::timeout() const {
    QTextStream out(stdout);
    out << "TEST CASE TIMED OUT!\n";

    emit complete(false, 4);
}

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
}
