#-------------------------------------------------
#
# Project created by QtCreator 2013-10-07T00:51:11
#
#-------------------------------------------------

QT       += core network sql

QT       -= gui

TARGET = TAEvalServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    Main.cpp \
    Server.cpp \
    ClientConnection.cpp \
    NetworkConnection.cpp \
    DBManager.cpp \
    Course.cpp \
    TeachingAssistant.cpp \
    Task.cpp \
    Instructor.cpp \
    Term.cpp \
    User.cpp

HEADERS += \
    Server.h \
    ClientConnection.h \
    NetworkConnection.h \
    DBManager.h \
    Course.h \
    TeachingAssistant.h \
    Task.h \
    Instructor.h \
    Term.h \
    User.h
