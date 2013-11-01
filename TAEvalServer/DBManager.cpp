#include "DBManager.h"
#include <iostream>

DBManager::DBManager(QObject *parent) : QObject(parent){}


bool DBManager::openDB()
    {
    // Open SQLite3 database
    db = QSqlDatabase::addDatabase("QSQLITE");

    QString path(QDir::home().path());
    path.append(QDir::separator()).append("D2.db.sqlite");
    path = QDir::toNativeSeparators(path);
    db.setDatabaseName(path);

    // Open databasee
    return db.open();
    }


bool DBManager::deleteDB()
    {
    // Delete SQLite3 database
    db.close();

    QString path(QDir::home().path());
    path.append(QDir::separator()).append("D2.db.sqlite");
    path = QDir::toNativeSeparators(path);
    return QFile::remove(path);

    }

bool DBManager::createTaskTable()
    {
    // Create table "Task"
    bool ret = false;
    if (db.isOpen())
        {
        QSqlQuery query;
        //do not provide a taskid on the insert.  The taskid will be created via auto increment
        ret = query.exec("create table if not exists task "
                  "(taskid integer primary key not null, "
                  "taskname text, "
                  "taskdesc text, "
                  "evaldesc text, "
                  "evalrank integer"
                  "employeenum integer not null, "
                  "studentnum integer not null, "
                  "courseid integer not null, "
                 "foreign key(employeenum) references instructor(employeeno), "
                 "foreign key(studentnum) references ta(studentno), "
                 "foreign key(courseid) references course(courseid))");
   // std::cerr << "go here in task\n";
        }
    return ret;
    }

bool DBManager::createTATable()
    {
    // Create table "TA"
    bool ret = false;
    if (db.isOpen())
        {
        QSqlQuery query;
        ret = query.exec("create table if not exists ta "
                  "(studentno integer primary key not null, "
                  "tafirstname text, "
                  "talastname text, "
                  "degree text, "
                  "major text, "
                  "year integer)");
   // std::cerr << "go here in TA\n";
        }
    return ret;
    }

bool DBManager::createInstructorTable()
{
// Create table "Instructor"
bool ret = false;
if (db.isOpen())
    {
    QSqlQuery query;
    ret = query.exec("create table if not exists instructor "
              "(employeeno integer primary key not null, "
              "infirstname text, "
              "inlastname text, "
              "department text)");
    //std::cerr << "go here in instructor\n";
    }

return ret;
}


bool DBManager::createCourseTable()
{
// Create table "Course"
bool ret = false;
if (db.isOpen())
    {
    QSqlQuery query;
    ret = query.exec("create table if not exists course "
              "(courseid integer primary key not null, "
              "coursename text, "
              "coursecode text not null, "
               "year integer not null, "
               "term text not null)");
    //std::cerr << "go here in course\n";
    }
return ret;
}
