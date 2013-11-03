/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created: Sun Nov 3 01:44:53 2013
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
    QTextEdit *courseListInfotextEdit;
    QPushButton *editButton;
    QPushButton *taskListButton;
    QPushButton *evaluateButton;
    QPushButton *deleteButton;
    QTextEdit *courseListTextEdit;
    QTextEdit *evaluateInfoTextEdit;
    QTextEdit *taListInfoTextEdit;
    QPushButton *courseListButton;
    QTextEdit *createTextEdit;
    QTextEdit *deleteTextEdit;
    QPushButton *createButton;
    QTextEdit *taskListTextEdit;
    QTextEdit *taskListInfoTextEdit;
    QPushButton *taListButton;
    QTextEdit *createInfoTextEdit;
    QTextEdit *taListTextEdit;
    QTextEdit *editTextEdit;
    QTextEdit *evaluateTextEdit;
    QTextEdit *editInfoTextEdit;
    QTextEdit *deleteInfoTextEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(448, 454);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        courseListInfotextEdit = new QTextEdit(centralWidget);
        courseListInfotextEdit->setObjectName(QString::fromUtf8("courseListInfotextEdit"));
        courseListInfotextEdit->setEnabled(false);
        courseListInfotextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        courseListInfotextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(courseListInfotextEdit, 2, 0, 1, 2);

        editButton = new QPushButton(centralWidget);
        editButton->setObjectName(QString::fromUtf8("editButton"));

        gridLayout->addWidget(editButton, 9, 0, 1, 1);

        taskListButton = new QPushButton(centralWidget);
        taskListButton->setObjectName(QString::fromUtf8("taskListButton"));

        gridLayout->addWidget(taskListButton, 5, 0, 1, 1);

        evaluateButton = new QPushButton(centralWidget);
        evaluateButton->setObjectName(QString::fromUtf8("evaluateButton"));

        gridLayout->addWidget(evaluateButton, 11, 0, 1, 1);

        deleteButton = new QPushButton(centralWidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        gridLayout->addWidget(deleteButton, 13, 0, 1, 1);

        courseListTextEdit = new QTextEdit(centralWidget);
        courseListTextEdit->setObjectName(QString::fromUtf8("courseListTextEdit"));
        courseListTextEdit->setEnabled(false);
        courseListTextEdit->setAutoFillBackground(false);
        courseListTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        courseListTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(courseListTextEdit, 0, 1, 1, 1);

        evaluateInfoTextEdit = new QTextEdit(centralWidget);
        evaluateInfoTextEdit->setObjectName(QString::fromUtf8("evaluateInfoTextEdit"));
        evaluateInfoTextEdit->setEnabled(false);
        evaluateInfoTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        evaluateInfoTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(evaluateInfoTextEdit, 12, 0, 1, 2);

        taListInfoTextEdit = new QTextEdit(centralWidget);
        taListInfoTextEdit->setObjectName(QString::fromUtf8("taListInfoTextEdit"));
        taListInfoTextEdit->setEnabled(false);
        taListInfoTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        taListInfoTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(taListInfoTextEdit, 4, 0, 1, 2);

        courseListButton = new QPushButton(centralWidget);
        courseListButton->setObjectName(QString::fromUtf8("courseListButton"));

        gridLayout->addWidget(courseListButton, 0, 0, 1, 1);

        createTextEdit = new QTextEdit(centralWidget);
        createTextEdit->setObjectName(QString::fromUtf8("createTextEdit"));
        createTextEdit->setEnabled(false);
        createTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        createTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(createTextEdit, 7, 1, 1, 1);

        deleteTextEdit = new QTextEdit(centralWidget);
        deleteTextEdit->setObjectName(QString::fromUtf8("deleteTextEdit"));
        deleteTextEdit->setEnabled(false);
        deleteTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        deleteTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(deleteTextEdit, 13, 1, 1, 1);

        createButton = new QPushButton(centralWidget);
        createButton->setObjectName(QString::fromUtf8("createButton"));

        gridLayout->addWidget(createButton, 7, 0, 1, 1);

        taskListTextEdit = new QTextEdit(centralWidget);
        taskListTextEdit->setObjectName(QString::fromUtf8("taskListTextEdit"));
        taskListTextEdit->setEnabled(false);
        taskListTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        taskListTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(taskListTextEdit, 5, 1, 1, 1);

        taskListInfoTextEdit = new QTextEdit(centralWidget);
        taskListInfoTextEdit->setObjectName(QString::fromUtf8("taskListInfoTextEdit"));
        taskListInfoTextEdit->setEnabled(false);
        taskListInfoTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        taskListInfoTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(taskListInfoTextEdit, 6, 0, 1, 2);

        taListButton = new QPushButton(centralWidget);
        taListButton->setObjectName(QString::fromUtf8("taListButton"));

        gridLayout->addWidget(taListButton, 3, 0, 1, 1);

        createInfoTextEdit = new QTextEdit(centralWidget);
        createInfoTextEdit->setObjectName(QString::fromUtf8("createInfoTextEdit"));
        createInfoTextEdit->setEnabled(false);
        createInfoTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        createInfoTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(createInfoTextEdit, 8, 0, 1, 2);

        taListTextEdit = new QTextEdit(centralWidget);
        taListTextEdit->setObjectName(QString::fromUtf8("taListTextEdit"));
        taListTextEdit->setEnabled(false);
        taListTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        taListTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(taListTextEdit, 3, 1, 1, 1);

        editTextEdit = new QTextEdit(centralWidget);
        editTextEdit->setObjectName(QString::fromUtf8("editTextEdit"));
        editTextEdit->setEnabled(false);
        editTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        editTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(editTextEdit, 9, 1, 1, 1);

        evaluateTextEdit = new QTextEdit(centralWidget);
        evaluateTextEdit->setObjectName(QString::fromUtf8("evaluateTextEdit"));
        evaluateTextEdit->setEnabled(false);
        evaluateTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        evaluateTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(evaluateTextEdit, 11, 1, 1, 1);

        editInfoTextEdit = new QTextEdit(centralWidget);
        editInfoTextEdit->setObjectName(QString::fromUtf8("editInfoTextEdit"));
        editInfoTextEdit->setEnabled(false);
        editInfoTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        editInfoTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(editInfoTextEdit, 10, 0, 1, 2);

        deleteInfoTextEdit = new QTextEdit(centralWidget);
        deleteInfoTextEdit->setObjectName(QString::fromUtf8("deleteInfoTextEdit"));
        deleteInfoTextEdit->setEnabled(false);
        deleteInfoTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        deleteInfoTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(deleteInfoTextEdit, 14, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        courseListButton->raise();
        courseListButton->raise();
        courseListButton->raise();
        courseListTextEdit->raise();
        taListButton->raise();
        taListTextEdit->raise();
        taskListButton->raise();
        taskListTextEdit->raise();
        courseListInfotextEdit->raise();
        createButton->raise();
        createTextEdit->raise();
        editButton->raise();
        editTextEdit->raise();
        evaluateButton->raise();
        evaluateTextEdit->raise();
        deleteButton->raise();
        deleteTextEdit->raise();
        taListInfoTextEdit->raise();
        taskListInfoTextEdit->raise();
        createInfoTextEdit->raise();
        editInfoTextEdit->raise();
        evaluateInfoTextEdit->raise();
        deleteInfoTextEdit->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 448, 24));
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
        editButton->setText(QApplication::translate("MainWindow", "Edit Task", 0, QApplication::UnicodeUTF8));
        taskListButton->setText(QApplication::translate("MainWindow", "Request Task List", 0, QApplication::UnicodeUTF8));
        evaluateButton->setText(QApplication::translate("MainWindow", "Evaluate Task", 0, QApplication::UnicodeUTF8));
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
