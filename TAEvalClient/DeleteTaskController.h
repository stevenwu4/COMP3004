#ifndef DELETETASKCONTROLLER_H
#define DELETETASKCONTROLLER_H

#include <QObject>

class TAEval;

class DeleteTaskController : public QObject {
    Q_OBJECT

public:
    DeleteTaskController();

    void invoke() const;
};

#endif // DELETETASKCONTROLLER_H
