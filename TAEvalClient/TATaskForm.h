#ifndef TATASKFORM_H
#define TATASKFORM_H

#include <QWidget>

class TAEval;

namespace Ui {
class TATaskForm;
}

class TATaskForm : public QWidget {
    Q_OBJECT

private:
    TAEval* _taEval;
    
public:
    explicit TATaskForm(QWidget *parent, TAEval* taEval);
    ~TATaskForm();

    void alert(QString m);
    
private slots:
    void on_okButton_clicked();

private:
    Ui::TATaskForm *ui;
};

#endif // TATASKFORM_H
