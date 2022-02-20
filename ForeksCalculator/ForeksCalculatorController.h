#pragma once

#include <QObject>
#include <QDebug>

#include "ForeksCalculatorView.h"
#include "ForeksCalculatorModel.h"

class ForeksCalculatorController : public QObject
{
	Q_OBJECT

public:
	explicit ForeksCalculatorController(QObject *parent = nullptr);
	~ForeksCalculatorController();

	ForeksCalculatorView& getView(void) const;

public slots:
	void setForeksCalculatorModel();

private:
	ForeksCalculatorView* view;
	ForeksCalculatorModel* model;
};
