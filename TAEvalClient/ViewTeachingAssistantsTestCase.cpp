#include "ViewTeachingAssistantsTestCase.h"
#include <QTextStream>
ViewTeachingAssistantsTestCase::ViewTeachingAssistantsTestCase() {}

Course ViewTeachingAssistantsTestCase::course() const {
    return Course(1, "Software Engineering", "COMP3004", 2013, "Fall");
}

void ViewTeachingAssistantsTestCase::run(const std::vector<TeachingAssistant>& teachingAssistantList) const {
    //Check to see that everything in TA list is correct
    QTextStream out(stdout);
    out << "Number of TAs  " << teachingAssistantList.size() << endl;
    for (int i = 0; i < teachingAssistantList.size(); i++){
        out << "TA Id " << teachingAssistantList[i].id() << endl;
        out << "First Name " << teachingAssistantList[i].firstName() << endl;
        out << "Last Name " << teachingAssistantList[i].lastName() << endl;
        out << "Degree " << teachingAssistantList[i].degree() << endl;
        out << "Major " << teachingAssistantList[i].major() << endl;
        out << "Year " << teachingAssistantList[i].year() << endl;
    }


    emit complete(false,1);
}
