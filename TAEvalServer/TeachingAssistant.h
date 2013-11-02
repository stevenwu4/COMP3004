#ifndef TEACHINGASSISTANT_H
#define TEACHINGASSISTANT_H

#include <QString>

class TeachingAssistant {
private:
    int _id;
    QString _firstName, _lastName;
    QString _degree, _major;
    int _year;
public:
    TeachingAssistant(int id, const QString& firstName, const QString& lastName, const QString& degree, const QString& major, int year);

    int id() const;
    QString getFirstName();
    QString getLastName();
    QString getDegree();
    QString getMajor();
    int getYear();
};

#endif // TEACHINGASSISTANT_H
