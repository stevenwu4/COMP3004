#ifndef TERM_H
#define TERM_H

#include <QString>

class Term {
private:
	QString _season;
	int _year;

public:
	Term(const QString& season, int year);

	const QString& season() const;
	int year() const;
};

#endif // TERM_H