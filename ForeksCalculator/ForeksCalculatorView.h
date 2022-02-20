#pragma once

#include <QtGui>
#include <QObject>
#include <QWidget>
#include <QIcon>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QList>
#include <QDebug>

#include "foreksframe.h"
#include "forekslineedit.h"
#include "forekslabel.h"
#include "foreksbutton.h"

class ForeksCalculatorView : public QWidget
{
    Q_OBJECT

public:
    explicit ForeksCalculatorView(QWidget *parent = Q_NULLPTR);
    ~ForeksCalculatorView();

    QString getProcess(void) const;
    qreal getFirst(void) const;
    qreal getLast(void) const;
    qreal getAnswer(void) const;

public slots:
    void on_digitButton_clicked();
    void on_buttonDel_clicked();
    void on_buttonClear_clicked();
    void on_buttonMulti_clicked();
    void on_buttonDiv_clicked();
    void on_buttonSum_clicked();
    void on_buttonSub_clicked();
    void on_buttonDot_clicked();
    void on_buttonAns_clicked();
    void on_buttonAs_clicked();

signals:
    void setModel();

private:
    void setlabelFrame(void);
    void setlineEditFrame(void);
    void setButtonFrame(void);
    void setDigitButtons(void);
    void setDeleteButton(void);
    void setClearButton(void);
    void setMultiplicationButton(void);
    void setDivisionButton(void);
    void setSumButton(void);
    void setSubtractionButton(void);
    void setDotButton(void);
    void setAnswerButton(void);
    void setAssignmentButton(void);
    void setButtonFrameLayoutComponents(void);



private:
    ForeksFrame* labelFrame;
    ForeksFrame* lineEditFrame;
    ForeksFrame* buttonFrame;

    QVBoxLayout* centralLayout;
    QHBoxLayout* labelFrameLayout;
    QHBoxLayout* lineEditFrameLayout;
    QGridLayout* buttonFrameLayout;

    ForeksLabel* label;
    ForeksLineEdit* lineEdit;
    QList<ForeksButton*> buttonList;

    QString lineEditField;
    QString labelField;
    QString process;
    qreal first;
    qreal last;
    qreal answer;
};
