#include "ViewTeachingAssistantsTestCase.h"

ViewTeachingAssistantsTestCase::ViewTeachingAssistantsTestCase() {}

Course ViewTeachingAssistantsTestCase::course() const {
    return Course(1, "Software Engineering", "COMP3004", 2013, "Fall");
}

void ViewTeachingAssistantsTestCase::run(const std::vector<TeachingAssistant>& teachingAssistantList) const {
    //Check to see that everything in TA list is correct
    emit complete(false,1);
}
