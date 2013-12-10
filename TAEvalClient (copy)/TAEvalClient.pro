#-------------------------------------------------
#
# Project created by QtCreator 2013-10-21T19:49:32
#
#-------------------------------------------------

QT       += core gui network

TARGET = TAEvalClient
TEMPLATE = app


SOURCES +=\
        MainWindow.cpp \
    Main.cpp \
    TAEval.cpp \
    NetworkConnection.cpp \
    CreateTaskTestCase.cpp \
    CreateTaskController.cpp \
    Course.cpp \
    ViewTeachingAssistantsTestCase.cpp \
    ViewTeachingAssistantsController.cpp \
    ViewTasksTestCase.cpp \
    ViewTasksController.cpp \
    ViewCoursesTestCase.cpp \
    ViewCoursesController.cpp \
    TeachingAssistant.cpp \
    Task.cpp \
    EditTaskTestCase.cpp \
    EditTaskController.cpp \
    DeleteTaskTestCase.cpp \
    DeleteTaskController.cpp \
    Instructor.cpp

HEADERS  += MainWindow.h \
    TAEval.h \
    NetworkConnection.h \
    CreateTaskTestCase.h \
    CreateTaskController.h \
    Course.h \
    ViewTeachingAssistantsTestCase.h \
    ViewTeachingAssistantsController.h \
    ViewTasksTestCase.h \
    ViewTasksController.h \
    ViewCoursesTestCase.h \
    ViewCoursesController.h \
    TeachingAssistant.h \
    Task.h \
    EditTaskTestCase.h \
    EditTaskController.h \
    DeleteTaskTestCase.h \
    DeleteTaskController.h \
    Instructor.h

FORMS    += MainWindow.ui
