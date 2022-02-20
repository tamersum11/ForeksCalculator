#pragma once

#include <QLabel>
#include <QFont>

class ForeksLabel : public QLabel
{
	Q_OBJECT

public:
	explicit ForeksLabel(QString text = "Calculator", QWidget * parent = nullptr);
	~ForeksLabel();

private:
	QFont* font;
};
