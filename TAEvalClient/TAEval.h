#ifndef TAEVAL_H
#define TAEVAL_H

#include <QObject>
#include <QString>
#include <QtNetwork/QTcpSocket>
#include <vector>
#include "Course.h"
#include "TeachingAssistant.h"
#include "Task.h"
#include <QTimer>

class NetworkConnection;

class TAEval : public QObject {
    Q_OBJECT

private:
    QTcpSocket* _socket;
    NetworkConnection* _network;

    int _currentPacketId;
    QTimer _requestTimer;
    const unsigned int _requestTimeoutSeconds;

private:
    std::vector<QString> _termList;
    std::vector<Course> _courseList;
    std::vector<TeachingAssistant> _teachingAssistantList;
    std::vector<Task> _taskList;
    Task* _currentTask;

    void clearClientState();

public:
    TAEval();
    ~TAEval();

    void requestLogin(const QString& username);
    void requestCourseList(const QString& term, int year);
    void requestTeachingAssistantList(const Course& course);
    void requestTaskList(const Course& course, const TeachingAssistant& teachingAssistant);
    void requestTaskList(const QString& term);
    void requestTaskList(const Course& course);
    void createTask(const Course& course, const TeachingAssistant& teachingAssistant, const QString& taskName, const QString& taskDescription);
    void deleteTask(const Task& task);
    void editTask(const Task& task);
    void requestTermList(const QString& term);
    void requestUpdate(const Task& task);

signals:
    void loginComplete(int result);
    void termListUpdated(const std::vector<QString>& termList);
    void courseListUpdated(const std::vector<Course>& courseList);
    void teachingAssistantListUpdated(const std::vector<TeachingAssistant>& teachingAssistantList);
    void taskListUpdated(const std::vector<Task>& taskList);
    void taskCreated(const Task* task);
    void taskDeleted(bool success);
    void taskEdited(const Task* task);
    void taskUpdated(const Task* task);
    void requestTimedOut();

private:
    void processLoginRequest(const QByteArray& packetData);
    void processTermListRequest(const QByteArray& packetData);
    void processCourseListRequest(const QByteArray& packetData);
    void processTeachingAssistantListRequest(const QByteArray& packetData);
    void processTaskListRequest(const QByteArray& packetData);
    void processCreateTask(const QByteArray& packetData);
    void processDeleteTask(const QByteArray& packetData);
    void processEditTask(const QByteArray& packetData);
    void processUpdateTask(const QByteArray& packetData);

private slots:
    void processPacket(unsigned short packetId, const QByteArray& packetData);
    void requestTimeout();
    
public slots:
    void initialize();
};

#endif // TAEVAL_H
