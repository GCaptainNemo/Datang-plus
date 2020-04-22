#ifndef WINDOW_HOUSECACOE_H
#define WINDOW_HOUSECACOE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QDialog>
#include <QRadioButton>
#include <QButtonGroup>
#include <math.h>
#include "par_equip.h"


class caco3HouseWindow : public QDialog
{
    Q_OBJECT
public:
    explicit caco3HouseWindow(QWidget *parent = nullptr);
    ~caco3HouseWindow();
    static int num;


signals:

public slots:
    void okSLOT();
    void group1SLOT(int p, bool status);
    void group2SLOT(int p, bool status);

protected:
    QWidget * widget1, *widget2, *widget3, *widget4;
    QGridLayout *layout1, *layout2, *layout3, *layout4;

    QLabel * sryTankLabel;
    QLabel  *singleFurnaceLabel, * fgdNumLabel, *bufferTimeLabel, *houseNumLabel, * dLabel, *coreAngleLabel, *hBarrelLabel, *hCoreLabel, *veLabel, *vLabel, * vevLabel;

    QLineEdit *singleFurnaceLineedit, *fgdNumLineedit, *bufferTimeLineedit,  *houseNumLineedit, * dLineedit, *coreAngleLineedit, *hBarrelLineedit, *hCoreLineedit, *veLineedit, *vLineedit, * vevLineedit;
    QLabel *houseStyleLabel, *coreStyleLabel;
    QHBoxLayout * hlayout;
    QPushButton * okButton, *calButton, *cancelButton;
    QVBoxLayout * layout;

    QButtonGroup * group1, *group2;
    QRadioButton * cirHouseRadiobutton, *sqrHouseRadiobutton, * cirCoreRadiobutton, *sqrCoreRadiobutton;

};

#endif // WINDOW_HOUSECACOE_H
