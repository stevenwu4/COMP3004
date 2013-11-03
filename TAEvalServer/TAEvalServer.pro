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
    Course.cpp \
    Task.cpp \
    TeachingAssistant.cpp \
    DBManager.cpp

HEADERS += \
    Server.h \
    ClientConnection.h \
    NetworkConnection.h \
    Course.h \
    Task.h \
    TeachingAssistant.h \
    DBManager.h
