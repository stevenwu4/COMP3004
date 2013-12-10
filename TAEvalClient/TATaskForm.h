#ifndef TATASKFORM_H
#define TATASKFORM_H

#include <QWidget>

namespace Ui {
class TATaskForm;
}

class TATaskForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit TATaskForm(QWidget *parent = 0);
    ~TATaskForm();
    
private slots:
    void on_okButton_clicked();

private:
    Ui::TATaskForm *ui;
};

#endif // TATASKFORM_H
