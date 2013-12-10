#include "Instructor.h"

Instructor::Instructor(int id, const QString& firstName, const QString& lastName, const QString& department) :
	_id(id),
	_firstName(firstName),
	_lastName(lastName),
	_department(department) {}

int Instructor::id() const {
	return _id;
}

const QString& Instructor::firstName() const {
	return _firstName;
}

const QString& Instructor::lastName() const {
	return _lastName;
}

const QString& Instructor::department() const {
    return _department;
}
