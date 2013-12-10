/********************************************************************************
** Form generated from reading UI file 'semesterselect.ui'
**
** Created: Tue Dec 10 01:32:33 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEMESTERSELECT_H
#define UI_SEMESTERSELECT_H

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

class Ui_SemesterSelect
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QListWidget *semesterList;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;

    void setupUi(QDialog *SemesterSelect)
    {
        if (SemesterSelect->objectName().isEmpty())
            SemesterSelect->setObjectName(QString::fromUtf8("SemesterSelect"));
        SemesterSelect->resize(281, 278);
        layoutWidget = new QWidget(SemesterSelect);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 260, 253));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        semesterList = new QListWidget(layoutWidget);
        semesterList->setObjectName(QString::fromUtf8("semesterList"));
        semesterList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        semesterList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        semesterList->setAlternatingRowColors(true);
        semesterList->setSortingEnabled(true);

        verticalLayout->addWidget(semesterList);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setAutoDefault(true);
        okButton->setDefault(true);
        okButton->setFlat(false);

        horizontalLayout->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(SemesterSelect);

        QMetaObject::connectSlotsByName(SemesterSelect);
    } // setupUi

    void retranslateUi(QDialog *SemesterSelect)
    {
        SemesterSelect->setWindowTitle(QApplication::translate("SemesterSelect", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SemesterSelect", "Select a semester", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("SemesterSelect", "Cancel", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("SemesterSelect", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SemesterSelect: public Ui_SemesterSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEMESTERSELECT_H
