#ifndef NETWORKCONNECTION_H
#define NETWORKCONNECTION_H

#include <QObject>
#include <QTcpSocket>

class NetworkConnection : public QObject {
    Q_OBJECT

private:
    QTcpSocket* _socket;
    unsigned short _packetSize;

public:
    NetworkConnection(QTcpSocket* socket);
    ~NetworkConnection() {}

    void sendPacket(unsigned short packetId, QByteArray& packetData);

private slots:
    void networkDataAvailable();
    
signals:
    void processPacket(unsigned short packetId, const QByteArray& packetData);
};

#endif // NETWORKCONNECTION_H
