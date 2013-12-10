#ifndef TASKSELECT_H
#define TASKSELECT_H

#include <QWidget>

namespace Ui {
class TaskSelect;
}

class TaskSelect : public QWidget
{
    Q_OBJECT
    
public:
    explicit TaskSelect(QWidget *parent = 0);
    ~TaskSelect();
    
private slots:
    void on_semesterButton_clicked();

    void on_courseButton_clicked();

    void on_createButton_clicked();

    void on_editButton_clicked();

    void on_evalButton_clicked();

    void on_deleteButton_clicked();

    void on_quitButton_clicked();

    void alert(QString);

private:
    Ui::TaskSelect *ui;
};

#endif // TASKSELECT_H
