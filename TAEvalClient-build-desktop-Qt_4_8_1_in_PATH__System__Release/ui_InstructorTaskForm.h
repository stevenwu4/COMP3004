/********************************************************************************
** Form generated from reading UI file 'InstructorTaskForm.ui'
**
** Created: Tue Dec 10 01:58:25 2013
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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *semesterEdit;
    QLineEdit *courseEdit;
    QComboBox *taBox;
    QLineEdit *taskEdit;
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
        layoutWidget = new QWidget(InstructorTaskForm);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 501, 551));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        semesterEdit = new QLineEdit(layoutWidget);
        semesterEdit->setObjectName(QString::fromUtf8("semesterEdit"));
        semesterEdit->setEnabled(true);
        semesterEdit->setReadOnly(true);

        verticalLayout_2->addWidget(semesterEdit);

        courseEdit = new QLineEdit(layoutWidget);
        courseEdit->setObjectName(QString::fromUtf8("courseEdit"));
        courseEdit->setEnabled(true);
        courseEdit->setReadOnly(true);

        verticalLayout_2->addWidget(courseEdit);

        taBox = new QComboBox(layoutWidget);
        taBox->setObjectName(QString::fromUtf8("taBox"));

        verticalLayout_2->addWidget(taBox);

        taskEdit = new QLineEdit(layoutWidget);
        taskEdit->setObjectName(QString::fromUtf8("taskEdit"));

        verticalLayout_2->addWidget(taskEdit);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);

        descriptionLayout = new QVBoxLayout();
        descriptionLayout->setObjectName(QString::fromUtf8("descriptionLayout"));
        descriptionLabel = new QLabel(layoutWidget);
        descriptionLabel->setObjectName(QString::fromUtf8("descriptionLabel"));

        descriptionLayout->addWidget(descriptionLabel);

        descriptionText = new QPlainTextEdit(layoutWidget);
        descriptionText->setObjectName(QString::fromUtf8("descriptionText"));
        descriptionText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        descriptionLayout->addWidget(descriptionText);


        verticalLayout_3->addLayout(descriptionLayout);

        feedbackLayout = new QVBoxLayout();
        feedbackLayout->setObjectName(QString::fromUtf8("feedbackLayout"));
        feedbackLabel = new QLabel(layoutWidget);
        feedbackLabel->setObjectName(QString::fromUtf8("feedbackLabel"));

        feedbackLayout->addWidget(feedbackLabel);

        feedbackText = new QPlainTextEdit(layoutWidget);
        feedbackText->setObjectName(QString::fromUtf8("feedbackText"));
        feedbackText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        feedbackLayout->addWidget(feedbackText);


        verticalLayout_3->addLayout(feedbackLayout);

        ratingLayout = new QHBoxLayout();
        ratingLayout->setObjectName(QString::fromUtf8("ratingLayout"));
        ratingLabel = new QLabel(layoutWidget);
        ratingLabel->setObjectName(QString::fromUtf8("ratingLabel"));

        ratingLayout->addWidget(ratingLabel);

        ratingBox = new QComboBox(layoutWidget);
        ratingBox->setObjectName(QString::fromUtf8("ratingBox"));

        ratingLayout->addWidget(ratingBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ratingLayout->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(ratingLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_2->addWidget(cancelButton);

        okButton = new QPushButton(layoutWidget);
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
        semesterEdit->setText(QApplication::translate("InstructorTaskForm", "semester", 0, QApplication::UnicodeUTF8));
        courseEdit->setText(QApplication::translate("InstructorTaskForm", "course", 0, QApplication::UnicodeUTF8));
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
