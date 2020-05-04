#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "widget_central.h"

middleWidget::middleWidget(QWidget *parent) : QWidget(parent)
{
    this->vlayout = new QVBoxLayout(this);
    widgetMain = new QWidget(this);
    widgetFlowChart = new QWidget(this);
    pushButton = new QPushButton(tr("烟气1"), widgetMain);
    pushButton_2 = new QPushButton(tr("浆液1"), widgetMain);
    connect(pushButton, SIGNAL(clicked(bool)), this, SLOT(showFlueGasParSLOT()));
    connect(pushButton_2, SIGNAL(clicked(bool)), this, SLOT(showSrySLOT()));

    this->vlayout->addWidget(this->widgetMain);
//    widgetMain->setAutoFillBackground(true);

}

void middleWidget::showFlueGasParSLOT()
{
    this->windowParFlueGas = new window_parameter_flue_gas(this);
}

void middleWidget::showSrySLOT()
{
    this->windowParSry = new window_parameter_slurry(this);
}
