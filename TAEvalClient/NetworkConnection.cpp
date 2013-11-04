#include "NetworkConnection.h"
#include <iostream>
#include <QtEndian>

NetworkConnection::NetworkConnection(QTcpSocket* socket) :
    _socket(socket),
    _packetSize(0) {
    QObject::connect(_socket, SIGNAL(readyRead()), this, SLOT(networkDataAvailable()));
}

void NetworkConnection::networkDataAvailable() {
    QDataStream inputStream(_socket);
    inputStream.setVersion(QDataStream::Qt_4_8);

    if (_packetSize == 0) {
        if (_socket->bytesAvailable() < sizeof(unsigned short))
            return;

        inputStream >> _packetSize;
    }

    if (_socket->bytesAvailable() >= _packetSize) {
        unsigned short packetId;
        inputStream >> packetId;

        int numBytesToRead = _packetSize - sizeof(packetId);

        char* buffer = new char[_packetSize];

        int numBytesRead = inputStream.readRawData(buffer, numBytesToRead);

        if (numBytesRead != numBytesToRead) {
            std::cerr << "Error reading network data\n";
            return;
        }

        QByteArray packetData(buffer, numBytesRead);
        delete[] buffer;

        emit processPacket(packetId, packetData);

        _packetSize = 0;
    }
}

void NetworkConnection::sendPacket(unsigned short packetId, QByteArray& packetData) {
    unsigned short packetLength = packetData.length() + sizeof(packetId);

    packetId = qFromBigEndian(packetId);
    packetLength = qFromBigEndian(packetLength);

    packetData.prepend(reinterpret_cast<char*>(&packetId), sizeof(packetId));
    packetData.prepend(reinterpret_cast<char*>(&packetLength), sizeof(packetLength));

    _socket->write(packetData);
}
