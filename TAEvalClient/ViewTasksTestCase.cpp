#include "ViewTasksTestCase.h"

ViewTasksTestCase::ViewTasksTestCase() {}

Course ViewTasksTestCase::course() const {
    return Course(3434, "Software Enginerring", "COMP3004", 2013, "Fall");
}

TeachingAssistant ViewTasksTestCase::teachingAssistant() const {
    return TeachingAssistant(7707, "John", "Smith", "BCS", "Computer Science", 2);
}

void ViewTasksTestCase::run(const std::vector<Task>& taskList) const {
    //Check to see that everything in task list is correct

    emit complete(false,2);
}
