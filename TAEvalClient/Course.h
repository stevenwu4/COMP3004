#ifndef COURSE_H
#define COURSE_H

#include <QString>

class Course {
private:
    int _id;
    QString _name, _code;
    int _year;
    QString _term;

public:
    Course(int id, const QString& name, const QString& code, int year, const QString& term);

    int id() const;
    const QString& name() const;
    const QString& code() const;
    int year() const;
    const QString& term() const;
};

#endif // COURSE_H
