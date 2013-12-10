#include "Course.h"

Course::Course(int id, const QString& name, const QString& code, int year, const QString& term) :
    _id(id),
    _name(name),
    _code(code),
    _year(year),
    _term(term) {}

int Course::id() const {
    return _id;
}

const QString& Course::name() const {
    return _name;
}

const QString& Course::code() const {
    return _code;
}

int Course::year() const {
    return _year;
}

const QString& Course::term() const {
    return _term;
}
