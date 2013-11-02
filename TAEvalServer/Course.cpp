#include "Course.h"

Course::Course(int id, const QString &name, const QString &code, int year, const QString &term) :
    _id(id),
    _name(name),
    _code(code),
    _year(year),
    _term(term) {}

int Course::id() const {
    return _id;
}

QString Course::getCourseName(){
    return _name;
}

QString Course::getCourseCode(){
    return _code;
}

int Course::getYear(){
    return _year;
}

QString Course::getTerm(){
    return _term;
}
