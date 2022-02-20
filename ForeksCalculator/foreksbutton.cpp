#include "foreksbutton.h"

ForeksButton::ForeksButton(QString text, QWidget *parent)
	: QPushButton(parent)
{
	QString styleSheet = "border-radius:30px;border:1px solid #bdc1c6;background-color:#202124;color:#307fff;";

	font = new QFont("Century Gothic");
	font->setBold(true);
	font->setPointSizeF(26);

	setFont(*font);
	setStyleSheet(styleSheet);
	setText(text);
}

ForeksButton::~ForeksButton()
{
	delete font;
	font = nullptr;
}
