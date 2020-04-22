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


    gasInputTLabel = new QLabel(tr("原烟气进口温度(°C):"));
    gasOutputTLabel = new QLabel(tr("净烟气进口温度(°C):"));
    outputTLabel = new QLabel(tr("出口温度(°C)"));
    gasFlowLabel = new QLabel(tr("烟气通气量(kg/h):"));
    gasInputTLineedit = new QLineEdit;
    gasOutputTLineedit = new QLineEdit;
    outputTLineedit = new QLineEdit;
    gasFlowLineedit = new QLineEdit;
    
    gasInputTLineedit ->setText(QString("%1").arg(gasResultPar::Gas[0][1][22]));
    gasOutputTLineedit->setText(QString("%1").arg(gasResultPar::Gas[0][3][22]));
    outputTLineedit->setText(tr("80"));
    gasFlowLineedit->setText(QString("%1").arg(gasResultPar::Gas[0][1][4]));

    gridLayout = new QGridLayout;
    gridLayout->addWidget(gasInputTLabel, 0, 0, 1, 3);
    gridLayout->addWidget(gasInputTLineedit, 0, 3, 1, 3);
    gridLayout->addWidget(gasOutputTLabel, 1, 0, 1, 3);
    gridLayout->addWidget(gasOutputTLineedit, 1, 3, 1, 3);
    gridLayout->addWidget(outputTLabel, 2, 0, 1, 3);
    gridLayout->addWidget(outputTLineedit, 2, 3, 1, 3);
    gridLayout->addWidget(gasFlowLabel, 3, 0, 1, 3);
    gridLayout->addWidget(gasFlowLineedit, 3, 3, 1, 3);


    hlayout = new QHBoxLayout;
    okButton = new QPushButton(tr("确定"));
    connect(okButton, SIGNAL(clicked(bool)), this, SLOT(okSLOT()));
    cancelButton = new QPushButton(tr("关闭"));
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    hlayout->addWidget(okButton);
    hlayout->addWidget(cancelButton);


    layout = new QVBoxLayout(this);
    layout->addLayout(gridLayout);
    layout->addLayout(hlayout);
    this->show();
}


heatExchangeWindow::~heatExchangeWindow()
{
    heatExchangeWindow::num -= 1;
}

void heatExchangeWindow::okSLOT()
{

}
