#ifndef CLIENTCONNECTION_H
#define CLIENTCONNECTION_H

#include <QtNetwork/QTcpSocket>
#include <QTimer>
#include "DBManager.h"

class NetworkConnection;
class DBManager;

class ClientConnection : public QObject {
    Q_OBJECT

private:
    int _socketDescriptor, _timeoutSeconds;

    QTcpSocket* _socket;
    NetworkConnection* _network;
    QTimer* _timeoutTimer;
    DBManager* _dbManager;

    const unsigned int _connectionId;
    static unsigned int CONNECTION_ID_COUNTER;

private:

    void sendCourseList();
    void sendTAList();
    void sendTaskList();
    void sendTaskCreatedSuccess(bool success);
    void sendTaskDeleteSuccess(bool success);
    void sendTaskEditSuccess(bool success);
    void sendVerifiedTask(bool success);

public:
    ClientConnection(int socketDescriptor, int timeoutSeconds);
    ~ClientConnection();

    void processCourseListRequest(const QByteArray& packetData);
    void processTeachingAssistantListRequest(const QByteArray& packetData);
    void processTaskListRequest(const QByteArray& packetData);
    void processCreateTaskRequest(const QByteArray& packetData);
    void processDeleteTask(const QByteArray& packetData);
    void processEditTask(const QByteArray& packetData);
    void processEvaluationsForTA(const QByteArray& packetData);
    void processEvaluationsForCourse(const QByteArray& packetData);
    void processEvaluationsForTerm(const QByteArray& packetData);
    void processVerifyTask(const QByteArray& packetData);

public slots:
    void startConnection();

private slots:
    void processPacket(unsigned short packetId, const QByteArray& packetData);
    void connectionTimeout();

signals:
    void finished();
};

#endif // CLIENTCONNECTION_H
