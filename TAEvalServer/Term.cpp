#include "Term.h"

Term::Term(const QString& season, int year) :
    _season(season),
    _year(year) {}

const QString& Term::season() const {
    return _season;
}

int Term::year() const {
    return _year;
}
