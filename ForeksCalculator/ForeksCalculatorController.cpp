#include "ForeksCalculatorController.h"

ForeksCalculatorController::ForeksCalculatorController(QObject *parent)
	: QObject(parent)
{
	view = new ForeksCalculatorView();
	QObject::connect(view, &ForeksCalculatorView::setModel, this, &ForeksCalculatorController::setForeksCalculatorModel);

	model = new ForeksCalculatorModel();
}

ForeksCalculatorController::~ForeksCalculatorController()
{
	delete view;
	view = nullptr;

	delete model;
	model = nullptr;
}

void ForeksCalculatorController::setForeksCalculatorModel()
{
	model->setOperand(view->getProcess());
	model->setFirst(view->getFirst());
	model->setLast(view->getLast());
	model->setResult(view->getAnswer());

	model->writeJSON();
}

ForeksCalculatorView& ForeksCalculatorController::getView(void) const
{
	return *view;
}

