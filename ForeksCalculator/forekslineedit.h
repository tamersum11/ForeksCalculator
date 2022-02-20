#pragma once

#include <QLineEdit>
#include <QFont>
#include <QDoubleValidator>

class ForeksLineEdit : public QLineEdit
{
	Q_OBJECT

public:
	explicit ForeksLineEdit(QString placeHolderText = "", QWidget* parent = nullptr);
	~ForeksLineEdit();

private:
	QFont* font;
	QDoubleValidator* validator;
};
