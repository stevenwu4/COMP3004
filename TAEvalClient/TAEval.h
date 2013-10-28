#ifndef TAEVAL_H
#define TAEVAL_H

#include <QObject>
#include <QString>
#include <QtNetwork/QTcpSocket>

class NetworkConnection;

class TAEval : public QObject {
    Q_OBJECT

private:
    const QString _hostname;
    const unsigned short _port;

    QTcpSocket* _socket;
    NetworkConnection* _network;

public:
    TAEval();
    ~TAEval();

private:
    void processTestRequest(const QByteArray& packetData);

private slots:
    void processPacket(unsigned short packetId, const QByteArray& packetData);
    
public slots:
    void initialize();
};

#endif // TAEVAL_H
