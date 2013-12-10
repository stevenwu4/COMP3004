/********************************************************************************
** Form generated from reading UI file 'TATaskForm.ui'
**
** Created: Tue Dec 10 02:13:35 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TATASKFORM_H
#define UI_TATASKFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
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

class Ui_TATaskForm
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *semesterLabel;
    QLabel *courseLabel;
    QLabel *taLabel;
    QLabel *taskNameLabel;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *semesterText;
    QLineEdit *courseText;
    QLineEdit *instructorNameText;
    QLineEdit *taskNameText;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QLabel *taskDescriptionLabel;
    QPlainTextEdit *descriptionText;
    QVBoxLayout *verticalLayout_4;
    QLabel *feedbackLabel;
    QPlainTextEdit *feedbackText;
    QHBoxLayout *horizontalLayout_2;
    QLabel *ratingLabel;
    QLabel *rating;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *okButton;

    void setupUi(QWidget *TATaskForm)
    {
        if (TATaskForm->objectName().isEmpty())
            TATaskForm->setObjectName(QString::fromUtf8("TATaskForm"));
        TATaskForm->resize(480, 399);
        layoutWidget = new QWidget(TATaskForm);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 461, 379));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        semesterLabel = new QLabel(layoutWidget);
        semesterLabel->setObjectName(QString::fromUtf8("semesterLabel"));

        verticalLayout->addWidget(semesterLabel);

        courseLabel = new QLabel(layoutWidget);
        courseLabel->setObjectName(QString::fromUtf8("courseLabel"));

        verticalLayout->addWidget(courseLabel);

        taLabel = new QLabel(layoutWidget);
        taLabel->setObjectName(QString::fromUtf8("taLabel"));

        verticalLayout->addWidget(taLabel);

        taskNameLabel = new QLabel(layoutWidget);
        taskNameLabel->setObjectName(QString::fromUtf8("taskNameLabel"));

        verticalLayout->addWidget(taskNameLabel);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        semesterText = new QLineEdit(layoutWidget);
        semesterText->setObjectName(QString::fromUtf8("semesterText"));
        semesterText->setEnabled(true);
        semesterText->setReadOnly(true);

        verticalLayout_2->addWidget(semesterText);

        courseText = new QLineEdit(layoutWidget);
        courseText->setObjectName(QString::fromUtf8("courseText"));
        courseText->setEnabled(true);
        courseText->setReadOnly(true);

        verticalLayout_2->addWidget(courseText);

        instructorNameText = new QLineEdit(layoutWidget);
        instructorNameText->setObjectName(QString::fromUtf8("instructorNameText"));
        instructorNameText->setEnabled(true);
        instructorNameText->setReadOnly(true);

        verticalLayout_2->addWidget(instructorNameText);

        taskNameText = new QLineEdit(layoutWidget);
        taskNameText->setObjectName(QString::fromUtf8("taskNameText"));
        taskNameText->setEnabled(true);
        taskNameText->setReadOnly(true);

        verticalLayout_2->addWidget(taskNameText);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_5->addLayout(horizontalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        taskDescriptionLabel = new QLabel(layoutWidget);
        taskDescriptionLabel->setObjectName(QString::fromUtf8("taskDescriptionLabel"));

        verticalLayout_3->addWidget(taskDescriptionLabel);

        descriptionText = new QPlainTextEdit(layoutWidget);
        descriptionText->setObjectName(QString::fromUtf8("descriptionText"));
        descriptionText->setEnabled(true);
        descriptionText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        descriptionText->setReadOnly(true);

        verticalLayout_3->addWidget(descriptionText);


        verticalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        feedbackLabel = new QLabel(layoutWidget);
        feedbackLabel->setObjectName(QString::fromUtf8("feedbackLabel"));

        verticalLayout_4->addWidget(feedbackLabel);

        feedbackText = new QPlainTextEdit(layoutWidget);
        feedbackText->setObjectName(QString::fromUtf8("feedbackText"));
        feedbackText->setEnabled(true);
        feedbackText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        feedbackText->setReadOnly(true);

        verticalLayout_4->addWidget(feedbackText);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ratingLabel = new QLabel(layoutWidget);
        ratingLabel->setObjectName(QString::fromUtf8("ratingLabel"));

        horizontalLayout_2->addWidget(ratingLabel);

        rating = new QLabel(layoutWidget);
        rating->setObjectName(QString::fromUtf8("rating"));
        rating->setFrameShadow(QFrame::Plain);

        horizontalLayout_2->addWidget(rating);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setAutoDefault(true);
        okButton->setDefault(true);

        horizontalLayout_2->addWidget(okButton);


        verticalLayout_5->addLayout(horizontalLayout_2);


        retranslateUi(TATaskForm);

        QMetaObject::connectSlotsByName(TATaskForm);
    } // setupUi

    void retranslateUi(QWidget *TATaskForm)
    {
        TATaskForm->setWindowTitle(QApplication::translate("TATaskForm", "Form", 0, QApplication::UnicodeUTF8));
        semesterLabel->setText(QApplication::translate("TATaskForm", "Semester:", 0, QApplication::UnicodeUTF8));
        courseLabel->setText(QApplication::translate("TATaskForm", "Course:", 0, QApplication::UnicodeUTF8));
        taLabel->setText(QApplication::translate("TATaskForm", "Instructor:", 0, QApplication::UnicodeUTF8));
        taskNameLabel->setText(QApplication::translate("TATaskForm", "Task:", 0, QApplication::UnicodeUTF8));
        semesterText->setText(QApplication::translate("TATaskForm", "semester", 0, QApplication::UnicodeUTF8));
        courseText->setText(QApplication::translate("TATaskForm", "course", 0, QApplication::UnicodeUTF8));
        instructorNameText->setText(QApplication::translate("TATaskForm", "first name last name", 0, QApplication::UnicodeUTF8));
        taskNameText->setText(QApplication::translate("TATaskForm", "task name", 0, QApplication::UnicodeUTF8));
        taskDescriptionLabel->setText(QApplication::translate("TATaskForm", "Description:", 0, QApplication::UnicodeUTF8));
        descriptionText->setPlainText(QApplication::translate("TATaskForm", "text text text text text text text text text text text text text text text text text text text text text text text", 0, QApplication::UnicodeUTF8));
        feedbackLabel->setText(QApplication::translate("TATaskForm", "Feedback:", 0, QApplication::UnicodeUTF8));
        feedbackText->setPlainText(QApplication::translate("TATaskForm", "text text text text text text text text text text text text text text text text text text text text text text text", 0, QApplication::UnicodeUTF8));
        ratingLabel->setText(QApplication::translate("TATaskForm", "Rating:", 0, QApplication::UnicodeUTF8));
        rating->setText(QApplication::translate("TATaskForm", "4/5 - Very Good", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("TATaskForm", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TATaskForm: public Ui_TATaskForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TATASKFORM_H
