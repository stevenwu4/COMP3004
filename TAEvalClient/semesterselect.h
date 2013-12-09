#ifndef SEMESTERSELECT_H
#define SEMESTERSELECT_H

#include <QDialog>

namespace Ui {
class SemesterSelect;
}

class SemesterSelect : public QDialog
{
    Q_OBJECT
    
public:
    explicit SemesterSelect(QWidget *parent = 0);
    ~SemesterSelect();
    
private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::SemesterSelect *ui;
    QWidget *p;
};

#endif // SEMESTERSELECT_H
