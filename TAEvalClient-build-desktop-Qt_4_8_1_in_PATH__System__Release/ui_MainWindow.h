/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created: Mon Nov 4 23:48:19 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTextEdit *taskListTextEdit;
    QTextEdit *deleteInfoTextEdit;
    QTextEdit *deleteTextEdit;
    QTextEdit *taListTextEdit;
    QPushButton *editButton;
    QPushButton *taskListButton;
    QPushButton *deleteButton;
    QPushButton *courseListButton;
    QPushButton *createButton;
    QPushButton *taListButton;
    QTextEdit *createInfoTextEdit;
    QTextEdit *editTextEdit;
    QTextEdit *editInfoTextEdit;
    QTextEdit *taListInfoTextEdit;
    QTextEdit *taskListInfoTextEdit;
    QTextEdit *createTextEdit;
    QTextEdit *courseListTextEdit;
    QTextEdit *courseListInfotextEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(414, 1079);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMaximumSize(QSize(16777215, 16777215));
        centralWidget->setCursor(QCursor(Qt::ArrowCursor));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        taskListTextEdit = new QTextEdit(centralWidget);
        taskListTextEdit->setObjectName(QString::fromUtf8("taskListTextEdit"));
        taskListTextEdit->setEnabled(false);
        taskListTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        taskListTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(taskListTextEdit, 8, 1, 1, 1);

        deleteInfoTextEdit = new QTextEdit(centralWidget);
        deleteInfoTextEdit->setObjectName(QString::fromUtf8("deleteInfoTextEdit"));
        deleteInfoTextEdit->setEnabled(false);
        deleteInfoTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        deleteInfoTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(deleteInfoTextEdit, 16, 0, 2, 1);

        deleteTextEdit = new QTextEdit(centralWidget);
        deleteTextEdit->setObjectName(QString::fromUtf8("deleteTextEdit"));
        deleteTextEdit->setEnabled(false);
        deleteTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        deleteTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(deleteTextEdit, 17, 1, 1, 1);

        taListTextEdit = new QTextEdit(centralWidget);
        taListTextEdit->setObjectName(QString::fromUtf8("taListTextEdit"));
        taListTextEdit->setEnabled(false);
        taListTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        taListTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(taListTextEdit, 5, 1, 1, 1);

        editButton = new QPushButton(centralWidget);
        editButton->setObjectName(QString::fromUtf8("editButton"));

        gridLayout->addWidget(editButton, 13, 1, 1, 1);

        taskListButton = new QPushButton(centralWidget);
        taskListButton->setObjectName(QString::fromUtf8("taskListButton"));

        gridLayout->addWidget(taskListButton, 7, 1, 1, 1);

        deleteButton = new QPushButton(centralWidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        gridLayout->addWidget(deleteButton, 16, 1, 1, 1);

        courseListButton = new QPushButton(centralWidget);
        courseListButton->setObjectName(QString::fromUtf8("courseListButton"));

        gridLayout->addWidget(courseListButton, 0, 1, 1, 1);

        createButton = new QPushButton(centralWidget);
        createButton->setObjectName(QString::fromUtf8("createButton"));

        gridLayout->addWidget(createButton, 10, 1, 1, 1);

        taListButton = new QPushButton(centralWidget);
        taListButton->setObjectName(QString::fromUtf8("taListButton"));

        gridLayout->addWidget(taListButton, 4, 1, 1, 1);

        createInfoTextEdit = new QTextEdit(centralWidget);
        createInfoTextEdit->setObjectName(QString::fromUtf8("createInfoTextEdit"));
        createInfoTextEdit->setEnabled(false);
        createInfoTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        createInfoTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(createInfoTextEdit, 10, 0, 2, 1);

        editTextEdit = new QTextEdit(centralWidget);
        editTextEdit->setObjectName(QString::fromUtf8("editTextEdit"));
        editTextEdit->setEnabled(false);
        editTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        editTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(editTextEdit, 14, 1, 1, 1);

        editInfoTextEdit = new QTextEdit(centralWidget);
        editInfoTextEdit->setObjectName(QString::fromUtf8("editInfoTextEdit"));
        editInfoTextEdit->setEnabled(false);
        editInfoTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        editInfoTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(editInfoTextEdit, 13, 0, 2, 1);

        taListInfoTextEdit = new QTextEdit(centralWidget);
        taListInfoTextEdit->setObjectName(QString::fromUtf8("taListInfoTextEdit"));
        taListInfoTextEdit->setEnabled(false);
        taListInfoTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        taListInfoTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(taListInfoTextEdit, 4, 0, 2, 1);

        taskListInfoTextEdit = new QTextEdit(centralWidget);
        taskListInfoTextEdit->setObjectName(QString::fromUtf8("taskListInfoTextEdit"));
        taskListInfoTextEdit->setEnabled(false);
        taskListInfoTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        taskListInfoTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(taskListInfoTextEdit, 7, 0, 2, 1);

        createTextEdit = new QTextEdit(centralWidget);
        createTextEdit->setObjectName(QString::fromUtf8("createTextEdit"));
        createTextEdit->setEnabled(false);
        createTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        createTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(createTextEdit, 11, 1, 1, 1);

        courseListTextEdit = new QTextEdit(centralWidget);
        courseListTextEdit->setObjectName(QString::fromUtf8("courseListTextEdit"));
        courseListTextEdit->setEnabled(false);
        courseListTextEdit->setAutoFillBackground(false);
        courseListTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        courseListTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(courseListTextEdit, 1, 1, 1, 1);

        courseListInfotextEdit = new QTextEdit(centralWidget);
        courseListInfotextEdit->setObjectName(QString::fromUtf8("courseListInfotextEdit"));
        courseListInfotextEdit->setEnabled(false);
        courseListInfotextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        courseListInfotextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(courseListInfotextEdit, 0, 0, 2, 1);

        MainWindow->setCentralWidget(centralWidget);
        courseListButton->raise();
        taListButton->raise();
        taskListButton->raise();
        createButton->raise();
        editButton->raise();
        deleteButton->raise();
        deleteInfoTextEdit->raise();
        editInfoTextEdit->raise();
        createInfoTextEdit->raise();
        taskListInfoTextEdit->raise();
        taListInfoTextEdit->raise();
        courseListInfotextEdit->raise();
        deleteTextEdit->raise();
        editTextEdit->raise();
        createTextEdit->raise();
        taskListTextEdit->raise();
        taListTextEdit->raise();
        courseListTextEdit->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 414, 24));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        editButton->setText(QApplication::translate("MainWindow", "Edit/Evaluate Task", 0, QApplication::UnicodeUTF8));
        taskListButton->setText(QApplication::translate("MainWindow", "Request Task List", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("MainWindow", "Delete Task", 0, QApplication::UnicodeUTF8));
        courseListButton->setText(QApplication::translate("MainWindow", "Request Course List", 0, QApplication::UnicodeUTF8));
        createButton->setText(QApplication::translate("MainWindow", "Create Task", 0, QApplication::UnicodeUTF8));
        taListButton->setText(QApplication::translate("MainWindow", "Request TA List", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
