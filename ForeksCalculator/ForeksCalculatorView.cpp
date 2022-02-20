#include "ForeksCalculatorView.h"

ForeksCalculatorView::ForeksCalculatorView(QWidget* parent)
    : QWidget(parent)
{
    setStyleSheet("background-color:#0d1117;");
    resize(400, 500);
    setWindowTitle("Calculator");
    setWindowIcon(QIcon(QPixmap(":/new/prefix1/calculator-4-256.png")));

    centralLayout = new QVBoxLayout();
    setlabelFrame();
    setlineEditFrame();
    setButtonFrame();
    centralLayout->addWidget(labelFrame);
    centralLayout->addWidget(lineEditFrame);
    centralLayout->addWidget(buttonFrame);
    setLayout(centralLayout);

    lineEditField = "";
    labelField = "";
    process = "";
    first = 0.0;
    last = 0.0;
    answer = 0.0;
}

ForeksCalculatorView::~ForeksCalculatorView()
{
    delete label;
    label = nullptr;

    delete lineEdit;
    lineEdit = nullptr;

    qDeleteAll(buttonList);
    buttonList.clear();

    delete centralLayout;
    centralLayout = nullptr;

    delete labelFrameLayout;
    labelFrameLayout = nullptr;

    delete lineEditFrameLayout;
    lineEditFrameLayout = nullptr;

    delete buttonFrameLayout;
    buttonFrameLayout = nullptr;

    delete labelFrame;
    labelFrame = nullptr;

    delete lineEditFrame;
    lineEditFrame = nullptr;

    delete buttonFrame;
    buttonFrame = nullptr;
}

QString ForeksCalculatorView::getProcess(void) const
{
    return process;
}

qreal ForeksCalculatorView::getFirst(void) const
{
    return first;
}

qreal ForeksCalculatorView::getLast(void) const
{
    return last;
}

qreal ForeksCalculatorView::getAnswer(void) const
{
    return answer;
}

void ForeksCalculatorView::on_digitButton_clicked()
{
    ForeksButton* clickedButton = qobject_cast<ForeksButton*>(sender());
    lineEditField += clickedButton->text();
    lineEdit->setText(lineEditField);
}

void ForeksCalculatorView::on_buttonDel_clicked()
{
    lineEditField = "";
    lineEdit->clear();
}

void ForeksCalculatorView::on_buttonClear_clicked()
{
    labelField = "";
    label->setText("Calculator");
    lineEditField = "";
    lineEdit->clear();
    first = 0.0;
    last = 0.0;
    answer = 0.0;
}

void ForeksCalculatorView::on_buttonMulti_clicked()
{
    process = "x";
    first = lineEdit->text().toDouble();
    labelField = QString::number(first) + " " + process + " ";
    label->setText(labelField);
    lineEditField = "";
    lineEdit->clear();
}

void ForeksCalculatorView::on_buttonDiv_clicked()
{
    process = "/";
    first = lineEdit->text().toDouble();
    labelField = QString::number(first) + " " + process + " ";
    label->setText(labelField);
    lineEditField = "";
    lineEdit->clear();
}

void ForeksCalculatorView::on_buttonSum_clicked()
{
    process = "+";
    first = lineEdit->text().toDouble();
    labelField = QString::number(first) + " " + process + " ";
    label->setText(labelField);
    lineEditField = "";
    lineEdit->clear();
}

void ForeksCalculatorView::on_buttonSub_clicked()
{
    process = "-";
    first = lineEdit->text().toDouble();
    labelField = QString::number(first) + " " + process + " ";
    label->setText(labelField);
    lineEditField = "";
    lineEdit->clear();
}

void ForeksCalculatorView::on_buttonDot_clicked()
{
    lineEditField +=  lineEditField.contains(".") ? "" : ".";
    lineEdit->setText(lineEditField);
}

void ForeksCalculatorView::on_buttonAns_clicked()
{
    labelField = "";
    lineEditField = "";
    lineEditField += QString::number(answer);
    lineEdit->setText(lineEditField);
}

void ForeksCalculatorView::on_buttonAs_clicked()
{
    last = lineEdit->text().toDouble();

    if (process == "x") {
        answer = first * last;
    }
    else if (process == "/") {
        answer = (last != 0) ? first / last : answer;
    }
    else if (process == "+") {
        answer = first + last;
    }
    else if (process == "-") {
        answer = first - last;
    }
    else {
        labelField = "Calculator";
        lineEditField = "";
        lineEdit->clear();
        return ;
    }

    labelField += QString::number(last) + " =";
    label->setText(labelField);
    lineEditField = "";
    lineEditField += QString::number(answer);
    lineEdit->setText(lineEditField);

    emit setModel();
    process = "";
}

void ForeksCalculatorView::setlabelFrame(void)
{
    labelFrame = new ForeksFrame();
    labelFrameLayout = new QHBoxLayout();
    label = new ForeksLabel();
    labelFrameLayout->addWidget(label);
    labelFrame->setLayout(labelFrameLayout);
    labelFrameLayout->setAlignment(Qt::AlignRight);
    labelFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}

void ForeksCalculatorView::setlineEditFrame(void)
{
    lineEditFrame = new ForeksFrame();
    lineEditFrameLayout = new QHBoxLayout();
    lineEdit = new ForeksLineEdit("Calculate");
    lineEditFrameLayout->addWidget(lineEdit);
    lineEditFrame->setLayout(lineEditFrameLayout);
    lineEditFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}

void ForeksCalculatorView::setButtonFrame(void)
{
    buttonFrame = new ForeksFrame();
    buttonFrameLayout = new QGridLayout();
    setDigitButtons();
    setDeleteButton();
    setClearButton();
    setMultiplicationButton();
    setDivisionButton();
    setSumButton();
    setSubtractionButton();
    setDotButton();
    setAnswerButton();
    setAssignmentButton();
    setButtonFrameLayoutComponents();
    buttonFrame->setLayout(buttonFrameLayout);
}

void ForeksCalculatorView::setDigitButtons(void)
{
    for (int i = 0; i <= 9; i++)
    {
        ForeksButton* button = new ForeksButton(QString::number(i));
        buttonList.append(button);
        QObject::connect(button, &ForeksButton::clicked, this, &ForeksCalculatorView::on_digitButton_clicked);
    }
}

void ForeksCalculatorView::setDeleteButton(void)
{
    QString styleSheet = "border-radius:30px;border:2px solid #307fff;background-color:white;color:#202124;";
    ForeksButton* buttonDel = new ForeksButton("DEL");
    buttonDel->setStyleSheet(styleSheet);
    buttonList.append(buttonDel);
    QObject::connect(buttonDel, &ForeksButton::clicked, this, &ForeksCalculatorView::on_buttonDel_clicked);
}

void ForeksCalculatorView::setClearButton(void)
{
    QString styleSheet = "border-radius:30px;border:2px solid #307fff;background-color:white;color:#202124;";
    ForeksButton* buttonClear = new ForeksButton("Clear");
    buttonClear->setStyleSheet(styleSheet);
    buttonList.append(buttonClear);
    QObject::connect(buttonClear, &ForeksButton::clicked, this, &ForeksCalculatorView::on_buttonClear_clicked);
}

void ForeksCalculatorView::setMultiplicationButton(void)
{
    QString styleSheet = "border-radius:30px;border:2px solid #307fff;background-color:white;color:#202124;";
    ForeksButton* buttonMulti = new ForeksButton("x");
    buttonMulti->setStyleSheet(styleSheet);
    buttonList.append(buttonMulti);
    QObject::connect(buttonMulti, &ForeksButton::clicked, this, &ForeksCalculatorView::on_buttonMulti_clicked);
}

void ForeksCalculatorView::setDivisionButton(void)
{
    QString styleSheet = "border-radius:30px;border:2px solid #307fff;background-color:white;color:#202124;";
    ForeksButton* buttonDiv = new ForeksButton("/");
    buttonDiv->setStyleSheet(styleSheet);
    buttonList.append(buttonDiv);
    QObject::connect(buttonDiv, &ForeksButton::clicked, this, &ForeksCalculatorView::on_buttonDiv_clicked);
}

void ForeksCalculatorView::setSumButton(void)
{
    QString styleSheet = "border-radius:30px;border:2px solid #307fff;background-color:white;color:#202124;";
    ForeksButton* buttonSum = new ForeksButton("+");
    buttonSum->setStyleSheet(styleSheet);
    buttonList.append(buttonSum);
    QObject::connect(buttonSum, &ForeksButton::clicked, this, &ForeksCalculatorView::on_buttonSum_clicked);
}

void ForeksCalculatorView::setSubtractionButton(void)
{
    QString styleSheet = "border-radius:30px;border:2px solid #307fff;background-color:white;color:#202124;";
    ForeksButton* buttonSub = new ForeksButton("-");
    buttonSub->setStyleSheet(styleSheet);
    buttonList.append(buttonSub);
    QObject::connect(buttonSub, &ForeksButton::clicked, this, &ForeksCalculatorView::on_buttonSub_clicked);
}

void ForeksCalculatorView::setDotButton(void)
{
    ForeksButton* buttonDot = new ForeksButton(".");
    buttonList.append(buttonDot);
    QObject::connect(buttonDot, &ForeksButton::clicked, this, &ForeksCalculatorView::on_buttonDot_clicked);
}

void ForeksCalculatorView::setAnswerButton(void)
{
    QString styleSheet = "border-radius:30px;border:2px solid #307fff;background-color:white;color:#202124;";
    ForeksButton* buttonAns = new ForeksButton("ANS");
    buttonAns->setStyleSheet(styleSheet);
    buttonList.append(buttonAns);
    QObject::connect(buttonAns, &ForeksButton::clicked, this, &ForeksCalculatorView::on_buttonAns_clicked);
}

void ForeksCalculatorView::setAssignmentButton(void)
{
    QString styleSheet = "border-radius:30px;border:2px solid #307fff;background-color:white;color:#202124;";
    ForeksButton* buttonAs = new ForeksButton("=");
    buttonAs->setStyleSheet(styleSheet);
    buttonList.append(buttonAs);
    QObject::connect(buttonAs, &ForeksButton::clicked, this, &ForeksCalculatorView::on_buttonAs_clicked);
}

void ForeksCalculatorView::setButtonFrameLayoutComponents(void)
{
    buttonFrameLayout->addWidget(buttonList[0], 3, 1);
    buttonFrameLayout->addWidget(buttonList[1], 2, 0);
    buttonFrameLayout->addWidget(buttonList[2], 2, 1); 
    buttonFrameLayout->addWidget(buttonList[3], 2, 2);
    buttonFrameLayout->addWidget(buttonList[4], 1, 0);
    buttonFrameLayout->addWidget(buttonList[5], 1, 1);
    buttonFrameLayout->addWidget(buttonList[6], 1, 2);
    buttonFrameLayout->addWidget(buttonList[7], 0, 0);
    buttonFrameLayout->addWidget(buttonList[8], 0, 1);
    buttonFrameLayout->addWidget(buttonList[9], 0, 2);
    buttonFrameLayout->addWidget(buttonList[10], 0, 3);
    buttonFrameLayout->addWidget(buttonList[11], 0, 4);
    buttonFrameLayout->addWidget(buttonList[12], 1, 3);
    buttonFrameLayout->addWidget(buttonList[13], 1, 4);
    buttonFrameLayout->addWidget(buttonList[14], 2, 3);
    buttonFrameLayout->addWidget(buttonList[15], 2, 4);
    buttonFrameLayout->addWidget(buttonList[16], 3, 2);
    buttonFrameLayout->addWidget(buttonList[17], 3, 3); 
    buttonFrameLayout->addWidget(buttonList[18], 3, 4);
}
