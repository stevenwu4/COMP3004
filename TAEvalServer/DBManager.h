#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>
#include <QDir>
#include <QVariant>
#include <QVector>
#include "Course.h"
#include "TeachingAssistant.h"
#include "Term.h"
#include "Task.h"
#include "User.h"

#ifndef DBMANAGER_H
#define DBMANAGER_H

class DBManager : public QObject {
public:
    explicit DBManager(QObject *parent = 0);
    ~DBManager(){}
    bool openDB(unsigned int connectionId);
    bool deleteDB();
    bool createDB();
    void populateDB();
    void getTasks(QString term);
    void getTasksByCourseID(int courseid);
    void getTasksByStudentID(int taid);
    void getTasks(int courseid,int taid);
    void getCourses(QString term, int year);
    QSqlQuery getQueryFromUserType();
    void getCourses();
    QSqlError lastError();
    std::vector<Course> _courses;
    std::vector<TeachingAssistant> _taList;
    std::vector<Task>_taskList;
    std::vector<Term> _termList;
    User* _login;
    void initializeDB(unsigned int connectionId);
    void showCourses();
    void showTAs();
    void showTasks();
    void getTAs(int courseid);
    void getCourseTAs(int courseid);
    bool createTask(QString taskname, QString taskdesc, QString evaldesc, int evalrank, int studentnum, int courseid);
    bool deleteTask(int taskid);
    bool modifyTask(int taskid, QString taskname, QString taskdesc, QString evaldesc, int evalrank);
    void getTaskbyID(int taskid);
    int getUser(QString username);

private:
    QSqlDatabase db;
    bool createTaskTable();
    bool createTATable();
    bool createCourseTable();
    bool createInstructorTable();
    bool createCourseTATable();
    bool createCourseUsersTable();
    bool createUsersTable();
    int createInstructor(int emplynum, QString fname, QString lname, QString dept);
    int createTA(int stdnum, QString fname, QString lname, QString degree, QString major, int year);
    int createCourse(QString coursename, QString coursecode, int year, QString term, int instructor);
    void clearServerState();
    int createCourseTA(int courseid, int stdnum);
    int createUsers(QString username, int userid, int usertype);
};

#endif // DBMANAGER_H
