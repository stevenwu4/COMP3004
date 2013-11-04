#include "Server.h"
#include <iostream>
#include <QThread>
#include "ClientConnection.h"

Server::Server() :
    _hostname("127.0.0.1"),
    _port(21234),
    _connectionTimeoutSeconds(300) {}

void Server::run() {
    std::cerr << "STARTING\n";

    if (!QTcpServer::listen(QHostAddress(_hostname), _port)) {
        std::cerr << "The server failed to start\n";
        emit finished();
    }
}

void Server::incomingConnection(int socketDescriptor) {
    std::cerr << "Incoming connection\n";
    QThread* thread = new QThread;

    ClientConnection* clientConnection = new ClientConnection(socketDescriptor, _connectionTimeoutSeconds);

    clientConnection->moveToThread(thread);

    //When the thread signals that it has started, the clientConnection's initialization function will be called
    connect(thread, SIGNAL(started()), clientConnection, SLOT(startConnection()));

    //When the clientConnection is finished, it will signal to the thread to quit
    connect(clientConnection, SIGNAL(finished()), thread, SLOT(quit()));

    //Clean up the clientConnection after it signals finished
    connect(clientConnection, SIGNAL(finished()), clientConnection, SLOT(deleteLater()));

    //Clean up the thread once the thread signals finished
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
}
