#include "DeleteTaskTestCase.h"

DeleteTaskTestCase::DeleteTaskTestCase() {}

Task DeleteTaskTestCase::task() const {
    return Task(384, "Grade Midterms", "Grade all the midterms by November 15th", QString(), -1);
}

void DeleteTaskTestCase::run(bool success) const {
    emit complete(true,6);
}
