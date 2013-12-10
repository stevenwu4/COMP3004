#include "DBManager.h"
#include <iostream>

DBManager::DBManager(QObject *parent) : QObject(parent) {}

void DBManager::clearServerState() {
    _courses.clear();
    _taList.clear();
    _taskList.clear();
    _termList.clear();}

void DBManager::initializeDB(unsigned int connectionId){

    if (openDB(connectionId)) {
        if (!createDB())
            std::cerr << "Failed to create tables.\n";
     }

}

bool DBManager::openDB(unsigned int connectionId)
    {
    // Open SQLite3 database
    db = QSqlDatabase::addDatabase("QSQLITE", QString::number(connectionId));

    QString path(QDir::home().path());
    path.append(QDir::separator()).append("D4.db.sqlite");
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
        if (!createUsersTable()){
            std::cerr << "Users table not created.\n";
        }

        populateDB();

         }

        return true;
    }

void DBManager::showCourses(){
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

void DBManager::showTasks(){
        QTextStream out(stdout);
        out << "Number of Tasks  " << _taskList.size() << endl;
        for (std::vector<Task>::iterator it = _taskList.begin() ; it != _taskList.end(); ++it){
            out << "Task Id " << it->id() << endl;
            out << "Task Name " << it->name() << endl;
            out << "Task Desc " << it->description() << endl;
            out << "Eval Desc " << it->comment() << endl;
            out << "Eval Rank " << it->rating() << endl;
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
    path.append(QDir::separator()).append("D4.db.sqlite");
    path = QDir::toNativeSeparators(path);
    return QFile::remove(path);

    }

bool DBManager::createTaskTable()
    {
    // Create table "Task"
    bool ret = false;
    if (db.isOpen())
        {

        QSqlQuery query(db);
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
        QSqlQuery query(db);
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


bool DBManager::createUsersTable()
    {
    // Create table "users"
    bool ret = false;
    if (db.isOpen())
        {
        QSqlQuery query(db);
        ret = query.exec("create table if not exists users "
                  "(usernameid text primary key not null unique, "
                  "userid integer, "
                  "usertype integer)");
    std::cerr << "go here in user\n";
        }
    return ret;
    }

bool DBManager::createInstructorTable()
{
// Create table "Instructor"
bool ret = false;
if (db.isOpen())
    {
    QSqlQuery query(db);
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

        QSqlQuery query(db);
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

        QSqlQuery query(db);
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
    int userID;

    instructID = createInstructor(1, "Fred", "Flintstone", "Geology");
    taID = createTA(100, "Sean", "Benjamin", "BSc", "Comp Sci", 3);
    taID = 100;
    courseID = createCourse("Rocks", "GEOL100", 2009, "Fall", instructID);
    createCourseTA(courseID,taID);
    instructID = createInstructor(2, "Donald", "Knuth", "Computer Science");
    courseID = createCourse("Discrete Math", "COMP1805", 2009, "Fall", instructID);
    createTask("Marking Exam", "correct midterm", NULL, 0, taID, courseID);


    //course with no TA in W2007 with tasks that aren't evaluated

    instructID = createInstructor(3, "John", "Carmack", "Computer Science");
    courseID = createCourse("3D Game Engines", "COMP4002", 2007, "Winter", instructID);
    taID = createTA(105, "John", "Romero", "MSc", "Computer Science", 1);
    createCourseTA(courseID,taID);
    createTask("Tutorial", "organize tutorial", NULL, 0, taID, courseID);
    createTask("Marking Test", "correct test", NULL, 0, taID, courseID);
    courseID = createCourse("Virtual Reality", "COMP4401", 2007, "Winter", instructID);
    taID = createTA(104, "Palmer", "Luckey", "BSc", "Computer Science", 4);
    createCourseTA(courseID,taID);
    createTask("Tutorial", "organize tutorial", NULL, 0, taID, courseID);
    createTask("Marking Project", "evaluate projects", NULL, 0, taID, courseID);

    //course with TA in W2007 with tasks that are evaluated

    instructID = createInstructor(4, "Jack", "Handey", "English");
    courseID = createCourse("Deep Thoughts", "ENGL9999", 2007, "Winter", instructID);
    taID = createTA(101, "Steve", "Martin", "M.A.", "English", 2);
    createCourseTA(courseID,taID);
    createTask("Tutorial", "organize tutorial", "Well organized!", 5, taID, courseID);
    taID = createTA(102, "Michael", "Nesmith", "M.A.", "English", 1);
    createCourseTA(courseID,taID);
    createTask("Marking Exam", "correct final", "Satisfactory marking.", 3, taID, courseID);
    courseID = createCourse("Comedic Writing", "ENGL3304", 2007, "Winter", instructID);
    taID = createTA(103, "Jim", "Borgman", "B.A.", "English", 2);
    createCourseTA(courseID,taID);
    createTask("Marking Assignments", "evaluate comics", "Always on time!", 4, taID, courseID);
    userID = createUsers("fred", 1, 1);
    userID = createUsers("don", 2, 1);
    userID = createUsers("john", 3, 1);
    userID = createUsers("jack", 4, 1);
    userID = createUsers("sean", 100, 2);
    userID = createUsers("palmer", 104, 2);
    userID = createUsers("romero", 105, 2);

}

int DBManager::getUser(QString username){
    //clearServerState();
    int ret =0;
     QSqlQuery query(QString("select * from users where username = '%1'").arg(username), db);

    if (query.size() == 0){
       ret = 0;
   } else {
       while (query.next()) {
          QString name = username;
          int usertype = query.value(2).toInt();
          int userid = query.value(1).toInt();
          ret = usertype;
      _login->setUserType(usertype);
          _login->setLoginName(username);
          _login->setID(userid);

       }
       qDebug() << "getUser(QString username) query " << query.lastError();
   }
   return ret;
}

void DBManager::getTasks(QString term) {
    clearServerState();
    QSqlQuery query(QString("select * from course where term = %1").arg(term), db);

    while (query.next()) {
        int courseID = 0;
        courseID = query.value(0).toInt();

        getTasksByCourseID(courseID);
    }
    qDebug() << "getTask(QString term) query " << query.lastError();
}

void DBManager::getTasksByCourseID(int courseid) {
    clearServerState();
    QSqlQuery query(QString("select * from task where courseid = %1").arg(courseid), db);

    while (query.next()) {
        int taskID = 0;
        taskID = query.value(0).toInt();

        QString taskName;
        taskName = query.value(1).toString();

        QString taskDesc;
        taskDesc = query.value(2).toString();

        QString evalComment;
        evalComment = query.value(3).toString();

        int evalRank;
        evalRank = query.value(4).toInt();

        _taskList.push_back(Task(taskID, taskName, taskDesc, evalComment, evalRank));
    }
    qDebug() << "getTask(int courseid) query " << query.lastError();
}

void DBManager::getTasksByStudentID(int taid) {
    clearServerState();
    QSqlQuery query(QString("select * from task where studentnum = %1").arg(taid), db);

    while (query.next()) {
        int taskID = 0;
        taskID = query.value(0).toInt();

        QString taskName;
        taskName = query.value(1).toString();

        QString taskDesc;
        taskDesc = query.value(2).toString();

        QString evalComment;
        evalComment = query.value(3).toString();

        int evalRank;
        evalRank = query.value(4).toInt();

        _taskList.push_back(Task(taskID, taskName, taskDesc, evalComment, evalRank));
    }
    qDebug() << "getTask(int taid) query " << query.lastError();
}

void DBManager::getTasks(int courseid, int taid)
    {
    clearServerState();
    QSqlQuery query(QString("select * from task where courseid = %1 AND studentnum = %2").arg(courseid).arg(taid), db);
    while (query.next()){
            int taskID = 0;
            taskID = query.value(0).toInt();

            QString taskName;
            taskName = query.value(1).toString();

            QString taskDesc;
            taskDesc = query.value(2).toString();

           QString evalComment;
           evalComment = query.value(3).toString();

           int evalRank = 0;
           evalRank = query.value(4).toInt();
           _taskList.push_back(Task(taskID, taskName, taskDesc, evalComment, evalRank));
    }
    qDebug() << "getTask(int courseid, int taid) query " << query.lastError();

  }

void DBManager::getTaskbyID(int taskid)
    {
    clearServerState();
    QSqlQuery query(QString("select * from task where taskid = %1").arg(taskid), db);
    while (query.next()){
            int taskID = 0;
            taskID = query.value(0).toInt();

            QString taskName;
            taskName = query.value(1).toString();

            QString taskDesc;
            taskDesc = query.value(2).toString();

           QString evalComment;
           evalComment = query.value(3).toString();

           int evalRank = 0;
           evalRank = query.value(4).toInt();
           _taskList.push_back(Task(taskID, taskName, taskDesc, evalComment, evalRank));
    }
        qDebug() << "getTaskbyID query " << query.lastError();

  }

void DBManager::getCourseTAs(int courseid)
    {
    clearServerState();
    QSqlQuery query(QString("select * from courseta where courseid=%1").arg(courseid), db);
    qDebug() << "getCourseTA" << " for courseid = " << courseid;
    while (query.next()){

            int studentID = 0;
            studentID = query.value(1).toInt();
            qDebug() << "Passed Student ID " << studentID;
            getTAs(studentID);


    }
        qDebug() << "getCourseTA query" << query.lastError();


}

void DBManager::getTAs(int studentnum){

    qDebug() << "getTA studentnum = " << studentnum;
    QSqlQuery query(QString("select * from ta where studentno=%1").arg(studentnum), db);
    while (query.next()){
        int id;
        id = query.value(0).toInt();
        qDebug() << "inside getTA id = " << id;

        QString firstName;
        firstName = query.value(1).toString();
        qDebug() << "inside getTA firstname = " << firstName;

        QString lastName;
        lastName = query.value(2).toString();
        qDebug() << "inside getTA lastname = " << lastName;

        QString degree;
        degree = query.value(3).toString();
        qDebug() << "inside getTA degree = " << degree;

        QString major;
        major = query.value(4).toString();
        qDebug() << "inside getTA major = " << major;

        int year = 0;
        year = query.value(5).toInt();
        qDebug() << "inside getTA year = " << year;

        _taList.push_back(TeachingAssistant(id, firstName, lastName, degree, major, year));
    }

    qDebug() << "getTA query " << query.lastError();
}

void DBManager::getCourses() {
    clearServerState();
    QSqlQuery query;

    if (_login->userType() == 1) {
        QSqlQuery query(QString("select * from course where employeenum=%1").arg(_login->id()));
    }
    else if (_login->userType() == 2) {
        QSqlQuery query(QString("select year, term from course join courseta on (course.courseid = courseta.courseid) where taid=%1").arg(_login->id()));
    }

    while (query.next()) {
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
    qDebug() << "getCourses() query " << query.lastError();
}


void DBManager::getCourses(QString courseterm, int courseyear)
    {
    clearServerState();
    QSqlQuery query(QString("select * from course where term = '%1' AND year=%2").arg(courseterm).arg(courseyear), db);

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
    qDebug() << "getCourse(courseterm, courseyear) query " << query.lastError();
}

int DBManager::createInstructor(int emplynum, QString fname, QString lname, QString dept){
    int newId = -1;
    bool ret = false;

    if (db.isOpen())
        {

        QSqlQuery query(db);
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

        QSqlQuery query(db);
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

        QSqlQuery query(db);
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

int DBManager::createUsers(QString username, int userid, int usertype){
    int newId = -1;
    bool ret = false;

    if (db.isOpen())
        {

        QSqlQuery query(db);
        ret = query.exec(QString("insert into users values('%1',%2,%3)")
                         .arg(username).arg(userid).arg(usertype));

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

        QSqlQuery query(db);
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

bool DBManager::createTask(QString taskname, QString taskdesc, QString evaldesc, int evalrank, int studentnum, int courseid){
    bool ret = false;

    if (db.isOpen())
        {

        QSqlQuery query(db);
        ret = query.exec(QString("insert into task values(NULL,'%1','%2','%3',%4,%5,%6)")
                         .arg(taskname).arg(taskdesc).arg(evaldesc).arg(evalrank).arg(studentnum).arg(courseid));

        // Get database given autoincrement value
        if (ret)
            {
            query.lastInsertId().toInt();
            ret = true;
            }

        }
    return ret;
}

bool DBManager::modifyTask(int taskid, QString taskname, QString taskdesc, QString evaldesc, int evalrank){
    bool ret = false;

    if (db.isOpen())
        {

        QSqlQuery query(db);
        ret = query.exec(QString("update task set taskname = '%1', taskdesc = '%2', evaldesc = '%3', evalrank = %4 where taskid = %5")
                         .arg(taskname).arg(taskdesc).arg(evaldesc).arg(evalrank).arg(taskid));

 


        // Get database given autoincrement value
        if (ret)
            {
            query.lastInsertId().toInt();
            ret = true;
            }

        }
    return ret;
}

bool DBManager::deleteTask(int taskid){
    bool ret = false;

    if (db.isOpen())
    {

        QSqlQuery query(db);
        ret = query.exec(QString("delete from task where taskid = %1").arg(taskid));

        // Get database given autoincrement value
        if (ret)
           ret = true;

    }
    return ret;
}

QSqlError DBManager::lastError()
 {
    return db.lastError();
 }
