#include "TeachingAssistant.h"

TeachingAssistant::TeachingAssistant(int id, const QString& firstName, const QString& lastName, const QString& degree, const QString& major, int year) :
    _id(id),
    _firstName(firstName),
    _lastName(lastName),
    _degree(degree),
    _major(major),
    _year(year) {}

int TeachingAssistant::id() const {
    return _id;
}
