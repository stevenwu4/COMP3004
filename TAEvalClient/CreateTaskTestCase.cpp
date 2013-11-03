#include "CreateTaskTestCase.h"
#include "Task.h"

CreateTaskTestCase::CreateTaskTestCase() {}

Course CreateTaskTestCase::course() const {
    return Course(3434, "Software Enginerring", "COMP3004", 2013, "Fall");
}

TeachingAssistant CreateTaskTestCase::teachingAssistant() const {
    return TeachingAssistant(7707, "John", "Smith", "BCS", "Computer Science", 2);
}

QString CreateTaskTestCase::taskName() const {
    return "Grade Midterms";
}

QString CreateTaskTestCase::taskDescription() const {
    return "Grade all the midterms in your tutorial section by November 13th";
}

void CreateTaskTestCase::run(const Task* task) const {
    //Check to see that everything in the new task is correct
    emit complete(true,3);
}
