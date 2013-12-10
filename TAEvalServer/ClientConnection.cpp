#include "ClientConnection.h"
#include <iostream>
#include <QDir>
#include <QSqlDatabase>
#include <QtEndian>
#include "NetworkConnection.h"
//#include "DBManager.h"

unsigned int ClientConnection::CONNECTION_ID_COUNTER = 0;

//DO NOT MAKE ANY HEAP ALLOCATIONS IN THE CONSTRUCTOR
//Heap allocations must be done in the startConnection() function since heap data
//won't be moved between threads
ClientConnection::ClientConnection(int socketDescriptor, int timeoutSeconds) :
    _socketDescriptor(socketDescriptor),
    _timeoutSeconds(timeoutSeconds),
    _socket(0),
    _network(0),
    _timeoutTimer(0),
    _dbManager(0),
    _connectionId(++CONNECTION_ID_COUNTER) {}

ClientConnection::~ClientConnection() {
    delete _dbManager;
    delete _timeoutTimer;
    delete _network;
    delete _socket;
    delete _dbManager->_login;
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
    _dbManager->_login = new User();
    _dbManager->initializeDB(_connectionId);

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
     case 3:
         processCreateTaskRequest(packetData);
         break;
     case 4:
         processDeleteTask(packetData);
         break;
     case 5:
         processEditTask(packetData);
         break;
     case 6:
         processEvaluationsForTA(packetData);
         break;
     case 7:
         processEvaluationsForCourse(packetData);
         break;
     case 8:
         processEvaluationsForTerm(packetData);
         break;
     case 9:
         processVerifyTask(packetData);
         break;
     case 11:
     processVerifyLogin(packetData);
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

 void ClientConnection::sendTaskCreatedSuccess(bool success) {
     QByteArray message;
     QDataStream outputStream(&message, QIODevice::WriteOnly);
     outputStream.setVersion(QDataStream::Qt_4_8);

     outputStream << success;
    /* if (success){
     //   outputStream << 1;
        for (std::vector<Task>::iterator it = _dbManager->_taskList.begin() ; it != _dbManager->_taskList.end(); ++it){
            outputStream <<  it->id();
            outputStream <<  it->name();
            outputStream <<  it->description();
        }

     }*/
//else{
      //  outputStream << 0;
   // }

     _network->sendPacket(3, message);
 }

 void ClientConnection::sendTaskEditSuccess(bool success) {
     QByteArray message;
     QDataStream outputStream(&message, QIODevice::WriteOnly);
     outputStream.setVersion(QDataStream::Qt_4_8);

     outputStream << success;
     if (success){
        for (std::vector<Task>::iterator it = _dbManager->_taskList.begin() ; it != _dbManager->_taskList.end(); ++it){
            outputStream <<  it->id();
            outputStream <<  it->name();
            outputStream <<  it->description();
            outputStream <<  it->comment();
            outputStream << it->rating();
        }
     }

     _network->sendPacket(5, message);
 }

 void ClientConnection::sendTaskDeleteSuccess(bool success) {
     QByteArray message;
     QDataStream outputStream(&message, QIODevice::WriteOnly);
     outputStream.setVersion(QDataStream::Qt_4_8);

     outputStream << success;

     _network->sendPacket(4, message);
 }


 void ClientConnection::sendVerifiedTask(bool success) {
     QByteArray message;
     QDataStream outputStream(&message, QIODevice::WriteOnly);
     outputStream.setVersion(QDataStream::Qt_4_8);

     outputStream << success;

     for (std::vector<Task>::iterator it = _dbManager->_taskList.begin() ; it != _dbManager->_taskList.end(); ++it){
         outputStream << it->id();
         outputStream << it->name();
         outputStream << it->description();
         outputStream << it->comment();
         outputStream << it->rating();
     }
     _network->sendPacket(9, message);
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

 void ClientConnection::sendTaskList(int packetId) {
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

     _network->sendPacket(packetId, message);
 }

 void ClientConnection::sendUserLogin(int usertype) {
     QByteArray message;
     QDataStream outputStream(&message, QIODevice::WriteOnly);
     outputStream.setVersion(QDataStream::Qt_4_8);

     outputStream << usertype;

     _network->sendPacket(10, message);
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
     _dbManager->getCourses(term, year);
     _dbManager->showCourses();

     sendCourseList();

 }



 void ClientConnection::processCreateTaskRequest(const QByteArray& packetData) {

     QDataStream inputStream(packetData);
     inputStream.setVersion(QDataStream::Qt_4_8);

     bool success = false;

     int courseid = 0;
     inputStream >> courseid;

     int taid = 0;
     inputStream >> taid;

     QString taskname;
     inputStream >> taskname;

     QString taskdesc;
     inputStream >> taskdesc;


     qDebug() << "processCreateTaskRequest";
     qDebug() << "courseid=  " << courseid;
     qDebug() << "taid= " << taid;
     qDebug() << "taskname= " << taskname;
     qDebug() << "taskdesc= " << taskdesc;
     success = _dbManager->createTask(taskname, taskdesc, NULL, 0, taid, courseid);
     if (success){
         qDebug() << "Created task.";
        _dbManager->getTasks(courseid, taid);
        _dbManager->showTasks();
    }
     sendTaskCreatedSuccess(success);

 }

 void ClientConnection::processEditTask(const QByteArray& packetData) {

     QDataStream inputStream(packetData);
     inputStream.setVersion(QDataStream::Qt_4_8);

     bool success = false;


     int taskid = 0;
     inputStream >> taskid;

     QString taskname;
     inputStream >> taskname;

     QString taskdesc;
     inputStream >> taskdesc;

     QString evalcomment;
     inputStream >> evalcomment;

     int rank = 0;
     inputStream >> rank;

     qDebug() << "processEditTask";
     qDebug() << "taskid= " << taskid;
     qDebug() << "taskname= " << taskname;
     qDebug() << "taskdesc= " << taskdesc;
     qDebug() << "evalcomment= " << evalcomment;
     qDebug() << "evalrating= " << rank;
     
     success = _dbManager->modifyTask(taskid,taskname,taskdesc,evalcomment,rank);

     if (success){
         qDebug() << "Failed Edit a task";
        _dbManager->getTaskbyID(taskid);
        _dbManager->showTasks();
    }
     sendTaskEditSuccess(success);

 }

 void ClientConnection::processTeachingAssistantListRequest(const QByteArray& packetData) {

     QDataStream inputStream(packetData);
     inputStream.setVersion(QDataStream::Qt_4_8);

     int courseid = 0;
     inputStream >> courseid;

     qDebug() << "processTAListRequest";
     qDebug() << "courseid=  " << courseid;
     _dbManager->getCourseTAs(courseid);
     _dbManager->showTAs();

     sendTAList();

 }

 void ClientConnection::processDeleteTask(const QByteArray& packetData) {

     QDataStream inputStream(packetData);
     inputStream.setVersion(QDataStream::Qt_4_8);

     bool success = false;

     int taskid = 0;
     inputStream >> taskid;

     qDebug() << "processDeleteTask";
     qDebug() << "courseid=  " << taskid;
     success = _dbManager->deleteTask(taskid);


     sendTaskDeleteSuccess(success);

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
     _dbManager->getTasks(courseid,taid);
     _dbManager->showTasks();

     sendTaskList(2);

 }

 void ClientConnection::processEvaluationsForTA(const QByteArray& packetData) {
     QDataStream inputStream(packetData);
     inputStream.setVersion(QDataStream::Qt_4_8);

     int taid = 0;
     inputStream >> taid;

     qDebug() << "processEvaluationsForTA";
     qDebug() << "taid=  " << taid;
     _dbManager->getTasksByStudentID(taid);
     _dbManager->showTasks();

     sendTaskList(6);
 }

 void ClientConnection::processEvaluationsForCourse(const QByteArray& packetData) {
     QDataStream inputStream(packetData);
     inputStream.setVersion(QDataStream::Qt_4_8);

     int courseid = 0;
     inputStream >> courseid;

     qDebug() << "processEvaluationsForCourse";
     qDebug() << "courseid=  " << courseid;
     _dbManager->getTasksByCourseID(courseid);
     _dbManager->showTasks();

     sendTaskList(7);
 }

 void ClientConnection::processEvaluationsForTerm(const QByteArray& packetData) {
     QDataStream inputStream(packetData);
     inputStream.setVersion(QDataStream::Qt_4_8);

     QString term;
     inputStream >> term;

     qDebug() << "processEvaluationsForTerm";
     qDebug() << "term=  " << term;
     _dbManager->getTasks(term);
     _dbManager->showTasks();

     sendTaskList(8);
 }

 void ClientConnection::processVerifyLogin(const QByteArray& packetData) {
     QDataStream inputStream(packetData);
     inputStream.setVersion(QDataStream::Qt_4_8);
     int usertype = 0;
     QString loginname;
     inputStream >> loginname;

     qDebug() << "processVerifyLogin";
     qDebug() << "loginname=  " << loginname;
     usertype =  _dbManager->getUser(loginname);

     sendUserLogin(usertype);
 }

 void ClientConnection::processVerifyTask(const QByteArray& packetData) {
     QDataStream inputStream(packetData);
     inputStream.setVersion(QDataStream::Qt_4_8);

     int taskID = 0;
     inputStream >> taskID;

     qDebug() << "processVerifyTask";
     qDebug() << "taskID = " << taskID;

     bool success = false;
     _dbManager->getTaskbyID(taskID);
     if (_dbManager->_taskList.size() > 0) {
         _dbManager->showTasks();
         success = true;
     }
     sendVerifiedTask(success);
 }

 void ClientConnection::connectionTimeout() {
    std::cerr << "Client Connection Timed Out!\n";
    emit finished();
}
