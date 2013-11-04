#include "ClientConnection.h"
#include <iostream>
#include <QDir>
#include <QSqlDatabase>
#include <QtEndian>
#include "NetworkConnection.h"
#include "DBManager.h"

//DO NOT MAKE ANY HEAP ALLOCATIONS IN THE CONSTRUCTOR
//Heap allocations must be done in the startConnection() function since heap data
//won't be moved between threads
ClientConnection::ClientConnection(int socketDescriptor, int timeoutSeconds) :
    _socketDescriptor(socketDescriptor),
    _timeoutSeconds(timeoutSeconds),
    _socket(0),
    _network(0),
    _timeoutTimer(0),
    _dbManager(0) {}

ClientConnection::~ClientConnection() {
    delete _dbManager;
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

    _dbManager = new DBManager();
    _dbManager->initializeDB();

    _timeoutTimer = new QTimer();
    connect(_timeoutTimer, SIGNAL(timeout()), this, SLOT(connectionTimeout()));
    _timeoutTimer->start(_timeoutSeconds * 1000);
}

 void ClientConnection::processPacket(unsigned short packetId, const QByteArray& packetData) {
     switch (packetId) {
     case 0:
        processCourseListRequest(packetData);
        break;
     case 1:
         processTeachingAssistantListRequest(packetData);
         break;
     case 2:
         processTaskListRequest(packetData);
         break;
     /*case 3:
         processCreateTask(packetData);
         break;
     case 4:
         processDeleteTask(packetData);
         break;
     case 5:
         processEditTask(packetData);
         break;*/
     default:
         break;
     }

 }


 void ClientConnection::sendCourseList() {
     QByteArray message;
     QDataStream outputStream(&message, QIODevice::WriteOnly);
     outputStream.setVersion(QDataStream::Qt_4_8);

     outputStream << _dbManager->_courses.size();

     for (std::vector<Course>::iterator it = _dbManager->_courses.begin() ; it != _dbManager->_courses.end(); ++it){
        outputStream <<  it->id();
        outputStream <<  it->name();
        outputStream <<  it->code();
        outputStream <<  it->year();
        outputStream <<  it->term();
     }

     _network->sendPacket(0, message);
 }

 void ClientConnection::sendTAList() {
     QByteArray message;
     QDataStream outputStream(&message, QIODevice::WriteOnly);
     outputStream.setVersion(QDataStream::Qt_4_8);

     outputStream << _dbManager->_taList.size();

     for (std::vector<TeachingAssistant>::iterator it = _dbManager->_taList.begin() ; it != _dbManager->_taList.end(); ++it){
        outputStream << it->id();
        outputStream << it->firstName();
        outputStream << it->lastName();
        outputStream << it->degree();
        outputStream << it->major();
        outputStream << it->year();

     }

     _network->sendPacket(1, message);
 }

 void ClientConnection::sendTaskList() {
     QByteArray message;
     QDataStream outputStream(&message, QIODevice::WriteOnly);
     outputStream.setVersion(QDataStream::Qt_4_8);

     outputStream << _dbManager->_taskList.size();

     for (std::vector<Task>::iterator it = _dbManager->_taskList.begin() ; it != _dbManager->_taskList.end(); ++it){
        outputStream << it->id();
        outputStream << it->name();
        outputStream << it->description();
        outputStream << it->comment();
        outputStream << it->rating();

     }

     _network->sendPacket(2, message);
 }


 void ClientConnection::processCourseListRequest(const QByteArray& packetData) {

     QDataStream inputStream(packetData);
     inputStream.setVersion(QDataStream::Qt_4_8);

     QString term;
     inputStream >> term;


     int year = 0;
     inputStream >> year;

     qDebug() << "processCourseListRequest";
     qDebug() << "year=  " << year;
     qDebug() << "term= " << term;
     _dbManager->getCourse(term, year);
     _dbManager->showCourse();

     sendCourseList();

 }

 void ClientConnection::processTeachingAssistantListRequest(const QByteArray& packetData) {

     QDataStream inputStream(packetData);
     inputStream.setVersion(QDataStream::Qt_4_8);

     int courseid = 0;
     inputStream >> courseid;

     qDebug() << "processTAListRequest";
     qDebug() << "courseid=  " << courseid;
     _dbManager->getCourseTA(courseid);
     _dbManager->showTAs();

     sendTAList();

 }

 void ClientConnection::processTaskListRequest(const QByteArray& packetData) {

     QDataStream inputStream(packetData);
     inputStream.setVersion(QDataStream::Qt_4_8);
     int courseid = 0;
     inputStream >> courseid;
     int taid = 0;
     inputStream >> taid;

     qDebug() << "processTaskListRequest";
     qDebug() << "courseid= " << courseid;
     qDebug() << "taid=  " << taid;
     _dbManager->getTask(courseid,taid);
     _dbManager->showTask();

     sendTaskList();

 }


 void ClientConnection::connectionTimeout() {
    std::cerr << "Client Connection Timed Out!\n";
    emit finished();
}
