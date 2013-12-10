/********************************************************************************
** Form generated from reading UI file 'CourseSelect.ui'
**
** Created: Tue Dec 10 01:32:34 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURSESELECT_H
#define UI_COURSESELECT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CourseSelect
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *courseList;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;

    void setupUi(QDialog *CourseSelect)
    {
        if (CourseSelect->objectName().isEmpty())
            CourseSelect->setObjectName(QString::fromUtf8("CourseSelect"));
        CourseSelect->resize(277, 269);
        layoutWidget = new QWidget(CourseSelect);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 258, 251));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        courseList = new QListWidget(layoutWidget);
        courseList->setObjectName(QString::fromUtf8("courseList"));
        courseList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        courseList->setAlternatingRowColors(true);
        courseList->setSortingEnabled(true);

        verticalLayout->addWidget(courseList);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setDefault(true);

        horizontalLayout->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CourseSelect);

        QMetaObject::connectSlotsByName(CourseSelect);
    } // setupUi

    void retranslateUi(QDialog *CourseSelect)
    {
        CourseSelect->setWindowTitle(QApplication::translate("CourseSelect", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CourseSelect", "Select a course", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("CourseSelect", "Cancel", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("CourseSelect", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CourseSelect: public Ui_CourseSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSESELECT_H
