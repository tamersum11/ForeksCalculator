#include "ForeksCalculatorModel.h"

ForeksCalculatorModel::ForeksCalculatorModel(QObject *parent)
	: QObject(parent)
{
	file = new QFile("record.json");
	content = new QJsonObject();
	document = new QJsonDocument();
	arr = new QJsonArray();

	operand = "";
	first = 0.0;
	last = 0.0;
	result = 0.0;

	loadDocument();
}

ForeksCalculatorModel::~ForeksCalculatorModel()
{
	delete file;
	file = nullptr;

	delete content;
	content = nullptr;

	delete document;
	document = nullptr;

	delete arr;
	arr = nullptr;
}

void ForeksCalculatorModel::setOperand(QString newOperand)
{
	operand = newOperand;
}

void ForeksCalculatorModel::setFirst(qreal newFirst)
{
	first = newFirst;
}

void ForeksCalculatorModel::setLast(qreal newLast)
{
	last = newLast;
}

void ForeksCalculatorModel::setResult(qreal newResult)
{
	result = newResult;
}

void ForeksCalculatorModel::writeJSON(void)
{
	setContent();
	QByteArray bytes = document->toJson(QJsonDocument::Indented);
	if (file->open(QIODevice::WriteOnly))
	{
		QTextStream iStream(file);
		iStream.setEncoding(QStringConverter::Utf8);
		iStream << bytes;
		file->close();
	}
	else
	{
		QMessageBox::critical(nullptr, "FAIL", "record.json file is not opened!");
	}

}

void ForeksCalculatorModel::loadDocument(void)
{
	if (!file->open(QIODevice::ReadOnly)) {
		QMessageBox::information(nullptr, "FILE", "record.json file is not opened but it is created!");
		return;
	}

	*document = QJsonDocument::fromJson(file->readAll());
	file->close();

	*arr = document->array();
}

void ForeksCalculatorModel::setContent(void)
{
	content->insert("first", first);
	content->insert("operand", operand);
	content->insert("last", last);
	content->insert("result", result);

	arr->push_back(*content);
	document->setArray(*arr);
}
