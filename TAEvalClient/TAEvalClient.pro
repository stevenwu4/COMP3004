#-------------------------------------------------
#
# Project created by QtCreator 2013-10-21T19:49:32
#
#-------------------------------------------------

QT       += core gui network

TARGET = TAEvalClient
TEMPLATE = app


SOURCES +=\
    Main.cpp \
    TAEval.cpp \
    NetworkConnection.cpp \
    CreateTaskController.cpp \
    Course.cpp \
    ViewTeachingAssistantsController.cpp \
    ViewTasksController.cpp \
    ViewCoursesController.cpp \
    TeachingAssistant.cpp \
    Task.cpp \
    EditTaskController.cpp \
    DeleteTaskController.cpp \
    loginwindow.cpp \
    semesterselect.cpp \
    CourseSelect.cpp \
    TaskSelect.cpp \
    InstructorTaskForm.cpp \
    QuitDialog.cpp \
    TATaskForm.cpp \
    LoginController.cpp \
    SemesterSelectController.cpp \
    Term.cpp

HEADERS  += \
    TAEval.h \
    NetworkConnection.h \
    CreateTaskController.h \
    Course.h \
    ViewTeachingAssistantsController.h \
    ViewTasksController.h \
    ViewCoursesController.h \
    TeachingAssistant.h \
    Task.h \
    EditTaskController.h \
    DeleteTaskController.h \
    loginwindow.h \
    semesterselect.h \
    CourseSelect.h \
    TaskSelect.h \
    InstructorTaskForm.h \
    QuitDialog.h \
    TATaskForm.h \
    LoginController.h \
    SemesterSelectController.h \
    Term.h

FORMS    += MainWindow.ui \
    loginwindow.ui \
    semesterselect.ui \
    CourseSelect.ui \
    TaskSelect.ui \
    InstructorTaskForm.ui \
    QuitDialog.ui \
    TATaskForm.ui
