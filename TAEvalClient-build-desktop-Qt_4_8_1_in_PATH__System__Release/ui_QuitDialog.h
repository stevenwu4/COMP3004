/********************************************************************************
** Form generated from reading UI file 'QuitDialog.ui'
**
** Created: Tue Dec 10 02:13:35 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUITDIALOG_H
#define UI_QUITDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuitDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QPushButton *quitButton;

    void setupUi(QDialog *QuitDialog)
    {
        if (QuitDialog->objectName().isEmpty())
            QuitDialog->setObjectName(QString::fromUtf8("QuitDialog"));
        QuitDialog->resize(203, 79);
        layoutWidget = new QWidget(QuitDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 180, 59));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setDefault(true);

        horizontalLayout->addWidget(cancelButton);

        quitButton = new QPushButton(layoutWidget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        horizontalLayout->addWidget(quitButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(QuitDialog);

        QMetaObject::connectSlotsByName(QuitDialog);
    } // setupUi

    void retranslateUi(QDialog *QuitDialog)
    {
        QuitDialog->setWindowTitle(QApplication::translate("QuitDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QuitDialog", "Really quit?", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("QuitDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("QuitDialog", "Quit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QuitDialog: public Ui_QuitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUITDIALOG_H