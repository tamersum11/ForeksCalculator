#pragma once

#include <QPushButton>
#include <QFont>

class ForeksButton : public QPushButton
{
	Q_OBJECT

public:
	explicit ForeksButton(QString text = "", QWidget * parent = nullptr);
	~ForeksButton();

private:
	QFont* font;
};
