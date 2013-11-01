#ifndef CLIENTCONNECTION_H
#define CLIENTCONNECTION_H
#include <QtNetwork/QTcpSocket>
#include <QTimer>

class NetworkConnection;

class ClientConnection : public QObject {
    Q_OBJECT

private:
    int _socketDescriptor, _timeoutSeconds;

    QTcpSocket* _socket;
    NetworkConnection* _network;
    QTimer* _timeoutTimer;

public:
    ClientConnection(int socketDescriptor, int timeoutSeconds);
    ~ClientConnection();

    void processTestRequest(const QByteArray& packetData);

public slots:
    void startConnection();

private slots:
    void processPacket(unsigned short packetId, const QByteArray& packetData);
    void connectionTimeout();

signals:
    void finished();
};

#endif // CLIENTCONNECTION_H
