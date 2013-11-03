#include "DBManager.h"
#include <iostream>

DBManager::DBManager(QObject *parent) : QObject(parent) {}

void DBManager::clearServerState() {
    _courses.clear();
    _taList.clear();
    //_taskList.clear();

    //delete _currentTask;
    //_currentTask = 0;
}

void DBManager::initializeDB(){

    if (openDB()) {
        if (!createDB())
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

bool DBManager::createDB(){

    if ((db.tables().indexOf("ta") == -1) && (db.tables().indexOf("instructor") == -1)){
        if (!createTATable()){
            std::cerr << "TA Table not created\n";
            return false;
        }
        if (!createInstructorTable()){
            std::cerr << "Instructor Table not created\n";
            return false;
        }
        if (!createCourseTable()){
            std::cerr << "Course Table not created\n";
            return false;
        }
        if (!createTaskTable()){
            std::cerr << "Task Table not created\n";
            return false;
        }
        if (!createCourseTATable()){
            std::cerr << "Course TA relationship table not created.\n";
        }

        populateDB();
        //QTextStream out(stdout);
        //mydbmanager->getCourse("Fall", 2009);
       // mydbmanager->getCourseTA(1);

         }

        return true;
    }

void DBManager::showCourse(){
        QTextStream out(stdout);
        out << "Number of Courses  " << _courses.size() << endl;
        for (std::vector<Course>::iterator it = _courses.begin() ; it != _courses.end(); ++it){
            out << "Course Id " << it->id() << endl;
            out << "Course Name " << it->name() << endl;
            out << "Course Code " << it->code() << endl;
            out << "Term " << it->term() << endl;
            out << "Year " << it->year() << endl;
        }
}

void DBManager::showTAs(){
        QTextStream out(stdout);
        out << "Number of TAs  " << _taList.size() << endl;
        for (std::vector<TeachingAssistant>::iterator it = _taList.begin() ; it != _taList.end(); ++it){
            out << "TA Id " << it->id() << endl;
            out << "First Name " << it->firstName() << endl;
            out << "Last Name " << it->lastName() << endl;
            out << "Degree " << it->degree() << endl;
            out << "Major " << it->major() << endl;
            out << "Year " << it->year() << endl;
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


bool DBManager::createCourseTATable()
{
// Create table "That contains the TAs associated with Courses"
bool ret = false;
if (db.isOpen())
    {

        QSqlQuery query;
        ret = query.exec("create table if not exists courseta "
                         "(courseid integer not null references course(courseid), "
                         "taid integer not null references ta(studentno), "
                         "primary key (courseid,taid))");
        //std::cerr << "go here in courseta\n";
    }
return ret;
}



void DBManager::populateDB(){
    int instructID;
    int taID;
    int courseID;
    int taskID;
    int courseta;

    instructID = createInstructor(1, "Fred", "Flintstone", "Geology");
    taID = createTA(100, "Sean", "Benjamin", "BSc", "Comp Sci", 3);
    taID = 100;
    courseID = createCourse("Rocks", "GEOL100", 2009, "Fall", instructID);
    courseta = createCourseTA(courseID,taID);
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
    qDebug() << "getTask query" << query.lastError();
    return ret;
  }

void DBManager::getCourseTA(int courseid)
    {
    clearServerState();
    QSqlQuery query(QString("select * from courseta where courseid=%1").arg(courseid));
    qDebug() << "getCourseTA";
    while (query.next()){

            int studentID = 0;
            studentID = query.value(1).toInt();
            getTA(studentID);

            qDebug() << "Passed student ID " << studentID;
    }
        qDebug() << "getCourseTA query" << query.lastError();


}

void DBManager::getTA(int studentnum){
    QSqlQuery query(QString("select * from ta where studentno=%1").arg(studentnum));

        int id;
        id = query.value(0).toInt();

        QString firstName;
        firstName = query.value(1).toString();

        QString lastName;
        lastName = query.value(2).toString();

        QString degree;
        degree = query.value(3).toString();

        QString major;
        major = query.value(4).toString();

        int year = 0;
        year = query.value(5).toInt();

        _taList.push_back(TeachingAssistant(id, firstName, lastName, degree, major, year));


    qDebug() << "getTA query " << query.lastError();
}


void DBManager::getCourse(QString courseterm, int courseyear)
    {
    clearServerState();
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
        qDebug() << "getCourse query " << query.lastError();


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

int DBManager::createCourseTA(int courseid, int stdnum){
    int newId = -1;
    bool ret = false;

    if (db.isOpen())
        {

        QSqlQuery query;
        ret = query.exec(QString("insert into courseta values(%1,%2)")
                         .arg(courseid).arg(stdnum));

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
