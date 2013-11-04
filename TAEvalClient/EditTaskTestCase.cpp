#include "EditTaskTestCase.h"
#include "Task.h"

EditTaskTestCase::EditTaskTestCase() {}

Task EditTaskTestCase::task() const {
    return Task(234, "Do Something", "Do it well", "Good job", 5);
}

void EditTaskTestCase::run(const Task* task) const {
    //Check to see that everything is edited properly
    emit complete(true,4);
    emit complete(false,5);
}
