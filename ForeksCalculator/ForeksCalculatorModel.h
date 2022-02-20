#pragma once

#include <QObject>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QFile>

class ForeksCalculatorModel : public QObject
{
	Q_OBJECT

public:
	explicit ForeksCalculatorModel(QObject *parent = nullptr);
	~ForeksCalculatorModel();

	void setOperand(QString newOperand);
	void setFirst(qreal newFirst);
	void setLast(qreal newLast);
	void setResult(qreal newResult);
	void writeJSON(void);

private:
	void loadDocument(void);
	void setContent(void);

private:
	QFile* file;
	QJsonObject* content;
	QJsonDocument* document;
	QJsonArray* arr;

	QString operand;
	qreal first;
	qreal last;
	qreal result;
};
