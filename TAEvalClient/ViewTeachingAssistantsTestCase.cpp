#include "ViewTeachingAssistantsTestCase.h"
#include <QTextStream>
ViewTeachingAssistantsTestCase::ViewTeachingAssistantsTestCase() {}

Course ViewTeachingAssistantsTestCase::course() const {
    return Course(5, "Deep Thoughts", "ENGL9999", 2007, "Winter"); //(1, "Software Engineering", "COMP3004", 2013, "Fall")
}

void ViewTeachingAssistantsTestCase::run(const std::vector<TeachingAssistant>& teachingAssistantList) const {
    //Check to see that everything in TA list is correct

    TeachingAssistant steveMartin(101, "Steve", "Martin", "M.A.", "English", 2);
    TeachingAssistant michaelNesmith(102, "Michael", "Nesmith", "M.A.", "English", 1);

    //TeachingAssistant
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

    //only prints out last TA added to course?

    bool result = (teachingAssistantList.size() == 2 &&
                   match(teachingAssistantList[0],steveMartin) &&
                   match(teachingAssistantList[1],michaelNesmith));

    emit complete(result,1);
}

bool ViewTeachingAssistantsTestCase::match(const TeachingAssistant& actual, TeachingAssistant& expected) const {
    bool result = true;
    QTextStream out(stdout);

    if(expected.id() != actual.id()) {
        result = false;
        out << "teaching assistant id from database doesn't match expected" << endl;
    }

    if(expected.firstName() != actual.firstName()) {
        result = false;
        out << "teaching assistant first name from database doesn't match expected" << endl;
    }

    if(expected.lastName() != actual.lastName()) {
        result = false;
        out << "teaching assistant last name description from database doesn't match expected" << endl;
    }

    if(expected.degree() != actual.degree()) {
        result = false;
        out << "teaching assistant degree from database doesn't match expected" << endl;
    }

    if(expected.major() != actual.major()) {
        result = false;
        out << "teaching assistant major from database doesn't match expected" << endl;
    }

    if(expected.year() != actual.year()) {
        result = false;
        out << "teaching assistant year from database doesn't match expected" << endl;
    }

    return result;
}
