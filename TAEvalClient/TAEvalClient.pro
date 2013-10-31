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
    ViewCoursesController.cpp \
    Course.cpp \
    ViewCoursesTestCase.cpp \
    Task.cpp \
    TeachingAssistant.cpp \
    ViewTeachingAssistantsController.cpp \
    ViewTeachingAssistantsTestCase.cpp \
    ViewTasksController.cpp \
    ViewTasksTestCase.cpp \
    CreateTaskController.cpp \
    CreateTaskTestCase.cpp

HEADERS  += MainWindow.h \
    TAEval.h \
    NetworkConnection.h \
    ViewCoursesController.h \
    Course.h \
    ViewCoursesTestCase.h \
    Task.h \
    TeachingAssistant.h \
    ViewTeachingAssistantsController.h \
    ViewTeachingAssistantsTestCase.h \
    ViewTasksController.h \
    ViewTasksTestCase.h \
    CreateTaskController.h \
    CreateTaskTestCase.h

FORMS    += MainWindow.ui
