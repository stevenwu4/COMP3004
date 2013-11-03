#ifndef TAEVAL_H
#define TAEVAL_H

#include <QObject>
#include <QString>
#include <QtNetwork/QTcpSocket>
#include <vector>
#include "Course.h"
#include "TeachingAssistant.h"
#include "Task.h"

class NetworkConnection;

class TAEval : public QObject {
    Q_OBJECT

private:
    const QString _hostname;
    const unsigned short _port;

    QTcpSocket* _socket;
    NetworkConnection* _network;

private:
    std::vector<Course> _courseList;
    std::vector<TeachingAssistant> _teachingAssistantList;
    std::vector<Task> _taskList;
    Task* _currentTask;

    void clearClientState();

public:
    TAEval();
    ~TAEval();

    void requestCourseList(const QString& term, int year);
    void requestTeachingAssistantList(const Course& course);
    void requestTaskList(const Course& course, const TeachingAssistant& teachingAssistant);
    void createTask(const Course& course, const TeachingAssistant& teachingAssistant, const QString& taskName, const QString& taskDescription);
    void deleteTask(const Task& task);
    void editTask(const Task& task);

signals:
    void courseListUpdated(const std::vector<Course>& courseList);
    void teachingAssistantListUpdated(const std::vector<TeachingAssistant>& teachingAssistantList);
    void taskListUpdated(const std::vector<Task>& taskList);
    void taskCreated(const Task* task);
    void taskDeleted(bool success);
    void taskEdited(const Task* task);

private:
    void processCourseListRequest(const QByteArray& packetData);
    void processTeachingAssistantListRequest(const QByteArray& packetData);
    void processTaskListRequest(const QByteArray& packetData);
    void processCreateTask(const QByteArray& packetData);
    void processDeleteTask(const QByteArray& packetData);
    void processEditTask(const QByteArray& packetData);

private slots:
    void processPacket(unsigned short packetId, const QByteArray& packetData);
    
public slots:
    void initialize();
};

#endif // TAEVAL_H
