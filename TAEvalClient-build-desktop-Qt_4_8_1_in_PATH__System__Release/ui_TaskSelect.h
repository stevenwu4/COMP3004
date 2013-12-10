/********************************************************************************
** Form generated from reading UI file 'TaskSelect.ui'
**
** Created: Tue Dec 10 02:13:35 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKSELECT_H
#define UI_TASKSELECT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskSelect
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout;
    QPushButton *semesterButton;
    QPushButton *courseButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *createButton;
    QPushButton *editButton;
    QPushButton *evalButton;
    QPushButton *deleteButton;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *quitButton;

    void setupUi(QWidget *TaskSelect)
    {
        if (TaskSelect->objectName().isEmpty())
            TaskSelect->setObjectName(QString::fromUtf8("TaskSelect"));
        TaskSelect->resize(478, 419);
        layoutWidget = new QWidget(TaskSelect);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 461, 401));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);

        verticalLayout_2->addWidget(lineEdit_2);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);

        verticalLayout_2->addWidget(lineEdit);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        semesterButton = new QPushButton(layoutWidget);
        semesterButton->setObjectName(QString::fromUtf8("semesterButton"));

        verticalLayout->addWidget(semesterButton);

        courseButton = new QPushButton(layoutWidget);
        courseButton->setObjectName(QString::fromUtf8("courseButton"));

        verticalLayout->addWidget(courseButton);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        createButton = new QPushButton(layoutWidget);
        createButton->setObjectName(QString::fromUtf8("createButton"));
        createButton->setAutoDefault(true);
        createButton->setDefault(true);

        horizontalLayout_2->addWidget(createButton);

        editButton = new QPushButton(layoutWidget);
        editButton->setObjectName(QString::fromUtf8("editButton"));

        horizontalLayout_2->addWidget(editButton);

        evalButton = new QPushButton(layoutWidget);
        evalButton->setObjectName(QString::fromUtf8("evalButton"));

        horizontalLayout_2->addWidget(evalButton);

        deleteButton = new QPushButton(layoutWidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        horizontalLayout_2->addWidget(deleteButton);


        verticalLayout_4->addLayout(horizontalLayout_2);

        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);
        tableView->horizontalHeader()->setDefaultSectionSize(100);
        tableView->horizontalHeader()->setMinimumSectionSize(50);

        verticalLayout_4->addWidget(tableView);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        quitButton = new QPushButton(layoutWidget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        horizontalLayout_3->addWidget(quitButton);


        verticalLayout_4->addLayout(horizontalLayout_3);


        retranslateUi(TaskSelect);

        QMetaObject::connectSlotsByName(TaskSelect);
    } // setupUi

    void retranslateUi(QWidget *TaskSelect)
    {
        TaskSelect->setWindowTitle(QApplication::translate("TaskSelect", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TaskSelect", "Semester:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TaskSelect", "Course:", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QApplication::translate("TaskSelect", "select a semester", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("TaskSelect", "select a course", 0, QApplication::UnicodeUTF8));
        semesterButton->setText(QApplication::translate("TaskSelect", "Change Semester", 0, QApplication::UnicodeUTF8));
        courseButton->setText(QApplication::translate("TaskSelect", "Change Course", 0, QApplication::UnicodeUTF8));
        createButton->setText(QApplication::translate("TaskSelect", "Create", 0, QApplication::UnicodeUTF8));
        editButton->setText(QApplication::translate("TaskSelect", "Edit", 0, QApplication::UnicodeUTF8));
        evalButton->setText(QApplication::translate("TaskSelect", "Evaluate", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("TaskSelect", "Delete", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("TaskSelect", "Quit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TaskSelect: public Ui_TaskSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKSELECT_H
