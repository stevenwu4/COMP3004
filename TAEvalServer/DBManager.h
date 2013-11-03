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

#ifndef DBMANAGER_H
#define DBMANAGER_H

class DBManager : public QObject {
public:
    explicit DBManager(QObject *parent = 0);
    ~DBManager(){}
    bool openDB();
    bool deleteDB();
    bool createDB();
    void populateDB();
    QString getTask(int id);
    void getCourse(QString term, int year);
    QSqlError lastError();
    std::vector<Course> _courses;
    std::vector<TeachingAssistant> _taList;
    //QVector<Course> *_courses;
    //QVectorIterator<Course> i(_courses);
    void initializeDB();
    void showCourse();
    void showTAs();
    void getTA(int courseid);
    void getCourseTA(int courseid);

private:
    QSqlDatabase db;
    bool createTaskTable();
    bool createTATable();
    bool createCourseTable();
    bool createInstructorTable();
    bool createCourseTATable();
    int createInstructor(int emplynum, QString fname, QString lname, QString dept);
    int createTA(int stdnum, QString fname, QString lname, QString degree, QString major, int year);
    int createCourse(QString coursename, QString coursecode, int year, QString term, int instructor);
    int createTask(QString taskname, QString taskdesc, QString evaldesc, int evalrank, int studentnum, int courseid);
    void clearServerState();
    int createCourseTA(int courseid, int stdnum);
};

#endif // DBMANAGER_H
