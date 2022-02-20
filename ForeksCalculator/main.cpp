#include <QtWidgets/QApplication>

#include "ForeksCalculatorController.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ForeksCalculatorController c;
    c.getView().show();

    return a.exec();
}
