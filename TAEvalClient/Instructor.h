#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <QString>

class Instructor {
private:
	int _id;
	QString _firstName, _lastName;
	QString department;

public:
	Instructor(int id, const QString& firstName, const QString& lastName, const QString& department)

	int id() const;
	const QString& firstName() const;
	const QString& lastName() const;
	const QString& department() const;
};

#endif // INSTRUCTOR_H