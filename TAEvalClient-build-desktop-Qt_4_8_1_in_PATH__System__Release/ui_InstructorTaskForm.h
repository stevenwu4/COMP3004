/********************************************************************************
** Form generated from reading UI file 'InstructorTaskForm.ui'
**
** Created: Mon Dec 9 22:17:40 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUCTORTASKFORM_H
#define UI_INSTRUCTORTASKFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InstructorTaskForm
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit_3;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *descriptionLayout;
    QLabel *descriptionLabel;
    QPlainTextEdit *descriptionText;
    QVBoxLayout *feedbackLayout;
    QLabel *feedbackLabel;
    QPlainTextEdit *feedbackText;
    QHBoxLayout *ratingLayout;
    QLabel *ratingLabel;
    QComboBox *ratingBox;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QWidget *InstructorTaskForm)
    {
        if (InstructorTaskForm->objectName().isEmpty())
            InstructorTaskForm->setObjectName(QString::fromUtf8("InstructorTaskForm"));
        InstructorTaskForm->resize(518, 572);
        widget = new QWidget(InstructorTaskForm);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 501, 551));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);

        verticalLayout_2->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);

        verticalLayout_2->addWidget(lineEdit_2);

        comboBox_2 = new QComboBox(widget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        verticalLayout_2->addWidget(comboBox_2);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout_2->addWidget(lineEdit_3);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);

        descriptionLayout = new QVBoxLayout();
        descriptionLayout->setObjectName(QString::fromUtf8("descriptionLayout"));
        descriptionLabel = new QLabel(widget);
        descriptionLabel->setObjectName(QString::fromUtf8("descriptionLabel"));

        descriptionLayout->addWidget(descriptionLabel);

        descriptionText = new QPlainTextEdit(widget);
        descriptionText->setObjectName(QString::fromUtf8("descriptionText"));
        descriptionText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        descriptionLayout->addWidget(descriptionText);


        verticalLayout_3->addLayout(descriptionLayout);

        feedbackLayout = new QVBoxLayout();
        feedbackLayout->setObjectName(QString::fromUtf8("feedbackLayout"));
        feedbackLabel = new QLabel(widget);
        feedbackLabel->setObjectName(QString::fromUtf8("feedbackLabel"));

        feedbackLayout->addWidget(feedbackLabel);

        feedbackText = new QPlainTextEdit(widget);
        feedbackText->setObjectName(QString::fromUtf8("feedbackText"));
        feedbackText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        feedbackLayout->addWidget(feedbackText);


        verticalLayout_3->addLayout(feedbackLayout);

        ratingLayout = new QHBoxLayout();
        ratingLayout->setObjectName(QString::fromUtf8("ratingLayout"));
        ratingLabel = new QLabel(widget);
        ratingLabel->setObjectName(QString::fromUtf8("ratingLabel"));

        ratingLayout->addWidget(ratingLabel);

        ratingBox = new QComboBox(widget);
        ratingBox->setObjectName(QString::fromUtf8("ratingBox"));

        ratingLayout->addWidget(ratingBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ratingLayout->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(ratingLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_2->addWidget(cancelButton);

        okButton = new QPushButton(widget);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setAutoDefault(true);
        okButton->setDefault(true);

        horizontalLayout_2->addWidget(okButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(InstructorTaskForm);

        QMetaObject::connectSlotsByName(InstructorTaskForm);
    } // setupUi

    void retranslateUi(QWidget *InstructorTaskForm)
    {
        InstructorTaskForm->setWindowTitle(QApplication::translate("InstructorTaskForm", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("InstructorTaskForm", "Semester:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("InstructorTaskForm", "Course:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("InstructorTaskForm", "Teaching Assistant:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("InstructorTaskForm", "Task Name:", 0, QApplication::UnicodeUTF8));
        descriptionLabel->setText(QApplication::translate("InstructorTaskForm", "Description:", 0, QApplication::UnicodeUTF8));
        feedbackLabel->setText(QApplication::translate("InstructorTaskForm", "Feedback:", 0, QApplication::UnicodeUTF8));
        ratingLabel->setText(QApplication::translate("InstructorTaskForm", "Rating:", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("InstructorTaskForm", "Cancel", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("InstructorTaskForm", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InstructorTaskForm: public Ui_InstructorTaskForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUCTORTASKFORM_H
