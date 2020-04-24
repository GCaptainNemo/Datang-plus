#ifndef WINDOW_EMERGENCYSRYTANKANDAGITATOR_H
#define WINDOW_EMERGENCYSRYTANKANDAGITATOR_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include <QDebug>
#include <math.h>
#include "par_equip.h"
#include "par_gslresult.h"
#include "utils.h"


class emergencySryTankAndAgitatorWindow : public QDialog
{
    Q_OBJECT
public:
    explicit emergencySryTankAndAgitatorWindow(float & Dshg, float & Hshg, float & HDshg, float & Vshg, float & VTshg, float & Yshg,
                                               float & Nbshg, float & Nfshg, float & Neshg, float & Nkshg, QWidget *parent = nullptr);
    ~emergencySryTankAndAgitatorWindow();
    static int num;
    float KD(float & power);
    
signals:

public slots:
    virtual void okSLOT();
    
protected:
    QWidget * emeSryTankWidget, * emeAgitatorWidget;
    QLabel * emeSryTankLabel, * emeAgitatorLabel;

    QLabel * dLabel, *hLabel, *hdLabel, *veLabel, *vLabel, * vevLabel;
    QLineEdit * dLineedit, *hLineedit, *hdLineedit, *veLineedit, *vLineedit, * vevLineedit;
    
    QLabel * rPowerLabel, * shaftPowerLabel, * motorPowerLabel, * kdLabel;
    QLineEdit * rPowerLineedit, * shaftPowerLineedit, * motorPowerLineedit;
    QComboBox * kdComBox;
    
    QGridLayout * layout1, *layout2;
    QHBoxLayout * hlayout;
    QVBoxLayout * layout;
    
    QPushButton * okButton, *cancelButton;
    float dangwei[67] = {0.55, 0.75, 1.1, 1.5, 2.2, 3, 4, 5.5, 7.5, 11, 15, 18.5, 22, 30, 37, 45,
                         55, 75, 90, 110, 132, 160, 185,
                         200,220,250,280,315,355, 400,450,500,560,630,710,800,900,1000,1120,1250,1400,1600,1800,2000,2240,2500,2800, 3000,3150,3550,4000,4500,5000,5600,6300,7100,
                         8000,9000,10000,11200,12500,13000, 14000,15000,16000,17000,18000};
    void setKdComboBox(QComboBox * kdComboBox, const float &nkshpb);
    float YL(const float &p);
    
    float & Dshg, & Hshg, & HDshg, & Vshg, & VTshg, & Yshg;
    float & Nbshg, & Nfshg,  & Neshg,  & Nkshg;    
};

#endif // WINDOW_EMERGENCYSRYTANKANDAGITATOR_H
