#include "forekslabel.h"

ForeksLabel::ForeksLabel(QString text, QWidget *parent)
	: QLabel(parent)
{
	font = new QFont("Century Gothic");
	font->setBold(true);
	font->setPointSizeF(14);

	setFont(*font);
	setStyleSheet("color:green;");
	setText(text);
	setAlignment(Qt::AlignRight);
}

ForeksLabel::~ForeksLabel()
{
	delete font;
	font = nullptr;
}
