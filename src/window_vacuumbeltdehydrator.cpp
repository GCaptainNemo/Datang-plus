﻿#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "window_vacuumbeltdehydrator.h"


int vacuumBeltDehydratorWindow::num = 0;

vacuumBeltDehydratorWindow::vacuumBeltDehydratorWindow(float & Qzhk,
                                                       float & Szhk, float & Nezhk, float & Qzhb,
                                                       float & Nfzhb, float & Nezhb, float & Dlb,
                                                       float & Hlb, float & Vjlb, float & Qlbb,
                                                       float & Hlbb, float & Nelbb, QWidget * parent) : QDialog(parent)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);

    vacuumBeltDehydratorWindow::num += 1;
    this->setAttribute(Qt::WA_DeleteOnClose);

    initVacuumBelt();
    initVacuumPump();
    initWaterPump();
    initWaterTank();

    this->maxForceLineeidt->setText(QString("%1").arg(Qzhk));
    this->filtAreaLineeidt->setText(QString("%1").arg(Szhk));
    this->motorPowerLineeidt->setText(QString("%1").arg(Nezhk));
    this->vacuumForceLineedit ->setText(QString("%1").arg(Qzhb));
    this->shaftPowerLineedit->setText(QString("%1").arg(Nfzhb));
    this->vacuumPumpPowerLineedit->setText(QString("%1").arg(Nezhb));
    this->flowLineedit->setText(QString("%1").arg(Qlbb));
    this->liftLineedit->setText(QString("%1").arg(Hlbb));
    this->waterPumpPowerLineedit->setText(QString("%1").arg(Nelbb));
    this->dLineedit->setText(QString("%1").arg(Dlb));
    this->hLineedit ->setText(QString("%1").arg(Hlb));
    this->vLineedit->setText(QString("%1").arg(Vjlb));




    buttonWidget = new widget_okcancel(this);
    connect(buttonWidget->cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));

    vlayout = new QVBoxLayout(this);
    vlayout->addWidget(vacuumBeltWidget);
    vlayout->addWidget(vacuumPumpWidget);
    vlayout->addWidget(waterTankWidget);
    vlayout->addWidget(waterPumpWidget);
    vlayout->addWidget(buttonWidget);

    this->setWindowTitle(tr("真空皮带脱水机"));
    this->show();
}

void vacuumBeltDehydratorWindow::initVacuumBelt()
{
    vacuumBeltWidget = new QWidget(this);
    layout1 = new QGridLayout(vacuumBeltWidget);
    this->vacuumBeltLabel = new QLabel(tr("真空皮带脱水机"), vacuumBeltWidget);
    this->maxForceLabel = new QLabel(tr("最大出力(t/h):"), vacuumBeltWidget);
    this->maxForceLineeidt = new QLineEdit(vacuumBeltWidget);
    this->maxForceLineeidt->setReadOnly(true);
    this->filtAreaLabel = new QLabel(tr("过滤面积(m2):"), vacuumBeltWidget);
    this->filtAreaLineeidt = new QLineEdit(vacuumBeltWidget);
    this->filtAreaLineeidt->setReadOnly(true);
    this->motorPowerLabel = new QLabel(tr("主驱动电机功率(kW):"), vacuumBeltWidget);
    this->motorPowerLineeidt = new QLineEdit(vacuumBeltWidget);
    this->motorPowerLineeidt->setReadOnly(true);
    layout1->addWidget(this->vacuumBeltLabel);
    layout1->addWidget(this->maxForceLabel, 1, 0, 1, 3);
    layout1->addWidget(this->maxForceLineeidt, 1, 3, 1, 3);
    layout1->addWidget(this->filtAreaLabel, 2, 0, 1, 3);
    layout1->addWidget(this->filtAreaLineeidt, 2, 3, 1, 3);
    layout1->addWidget(this->motorPowerLabel, 3, 0, 1, 3);
    layout1->addWidget(this->motorPowerLineeidt, 3, 3, 1, 3);
}

void vacuumBeltDehydratorWindow::initVacuumPump()
{
    this->vacuumPumpWidget = new QWidget(this);
    this->vacuumPumpLabel = new QLabel(tr("真空泵"), vacuumPumpWidget);
    this->layout2 = new QGridLayout(vacuumPumpWidget);
    this->vacuumForceLabel = new QLabel(tr("真空泵出力(m3/h):"), vacuumPumpWidget);
    this->vacuumForceLineedit = new QLineEdit(vacuumPumpWidget);
    this->vacuumForceLineedit ->setReadOnly(true);
    this->shaftPowerLabel = new QLabel(tr("轴功率(kW):"), vacuumPumpWidget);
    this->shaftPowerLineedit = new QLineEdit(vacuumPumpWidget);
    this->shaftPowerLineedit->setReadOnly(true);
    this->vacuumPumpPowerLabel= new QLabel(tr("功率(kW):"), vacuumPumpWidget);
    this->vacuumPumpPowerLineedit = new QLineEdit(vacuumPumpWidget);
    this->vacuumPumpPowerLineedit->setReadOnly(true);
    layout2->addWidget(this->vacuumPumpLabel);
    layout2->addWidget(this->vacuumForceLabel, 1, 0, 1, 3);
    layout2->addWidget(this->vacuumForceLineedit, 1, 3, 1, 3);
    layout2->addWidget(this->shaftPowerLabel, 2, 0, 1, 3);
    layout2->addWidget(this->shaftPowerLineedit, 2, 3, 1, 3);
    layout2->addWidget(this->vacuumPumpPowerLabel, 3, 0, 1, 3);
    layout2->addWidget(this->vacuumPumpPowerLineedit, 3, 3, 1, 3);

}

void vacuumBeltDehydratorWindow::initWaterTank()
{

    this->waterTankWidget = new QWidget(this);
    this->waterTankLabel = new QLabel(tr("滤布洗水箱"), waterTankWidget);
    this->layout3 = new QGridLayout(waterTankWidget);
    this->dLabel = new QLabel(tr("直径(m):"), waterTankWidget);
    this->dLineedit = new QLineEdit(waterTankWidget);
    this->dLineedit->setReadOnly(true);
    this->hLabel = new QLabel(tr("高度(m):"), waterTankWidget);
    this->hLineedit = new QLineEdit(waterTankWidget);
    this->hLineedit ->setReadOnly(true);
    this->vLabel = new QLabel(tr("有效容积(m3):"), waterTankWidget);
    this->vLineedit = new QLineEdit(waterTankWidget);
    this->vLineedit->setReadOnly(true);
    layout3->addWidget(this->waterTankLabel, 0, 0, 1, 6);
    layout3->addWidget(this->dLabel, 1, 0, 1, 3);
    layout3->addWidget(this->dLineedit, 1, 3, 1, 3);
    layout3->addWidget(this->hLabel, 2, 0, 1, 3);
    layout3->addWidget(this->hLineedit, 2, 3, 1, 3);
    layout3->addWidget(this->vLabel, 3, 0, 1, 3);
    layout3->addWidget(this->vLineedit, 3, 3, 1, 3);
}

void vacuumBeltDehydratorWindow::initWaterPump()
{
    this->waterPumpWidget = new QWidget(this);
    this->waterPumpLabel = new QLabel(tr("滤布冲洗水泵"), waterPumpWidget);
    this->layout4 = new QGridLayout(waterPumpWidget);
    this->flowLabel = new QLabel(tr("流量(m3/h):"), waterPumpWidget);
    this->flowLineedit = new QLineEdit(waterPumpWidget);
    this->flowLineedit->setReadOnly(true);
    this->liftLabel = new QLabel(tr("扬程(m):"), waterPumpWidget);
    this->liftLineedit = new QLineEdit(waterPumpWidget);
    this->liftLineedit->setReadOnly(true);

    this->waterPumpPowerLabel = new QLabel(tr("功率(kW):"), waterPumpWidget);
    this->waterPumpPowerLineedit = new QLineEdit(waterPumpWidget);
    this->waterPumpPowerLineedit->setReadOnly(true);
    layout4->addWidget(this->waterPumpLabel, 0, 0, 1, 6);
    layout4->addWidget(this->flowLabel, 1, 0, 1, 3);
    layout4->addWidget(this->flowLineedit, 1, 3, 1, 3);
    layout4->addWidget(this->liftLabel, 2, 0, 1, 3);
    layout4->addWidget(this->liftLineedit, 2, 3, 1, 3);
    layout4->addWidget(this->waterPumpPowerLabel, 3, 0, 1, 3);
    layout4->addWidget(this->waterPumpPowerLineedit, 3, 3, 1, 3);
}



vacuumBeltDehydratorWindow::~vacuumBeltDehydratorWindow()
{
    vacuumBeltDehydratorWindow::num -= 1;
}

