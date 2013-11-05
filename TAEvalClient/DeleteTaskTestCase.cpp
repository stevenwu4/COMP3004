#include "DeleteTaskTestCase.h"
#include <QTextStream>

DeleteTaskTestCase::DeleteTaskTestCase() {}

Task DeleteTaskTestCase::task() const {
    return Task(20, "Marking Project", "evaluate projects", QString(), -1); //(384, "Grade Midterms", "Grade all the midterms by November 15th", QString(), -1)
}

void DeleteTaskTestCase::run(bool success) const {
    QTextStream out (stdout);
    out << "\nDELETE TASK TEST CASE:\n";
    out << success << "\n";

    emit complete(success,6);
}

void DeleteTaskTestCase::timeout() const {
    QTextStream out(stdout);
    out << "TEST CASE TIMED OUT!\n";

    emit complete(false, 6);
}
