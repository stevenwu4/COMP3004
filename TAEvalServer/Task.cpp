#include "Task.h"

Task::Task(int id, const QString& name, const QString& description, const QString& comment, int rating) :
    _id(id),
    _name(name),
    _description(description),
    _comment(comment),
    _rating(rating) {}

int Task::id() const {
    return _id;
}

const QString& Task::name() const {
    return _name;
}

const QString& Task::description() const {
    return _description;
}

const QString& Task::comment() const {
    return _comment;
}

int Task::rating() const {
    return _rating;
}
