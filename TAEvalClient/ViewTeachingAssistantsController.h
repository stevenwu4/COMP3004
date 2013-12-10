#ifndef VIEWTEACHINGASSISTANTSCONTROLLER_H
#define VIEWTEACHINGASSISTANTSCONTROLLER_H

#include <QObject>

class TAEval;

class ViewTeachingAssistantsController : public QObject {
    Q_OBJECT

public:
    ViewTeachingAssistantsController();
    
    void invoke() const;
};

#endif // VIEWTEACHINGASSISTANTSCONTROLLER_H
