#include "DeleteTaskTestCase.h"

DeleteTaskTestCase::DeleteTaskTestCase() {}

Task DeleteTaskTestCase::task() const {
    return Task(20, "Marking Project", "evaluate projects", QString(), -1); //(384, "Grade Midterms", "Grade all the midterms by November 15th", QString(), -1)
}

void DeleteTaskTestCase::run(bool success) const {
    //should we try to grab the task from the database to show it's not there anymore?
    emit complete(success,6);
}
