#include "TAEval.h"
#include <QHostAddress>
#include <iostream>
#include <QtEndian>
#include "NetworkConnection.h"

TAEval::TAEval() :
    _hostname("127.0.0.1"),
    _port(21234),
    _socket(0),
    _network(0) {}

TAEval::~TAEval() {
    delete _network;
    delete _socket;
}

void TAEval::initialize() {
    _socket = new QTcpSocket();

    _network = new NetworkConnection(_socket);
    connect(_network, SIGNAL(processPacket(unsigned short, const QByteArray&)), this, SLOT(processPacket(unsigned short, const QByteArray&)));

    _socket->connectToHost(QHostAddress(_hostname), _port);
}

 void TAEval::processPacket(unsigned short packetId, const QByteArray& packetData) {
     switch (packetId) {
     case 0:
        processTestRequest(packetData);
        break;
     default:
         break;
     }
 }

 void TAEval::processTestRequest(const QByteArray& packetData) {
     //Unpack and print the test welcome message
     QDataStream inputStream(packetData);
     inputStream.setVersion(QDataStream::Qt_4_8);

     char* str = 0;
     inputStream >> str;

     std::cerr << str << "\n";

     delete[] str;

     //Send a test acknowledgement message
     QByteArray message;
     QDataStream outputStream(&message, QIODevice::WriteOnly);
     outputStream.setVersion(QDataStream::Qt_4_8);
     outputStream << "Thanks for the welcome";
     _network->sendPacket(0, message);
 }
