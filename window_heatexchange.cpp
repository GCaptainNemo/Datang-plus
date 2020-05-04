#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "window_heatexchange.h"

int heatExchangeWindow::num = 0;

heatExchangeWindow::heatExchangeWindow(QWidget *parent) : QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);

    heatExchangeWindow::num += 1;
    this->setWindowTitle(tr("换热器"));
    this->setAttribute(Qt::WA_DeleteOnClose);

    gridWidget = new QWidget(this);
    gasInputLabel = new QLabel(tr("原烟气进口温度(°C):"), this->gridWidget);
    gasOutputLabel = new QLabel(tr("净烟气进口温度(°C):"), this->gridWidget);
    outputLabel = new QLabel(tr("出口温度(°C)"), this->gridWidget);
    gasFlowLabel = new QLabel(tr("烟气通气量(kg/h):"), this->gridWidget);
    gasInputLineedit = new QLineEdit(this->gridWidget);
    gasOutputLineedit = new QLineEdit(this->gridWidget);
    outputLineedit = new QLineEdit(this->gridWidget);
    gasFlowLineedit = new QLineEdit(this->gridWidget);

    gasInputLineedit ->setText(QString("%1").arg(gasResultPar::Gas[0][1][22]));
    gasOutputLineedit->setText(QString("%1").arg(gasResultPar::Gas[0][3][22]));
    outputLineedit->setText(tr("80"));
    gasFlowLineedit->setText(QString("%1").arg(gasResultPar::Gas[0][1][4]));

    gridLayout = new QGridLayout(gridWidget);
    gridLayout->addWidget(gasInputLabel, 0, 0, 1, 3);
    gridLayout->addWidget(gasInputLineedit, 0, 3, 1, 3);
    gridLayout->addWidget(gasOutputLabel, 1, 0, 1, 3);
    gridLayout->addWidget(gasOutputLineedit, 1, 3, 1, 3);
    gridLayout->addWidget(outputLabel, 2, 0, 1, 3);
    gridLayout->addWidget(outputLineedit, 2, 3, 1, 3);
    gridLayout->addWidget(gasFlowLabel, 3, 0, 1, 3);
    gridLayout->addWidget(gasFlowLineedit, 3, 3, 1, 3);


    buttonWidget = new widget_okcancel(this);
    connect(buttonWidget->okButton, SIGNAL(clicked(bool)), this, SLOT(okSLOT()));
    connect(buttonWidget->cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));

    layout = new QVBoxLayout(this);
    layout->addWidget(gridWidget);
    layout->addWidget(buttonWidget);
    this->show();
}


heatExchangeWindow::~heatExchangeWindow()
{
    heatExchangeWindow::num -= 1;
}

void heatExchangeWindow::okSLOT()
{

}
