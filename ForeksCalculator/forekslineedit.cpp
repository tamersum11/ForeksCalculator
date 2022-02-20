#include "forekslineedit.h"

ForeksLineEdit::ForeksLineEdit(QString placeHolderText, QWidget *parent)
	: QLineEdit(parent)
{
	QString styleSheet = "border-radius:30px;border:1px solid #bdc1c6;background:transparent;background-color:white;color:#307fff;";

	font = new QFont("Century Gothic");
	font->setBold(true);
	font->setPointSizeF(26);

	validator = new QDoubleValidator(-9999999.9, 9999999.9, 2, this);

	setFont(*font);
	setStyleSheet(styleSheet);
	setPlaceholderText(placeHolderText);
	setAlignment(Qt::AlignRight);
	setValidator(validator);
}

ForeksLineEdit::~ForeksLineEdit()
{
	delete font;
	font = nullptr;

	delete validator;
	validator = nullptr;
}
