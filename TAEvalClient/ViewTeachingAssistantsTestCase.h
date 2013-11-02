#ifndef VIEWTEACHINGASSISTANTSTESTCASE_H
#define VIEWTEACHINGASSISTANTSTESTCASE_H

#include <QObject>
#include <vector>
#include "TeachingAssistant.h"
#include "Course.h"

class ViewTeachingAssistantsTestCase : public QObject {
    Q_OBJECT

public:
    ViewTeachingAssistantsTestCase();
    Course course() const;
    
signals:
    void complete(bool success) const;

public slots:
    void run(const std::vector<TeachingAssistant>& teachingAssistantList) const;
};

#endif // VIEWTEACHINGASSISTANTSTESTCASE_H
