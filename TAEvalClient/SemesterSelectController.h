#ifndef SEMESTERSELECTCONTROLLER_H
#define SEMESTERSELECTCONTROLLER_H

#include <QObject>

class TAEval;
class SemesterSelect;
class Term;

class SemesterSelectController : public QObject {
    Q_OBJECT

private:
    SemesterSelect* _semesterSelect;
    TAEval* _taEval;

public:
    SemesterSelectController(SemesterSelect* semesterSelect, TAEval* taEval);
    void invoke(const Term& term) const;

private slots:
    void termRetrieved();
    void timeout();
};

#endif // SEMESTERSELECTCONTROLLER_H
