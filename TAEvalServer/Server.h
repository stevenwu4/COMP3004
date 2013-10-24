#ifndef SERVER_H
#define SERVER_H

#include <QtCore>
#include <QtNetwork/QTcpServer>

class Server : public QTcpServer {
    Q_OBJECT

private:
    const QString _hostname;
    const unsigned short _port;
    const unsigned int _connectionTimeoutSeconds;

public:
    Server();
    ~Server() {}

    void incomingConnection(int socketDescriptor);

public slots:
    void run();

signals:
    void finished();
};

#endif // SERVER_H
