#include "TAEval.h"
#include <QHostAddress>
#include <iostream>
#include <QtEndian>
#include "NetworkConnection.h"
#include <fstream>

TAEval::TAEval() :
    _socket(0),
    _network(0),
    _currentPacketId(-1),
    _requestTimeoutSeconds(5),
    _currentTask(0) {}

TAEval::~TAEval() {
    delete _network;
    delete _socket;
    delete _currentTask;
}

void TAEval::requestTimeout() {
    _currentPacketId = -1;
    emit requestTimedOut();
}

void TAEval::clearClientState() {
    _courseList.clear();
    _teachingAssistantList.clear();
    _taskList.clear();

    delete _currentTask;
    _currentTask = 0;
}

void TAEval::requestLogin(const QString& username) {
    QByteArray message;
    QDataStream outputStream(&message, QIODevice::WriteOnly);
    outputStream.setVersion(QDataStream::Qt_4_8);

    outputStream << username;

    _currentPacketId = 10;
    _requestTimer.start(_requestTimeoutSeconds * 1000);
    _network->sendPacket(_currentPacketId, message);
}

void TAEval::requestCourseList(const QString& term, int year) {
    QByteArray message;
    QDataStream outputStream(&message, QIODevice::WriteOnly);
    outputStream.setVersion(QDataStream::Qt_4_8);

    outputStream << term;
    outputStream << year;

    _currentPacketId = 0;
    _requestTimer.start(_requestTimeoutSeconds * 1000);
    _network->sendPacket(_currentPacketId, message);
}

void TAEval::requestTeachingAssistantList(const Course& course) {
    QByteArray message;
    QDataStream outputStream(&message, QIODevice::WriteOnly);
    outputStream.setVersion(QDataStream::Qt_4_8);

    outputStream << course.id();

    _currentPacketId = 1;
    _requestTimer.start(_requestTimeoutSeconds * 1000);
    _network->sendPacket(_currentPacketId, message);
}

void TAEval::requestTaskList(const Course& course, const TeachingAssistant& teachingAssistant) {
    QByteArray message;
    QDataStream outputStream(&message, QIODevice::WriteOnly);
    outputStream.setVersion(QDataStream::Qt_4_8);

    outputStream << course.id();
    outputStream << teachingAssistant.id();

    _currentPacketId = 2;
    _requestTimer.start(_requestTimeoutSeconds * 1000);
    _network->sendPacket(_currentPacketId, message);
}

void TAEval::requestTaskList(const QString& term) {
    QByteArray message;
    QDataStream outputStream(&message, QIODevice::WriteOnly);
    outputStream.setVersion(QDataStream::Qt_4_8);

    outputStream << term;

    _currentPacketId = 6;
    _requestTimer.start(_requestTimeoutSeconds * 1000);
    _network->sendPacket(_currentPacketId, message);
}

void TAEval::requestTaskList(const Course& course) {
    QByteArray message;
    QDataStream outputStream(&message, QIODevice::WriteOnly);
    outputStream.setVersion(QDataStream::Qt_4_8);

    outputStream << course.id();

    _currentPacketId = 7;
    _requestTimer.start(_requestTimeoutSeconds * 1000);
    _network->sendPacket(_currentPacketId, message);
}

void TAEval::createTask(const Course& course, const TeachingAssistant& teachingAssistant, const QString& taskName, const QString& taskDescription) {
    QByteArray message;
    QDataStream outputStream(&message, QIODevice::WriteOnly);
    outputStream.setVersion(QDataStream::Qt_4_8);

    outputStream << course.id();
    outputStream << teachingAssistant.id();
    outputStream << taskName;
    outputStream << taskDescription;

    _currentPacketId = 3;
    _requestTimer.start(_requestTimeoutSeconds * 1000);
    _network->sendPacket(_currentPacketId, message);
}

void TAEval::deleteTask(const Task& task) {
    QByteArray message;
    QDataStream outputStream(&message, QIODevice::WriteOnly);
    outputStream.setVersion(QDataStream::Qt_4_8);

    outputStream << task.id();

    _currentPacketId = 4;
    _requestTimer.start(_requestTimeoutSeconds * 1000);
    _network->sendPacket(_currentPacketId, message);
}

void TAEval::editTask(const Task& task) {
    QByteArray message;
    QDataStream outputStream(&message, QIODevice::WriteOnly);
    outputStream.setVersion(QDataStream::Qt_4_8);

    outputStream << task.id();
    outputStream << task.name();
    outputStream << task.description();
    outputStream << task.comment();
    outputStream << task.rating();

    _currentPacketId = 5;
    _requestTimer.start(_requestTimeoutSeconds * 1000);
    _network->sendPacket(_currentPacketId, message);
}

void TAEval::requestTermList(const QString& term) {
    QByteArray message;
    QDataStream outputStream(&message, QIODevice::WriteOnly);
    outputStream.setVersion(QDataStream::Qt_4_8);

    outputStream << term;

    _currentPacketId = 8;
    _requestTimer.start(_requestTimeoutSeconds * 1000);
    _network->sendPacket(_currentPacketId, message);
}

void TAEval::requestUpdate(const Task& task) {
    QByteArray message;
    QDataStream outputStream(&message, QIODevice::WriteOnly);
    outputStream.setVersion(QDataStream::Qt_4_8);

    outputStream << task.id();

    _currentPacketId = 9;
    _requestTimer.start(_requestTimeoutSeconds * 1000);
    _network->sendPacket(_currentPacketId, message);
}

void TAEval::initialize() {
    std::fstream configFile("taeval.config", std::ios::in);

    if (!configFile.is_open())
        return;

    std::string hostname;
    unsigned short port;

    std::getline(configFile, hostname);
    configFile >> port;

    configFile.close();

    std::cerr << hostname << "\n" << port << "\n";

    _socket = new QTcpSocket();

    _network = new NetworkConnection(_socket);
    connect(_network, SIGNAL(processPacket(unsigned short, const QByteArray&)), this, SLOT(processPacket(unsigned short, const QByteArray&)));

    connect(&_requestTimer, SIGNAL(timeout()), this, SLOT(requestTimeout()));

    _socket->connectToHost(QHostAddress(QString::fromStdString(hostname)), port);
}

void TAEval::processPacket(unsigned short packetId, const QByteArray& packetData) {
    //A timeout has occured previously and we just received an old packet, discard it
    if (packetId != _currentPacketId)
        return;

    _requestTimer.stop();

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
        processCreateTask(packetData);
        break;
    case 4:
        processDeleteTask(packetData);
        break;
    case 5:
        processEditTask(packetData);
        break;
    case 6:
        processTaskListRequest(packetData);
        break;
    case 7:
        processTaskListRequest(packetData);
        break;
    case 8:
        processTermListRequest(packetData);
        break;
    case 9:
        processUpdateTask(packetData);
        break;
    case 10:
        processLoginRequest(packetData);
        break;
    default:
        break;
    }
}

void TAEval::processLoginRequest(const QByteArray& packetData) {
    QDataStream inputStream(packetData);
    inputStream.setVersion(QDataStream::Qt_4_8);

    int result;
    inputStream >> result;

    emit loginComplete(result);
}

void TAEval::processTermListRequest(const QByteArray& packetData) {
    clearClientState();

    QDataStream inputStream(packetData);
    inputStream.setVersion(QDataStream::Qt_4_8);

    unsigned int numTerms;
    inputStream >> numTerms;

    for (unsigned int i = 0; i < numTerms; ++i) {
        QString term = 0;
        inputStream >> term;

        _termList.push_back(term);
    }

    emit termListUpdated(_termList);
}

void TAEval::processCourseListRequest(const QByteArray& packetData) {
    clearClientState();

    QDataStream inputStream(packetData);
    inputStream.setVersion(QDataStream::Qt_4_8);

    unsigned int numCourses;
    inputStream >> numCourses;

    for (unsigned int i = 0; i < numCourses; ++i) {
        int courseId;
        inputStream >> courseId;

        QString courseName = 0;
        inputStream >> courseName;

        QString courseCode = 0;
        inputStream >> courseCode;

        int year = 0;
        inputStream >> year;

        QString term = 0;
        inputStream >> term;

        _courseList.push_back(Course(courseId, courseName, courseCode, year, term));
    }

    emit courseListUpdated(_courseList);
}

void TAEval::processTeachingAssistantListRequest(const QByteArray& packetData) {
    clearClientState();

    QDataStream inputStream(packetData);
    inputStream.setVersion(QDataStream::Qt_4_8);

    unsigned int numTeachingAssistants;
    inputStream >> numTeachingAssistants;

    for (unsigned int i = 0; i < numTeachingAssistants; ++i) {
        int id;
        inputStream >> id;

        QString firstName = 0;
        inputStream >> firstName;

        QString lastName = 0;
        inputStream >> lastName;

        QString degree = 0;
        inputStream >> degree;

        QString major = 0;
        inputStream >> major;

        int year = 0;
        inputStream >> year;

        _teachingAssistantList.push_back(TeachingAssistant(id, firstName, lastName, degree, major, year));
    }

    emit teachingAssistantListUpdated(_teachingAssistantList);
}

void TAEval::processTaskListRequest(const QByteArray& packetData) {
    clearClientState();

    QDataStream inputStream(packetData);
    inputStream.setVersion(QDataStream::Qt_4_8);

    unsigned int numTasks;
    inputStream >> numTasks;

    for (unsigned int i = 0; i < numTasks; ++i) {
        int id;
        inputStream >> id;

        QString name;
        inputStream >> name;

        QString description;
        inputStream >> description;

        QString comment;
        inputStream >> comment;

        int rating;
        inputStream >> rating;

        _taskList.push_back(Task(id, name, description, comment, rating));
    }

    emit taskListUpdated(_taskList);
}

void TAEval::processCreateTask(const QByteArray& packetData) {
    clearClientState();

    QDataStream inputStream(packetData);
    inputStream.setVersion(QDataStream::Qt_4_8);

    bool success;
    inputStream >> success;

    if (success) {
        int id;
        inputStream >> id;

        QString name;
        inputStream >> name;

        QString description;
        inputStream >> description;

        _currentTask = new Task(id, name, description, QString(), -1);
    }

    emit taskCreated(_currentTask);
}

void TAEval::processDeleteTask(const QByteArray &packetData) {
    clearClientState();

    QDataStream inputStream(packetData);
    inputStream.setVersion(QDataStream::Qt_4_8);

    bool success;
    inputStream >> success;

    emit taskDeleted(success);
}

void TAEval::processEditTask(const QByteArray& packetData) {
    clearClientState();

    QDataStream inputStream(packetData);
    inputStream.setVersion(QDataStream::Qt_4_8);

    bool success;
    inputStream >> success;

    if (success) {
        int id;
        inputStream >> id;

        QString name;
        inputStream >> name;

        QString description;
        inputStream >> description;

        QString evaluation;
        inputStream >> evaluation;

        int rating;
        inputStream >> rating;

        _currentTask = new Task(id, name, description, evaluation, rating);
    }

    emit taskEdited(_currentTask);
}

void TAEval::processUpdateTask(const QByteArray& packetData) {
    clearClientState();

    QDataStream inputStream(packetData);
    inputStream.setVersion(QDataStream::Qt_4_8);

    bool success;
    inputStream >> success;

    if (success) {
        int id;
        inputStream >> id;

        QString name;
        inputStream >> name;

        QString description;
        inputStream >> description;

        QString evaluation;
        inputStream >> evaluation;

        int rating;
        inputStream >> rating;

        _currentTask = new Task(id, name, description, evaluation, rating);
    }

    emit taskCreated(_currentTask);
}

std::vector<Task> TAEval::getTaskList() {
    return _taskList;
}
