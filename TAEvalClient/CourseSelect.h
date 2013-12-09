#ifndef COURSESELECT_H
#define COURSESELECT_H

#include <QDialog>

namespace Ui {
class CourseSelect;
}

class CourseSelect : public QDialog
{
    Q_OBJECT
    
public:
    explicit CourseSelect(QWidget *parent = 0);
    ~CourseSelect();
    
private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::CourseSelect *ui;
    QWidget *p;
};

#endif // COURSESELECT_H
