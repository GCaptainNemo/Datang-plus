#ifndef WINDOW_HOUSECACOE_H
#define WINDOW_HOUSECACOE_H
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
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
#include "par_pinf.h"

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
    void group1SLOT(int p);
    void group2SLOT(int p);

protected:
    QWidget * widget1, *widget2, *widget3, *widget4, *widget5;
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

private:
    void initWidget1();
    void initWidget2();
    void initWidget3();
    void initWidget4();

};

#endif // WINDOW_HOUSECACOE_H
