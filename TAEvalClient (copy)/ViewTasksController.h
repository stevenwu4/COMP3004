#ifndef VIEWTASKSCONTROLLER_H
#define VIEWTASKSCONTROLLER_H

#include <QObject>

class TAEval;

class ViewTasksController : public QObject {
    Q_OBJECT

public:
    ViewTasksController();

    void invoke() const;
};

#endif // VIEWTASKSCONTROLLER_H
