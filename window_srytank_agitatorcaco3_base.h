#ifndef WINDOW_SRYTANKANDAGITATORCACO3_H
#define WINDOW_SRYTANKANDAGITATORCACO3_H

#include <QDialog>
#include <QWidget>
#include <math.h>
#include "par_equip.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "par_gslresult.h"
#include "utils.h"
#include "widget_okcancel.h"

class caco3SryTankAndAgitatorWindow: public QDialog
{
    Q_OBJECT
public:
    static int num;
    explicit caco3SryTankAndAgitatorWindow(float & Qsj, int & FGDnum, float & Tsj, float & Dsj, float & Hsj, float & HDsj,  float & Vjsj, float & VTjsj, float & Ysj,
                                           float & Nbsj, float & Nfsj, float & Nesj, float & Nksj, QWidget *parent = nullptr);
    ~caco3SryTankAndAgitatorWindow();

signals:

public slots:
    void okSLOT();

protected:
    float & Qsj;
    int &FGDnum;
    float & Tsj, & Dsj, & Hsj, & HDsj, & Vjsj, & VTjsj, & Ysj, & Nbsj, & Nfsj,  & Nesj,  & Nksj;
    QWidget * sryTankWidget, * agitatorWidget;
    QLabel * sryTankLabel, * agitatorLabel;

    QLabel  *singleFurnaceLabel, * fgdNumLabel, *bufferTimeLabel,  * dLabel, *hLabel, *hdLabel, *veLabel, *vLabel, * vevLabel;
    QLineEdit *singleFurnaceLineedit, *fgdNumLineedit, *bufferTimeLineedit,  * dLineedit, *hLineedit, *hdLineedit, *veLineedit, *vLineedit, * vevLineedit;

    QLabel * rPowerLabel, * shaftPowerLabel, * motorPowerLabel, * kdLabel;
    QLineEdit * rPowerLineedit, * shaftPowerLineedit, * motorPowerLineedit;
    QComboBox * kdComBox;

    QGridLayout * layout1, *layout2;
    QVBoxLayout * layout;

    widget_okcancel * buttonWidget;
    float dangwei[67] = {0.55, 0.75, 1.1, 1.5, 2.2, 3, 4, 5.5, 7.5, 11, 15, 18.5, 22, 30, 37, 45,
                         55, 75, 90, 110, 132, 160, 185,
                         200,220,250,280,315,355, 400,450,500,560,630,710,800,900,1000,1120,1250,1400,1600,1800,2000,2240,2500,2800, 3000,3150,3550,4000,4500,5000,5600,6300,7100,
                         8000,9000,10000,11200,12500,13000, 14000,15000,16000,17000,18000};
    void setKdComboBox(QComboBox * kdComboBox, const float &nkshpb);
    void initSryTank();
    void initAgitator();
    float YL(const float &p);


};

#endif // WINDOW_SRYTANKANDAGITATORCACO3_H
