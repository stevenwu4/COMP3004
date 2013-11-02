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
};

#endif // TASK_H
