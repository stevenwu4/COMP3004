#include "ClientConnection.h"
#include <iostream>
#include <QDir>
#include <QSqlDatabase>
#include <QtEndian>
#include "NetworkConnection.h"

//DO NOT MAKE ANY HEAP ALLOCATIONS IN THE CONSTRUCTOR
//Heap allocations must be done in the startConnection() function since heap data
//won't be moved between threads
ClientConnection::ClientConnection(int socketDescriptor, int timeoutSeconds) :
    _socketDescriptor(socketDescriptor),
    _timeoutSeconds(timeoutSeconds),
    _socket(0),
    _network(0),
    _timeoutTimer(0) {}

ClientConnection::~ClientConnection() {
    delete _timeoutTimer;
    delete _network;
    delete _socket;
}

void ClientConnection::startConnection() {
    _socket = new QTcpSocket();

    if (!_socket->setSocketDescriptor(_socketDescriptor)) {
        std::cerr << "Failed to create client connection with descriptor " << _socketDescriptor << "\n";
        emit finished();
        return;
    }

    _network = new NetworkConnection(_socket);
    connect(_network, SIGNAL(processPacket(unsigned short, const QByteArray&)), this, SLOT(processPacket(unsigned short, const QByteArray&)));

    //Connect to database here
    QString databasePath(QDir::home().path());
    databasePath.append(QDir::separator()).append("ta_eval.db");
    databasePath = QDir::toNativeSeparators(databasePath);

    //Use socket descriptor as unique name for database connection for now, use login name later
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", QString::number(_socketDescriptor));
    database.setDatabaseName(databasePath);

    if (database.open()) {
        std::cerr << "Database Opened!\n";
    }

    _timeoutTimer = new QTimer();
    connect(_timeoutTimer, SIGNAL(timeout()), this, SLOT(connectionTimeout()));
    _timeoutTimer->start(_timeoutSeconds * 1000);

    //Send a test welcome message
    QByteArray welcomeMessage;
    QDataStream outputStream(&welcomeMessage, QIODevice::WriteOnly);
    outputStream.setVersion(QDataStream::Qt_4_8);
    outputStream << "Welcome";
    _network->sendPacket(0, welcomeMessage);
}

 void ClientConnection::processPacket(unsigned short packetId, const QByteArray& packetData) {
     switch (packetId) {
     case 0:
        processTestRequest(packetData);
        break;
     default:
         break;
     }
 }

 void ClientConnection::processTestRequest(const QByteArray& packetData) {
     QDataStream inputStream(packetData);
     inputStream.setVersion(QDataStream::Qt_4_8);

     char* str = 0;
     inputStream >> str;

     std::cerr << str << "\n";

     delete[] str;
 }

void ClientConnection::connectionTimeout() {
    std::cerr << "Client Connection Timed Out!\n";
    emit finished();
}
