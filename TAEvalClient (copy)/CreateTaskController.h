#ifndef CREATETASKCONTROLLER_H
#define CREATETASKCONTROLLER_H

#include <QObject>

class TAEval;

class CreateTaskController : public QObject {
    Q_OBJECT

public:
    CreateTaskController();

    void invoke() const;
};

#endif // CREATETASKCONTROLLER_H
