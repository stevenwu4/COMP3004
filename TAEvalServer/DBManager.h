#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDir>

#ifndef DBMANAGER_H
#define DBMANAGER_H

#endif // DBMANAGER_H



class DBManager : public QObject
    {

    public:
        explicit DBManager(QObject *parent = 0);
        ~DBManager(){}
        bool openDB();
        bool deleteDB();
        bool createTaskTable();
        bool createTATable();
        bool createCourseTable();
        bool createInstructorTable();

    private:
        QSqlDatabase db;
    };
