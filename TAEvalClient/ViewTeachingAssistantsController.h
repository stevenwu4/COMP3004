#ifndef VIEWTEACHINGASSISTANTSCONTROLLER_H
#define VIEWTEACHINGASSISTANTSCONTROLLER_H

#include <QObject>

class TAEval;
class ViewTeachingAssistantsTestCase;

class ViewTeachingAssistantsController : public QObject {
    Q_OBJECT

public:
    ViewTeachingAssistantsController();
    
    void invoke(TAEval* taEval, const ViewTeachingAssistantsTestCase* testCase) const;
};

#endif // VIEWTEACHINGASSISTANTSCONTROLLER_H
