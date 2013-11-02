#include "DBManager.h"
#include <iostream>

DBManager::DBManager(QObject *parent) : QObject(parent){}


void DBManager::clearServerState() {
    _courses.clear();
    //_teachingAssistantList.clear();
    //_taskList.clear();

    //delete _currentTask;
    //_currentTask = 0;
}

void DBManager::initializeDB(DBManager *mydbmanager){

    if (mydbmanager->openDB()) {
        if (!mydbmanager->createDB(mydbmanager))
            std::cerr << "Failed to create tables.\n";
     }

}

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

bool DBManager::createDB(DBManager *mydbmanager){

    if ((db.tables().indexOf("ta") == -1) && (db.tables().indexOf("instructor") == -1)){
        if (!mydbmanager->createTATable()){
            std::cerr << "TA Table not created\n";
            return false;
        }
        if (!mydbmanager->createInstructorTable()){
            std::cerr << "Instructor Table not created\n";
            return false;
        }
        if (!mydbmanager->createCourseTable()){
            std::cerr << "Course Table not created\n";
            return false;
        }
        if (!mydbmanager->createTaskTable()){
            std::cerr << "Task Table not created\n";
            return false;
        }

        mydbmanager->populateDB();
        QTextStream out(stdout);
        mydbmanager->getCourse("Fall", 2009);
        out << "Number of Courses1  " << mydbmanager->_courses.size() << endl;
            for (std::vector<Course>::iterator it = mydbmanager->_courses.begin() ; it != mydbmanager->_courses.end(); ++it){
                out << "Course Id " << it->id() << endl;
                out << "Course Name " << it->getCourseName() << endl;
                out << "Course Code " << it->getCourseCode() << endl;
                out << "Term " << it->getTerm() << endl;
                out << "Year " << it->getYear() << endl;
            }
         }

        return true;
    }

void DBManager::showCourse(DBManager *mydbmanager){
        QTextStream out(stdout);
        out << "Number of Courses2  " << mydbmanager->_courses.size() << endl;
        for (std::vector<Course>::iterator it = mydbmanager->_courses.begin() ; it != mydbmanager->_courses.end(); ++it){
            out << "Course Id " << it->id() << endl;
            out << "Course Name " << it->getCourseName() << endl;
            out << "Course Code " << it->getCourseCode() << endl;
            out << "Term " << it->getTerm() << endl;
            out << "Year " << it->getYear() << endl;
        }
}

bool DBManager::deleteDB()
    {
    // Delete SQLite3 database
    db.close();

    QString path(QDir::currentPath());
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
                  "evalrank integer, "
                  "studentnum integer not null, "
                  "courseid integer not null, "
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
              "term text not null, "
              "employeenum integer not null, "
              "foreign key(employeenum) references instructor(employeeno))");
        //std::cerr << "go here in course\n";
    }
return ret;
}

void DBManager::populateDB(){
    int instructID;
    int taID;
    int courseID;
    int taskID;


    instructID = createInstructor(1, "Fred", "Flintstone", "Geology");
    taID = createTA(100, "Sean", "Benjamin", "BSc", "Comp Sci", 3);
    taID = 100;
    courseID = createCourse("Rocks", "GEOL100", 2009, "Fall", instructID);
    instructID = createInstructor(2, "Donald", "Knuth", "Computer Science");
    courseID = createCourse("Discrete Math", "COMP1805", 2009, "Fall", instructID);
    taskID = createTask("Marking Exam", "correct midterm", NULL, 0, taID, courseID);

}

QString DBManager::getTask(int id)
    {
    QString ret = "false";

    QSqlQuery query(QString("select * from task where taskid = %1").arg(id));
    if (query.next())
        {
        ret = QString("Task info = %1 %2 %3").arg(query.value(0).toString()).arg(query.value(1).toString()).arg(query.value(2).toString());
        }
    qDebug() << query.lastError();
    return ret;
  }

void DBManager::getCourse(QString courseterm, int courseyear)
    {
    this->clearServerState();
    QSqlQuery query(QString("select * from course where term = '%1' AND year=%2").arg(courseterm).arg(courseyear));

    while (query.next()){

            int courseID = 0;
            courseID = query.value(0).toInt();

            QString courseName;
            courseName = query.value(1).toString();

            QString courseCode;
            courseCode = query.value(2).toString();

           int year = 0;
           year = query.value(3).toInt();

           QString term;
           term = query.value(4).toString();
           _courses.push_back(Course(courseID, courseName, courseCode, year, term));
    }
        qDebug() << query.lastError();


}

int DBManager::createInstructor(int emplynum, QString fname, QString lname, QString dept){
    int newId = -1;
    bool ret = false;

    if (db.isOpen())
        {

        QSqlQuery query;
        ret = query.exec(QString("insert into instructor values(%1,'%2','%3','%4')")
                         .arg(emplynum).arg(fname).arg(lname).arg(dept));

        // Get database given autoincrement value
        if (ret)
            {
            newId = query.lastInsertId().toInt();
            }

        }
    return newId;
}

int DBManager::createTA(int stdnum, QString fname, QString lname, QString degree, QString major, int year){
    int newId = -1;
    bool ret = false;

    if (db.isOpen())
        {

        QSqlQuery query;
        ret = query.exec(QString("insert into ta values(%1,'%2','%3','%4','%5',%6)")
                         .arg(stdnum).arg(fname).arg(lname).arg(degree).arg(major).arg(year));

        // Get database given autoincrement value
        if (ret)
            {
            newId = query.lastInsertId().toInt();
            }

        }
    return newId;
}

int DBManager::createCourse(QString coursename, QString coursecode, int year, QString term, int instructor){
    int newId = -1;
    bool ret = false;

    if (db.isOpen())
        {

        QSqlQuery query;
        ret = query.exec(QString("insert into course values(NULL,'%1','%2',%3,'%4',%5)")
                         .arg(coursename).arg(coursecode).arg(year).arg(term).arg(instructor));

        // Get database given autoincrement value
        if (ret)
            {
            newId = query.lastInsertId().toInt();
            }

        }
    return newId;
}

int DBManager::createTask(QString taskname, QString taskdesc, QString evaldesc, int evalrank, int studentnum, int courseid){
    int newId = -1;
    bool ret = false;

    if (db.isOpen())
        {

        QSqlQuery query;
        ret = query.exec(QString("insert into task values(NULL,'%1','%2','%3',%4,%5,%6)")
                         .arg(taskname).arg(taskdesc).arg(evaldesc).arg(evalrank).arg(studentnum).arg(courseid));

        // Get database given autoincrement value
        if (ret)
            {
            newId = query.lastInsertId().toInt();
            }

        }
    return newId;
}

QSqlError DBManager::lastError()
 {
    return db.lastError();
 }
