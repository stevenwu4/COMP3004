#ifndef COURSESELECT_H
#define COURSESELECT_H

#include <QDialog>

class TAEval;

namespace Ui {
class CourseSelect;
}

class CourseSelect : public QDialog {
    Q_OBJECT

private:
    TAEval* _taEval;
    
public:
    explicit CourseSelect(QWidget *parent, TAEval* taEval);
    ~CourseSelect();
    
private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();
    void timeout();

private:
    Ui::CourseSelect *ui;
    QWidget *p;
};

#endif // COURSESELECT_H
