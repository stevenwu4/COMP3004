#ifndef SEMESTERSELECT_H
#define SEMESTERSELECT_H

#include <QDialog>

class TAEval;

namespace Ui {
class SemesterSelect;
}

class SemesterSelect : public QDialog {
    Q_OBJECT
    
private:
    TAEval* _taEval;

public:
    explicit SemesterSelect(QWidget *parent, TAEval* taEval);
    ~SemesterSelect();
    
private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::SemesterSelect *ui;
    QWidget *p;
};

#endif // SEMESTERSELECT_H
