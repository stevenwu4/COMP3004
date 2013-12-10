#ifndef EDITTASKCONTROLLER_H
#define EDITTASKCONTROLLER_H

#include <QObject>

class TAEval;

class EditTaskController : public QObject {
    Q_OBJECT

public:
    EditTaskController();

    void invoke() const;
};

#endif // EDITTASKCONTROLLER_H
