#include "Task.h"

Task::Task(int id, const QString& name, const QString& description, const QString& comment, int rating) :
    _id(id),
    _name(name),
    _description(description),
    _comment(comment),
    _rating(rating) {}
