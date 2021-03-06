﻿#ifndef WINDOW_VACUUMBELTDEHYDRATOR_H
#define WINDOW_VACUUMBELTDEHYDRATOR_H
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include <QWidget>
#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "widget_okcancel.h"


class vacuumBeltDehydratorWindow : public QDialog
{
    Q_OBJECT
public:
    explicit vacuumBeltDehydratorWindow(float & Qzhk,
                                        float & Szhk, float & Nezhk, float & Qzhb,
                                        float & Nfzhb, float & Nezhb, float & Dlb,
                                        float & Hlb, float & Vjlb, float & Qlbb,
                                        float & Hlbb, float & Nelbb, QWidget *parent = nullptr);
    static int num;
    ~vacuumBeltDehydratorWindow();

signals:

public slots:


private:

    QLabel * vacuumBeltLabel, *vacuumPumpLabel, *waterTankLabel, *waterPumpLabel;

    QLabel * maxForceLabel, * filtAreaLabel, * motorPowerLabel;
    QLineEdit * maxForceLineeidt, * filtAreaLineeidt, * motorPowerLineeidt;

    QLabel * vacuumForceLabel, * shaftPowerLabel, *vacuumPumpPowerLabel;
    QLineEdit * vacuumForceLineedit, * shaftPowerLineedit, *vacuumPumpPowerLineedit;

    QLabel * dLabel, * hLabel, *vLabel;
    QLineEdit * dLineedit, * hLineedit, *vLineedit;

    QLabel * flowLabel, *liftLabel, * waterPumpPowerLabel;
    QLineEdit * flowLineedit, *liftLineedit, * waterPumpPowerLineedit;

    QWidget * vacuumBeltWidget, *vacuumPumpWidget, *waterTankWidget, *waterPumpWidget;
    QGridLayout * layout1, *layout2, *layout3, *layout4;

    QVBoxLayout * vlayout;
    widget_okcancel * buttonWidget;
    void initVacuumBelt();
    void initVacuumPump();
    void initWaterTank();
    void initWaterPump();

};

#endif // WINDOW_VACUUMBELTDEHYDRATOR_H
