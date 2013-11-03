#ifndef TASK_H
#define TASK_H

#include <QString>

class Task  {
private:
    int _id;
    QString _name, _description, _comment;
    int _rating;

public:
    Task(int id, const QString& name, const QString& description, const QString& comment, int rating);

    int id() const;
    const QString& name() const;
    const QString& description() const;
    const QString& comment() const;
    int rating() const;
};

#endif // TASK_H
