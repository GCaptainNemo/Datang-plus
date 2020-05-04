#ifndef CASO4DISCHARGEPUMP_WINDOW_H
#define CASO4DISCHARGEPUMP_WINDOW_H
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include <QWidget>
#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <math.h>
#include "par_gslresult.h"
#include "par_gasresult.h"
#include "utils.h"
#include "widget_okcancel.h"


class caso4DischargePumpWindow : public QDialog
{
    Q_OBJECT
public:
    explicit caso4DischargePumpWindow(float & yshpb, float & qshpb, float & hshpb, float & nfshpb,
                                      float & neshpb, float & nkshpb, QWidget *parent = nullptr);
    ~caso4DischargePumpWindow();
    static int num;

signals:

public slots:
    virtual void okSLOT();


protected:
    float & yshpb; // 效率
    float & qshpb; // 流量
    float & hshpb; // 扬程
    float & nfshpb; //轴功率
    float & neshpb; // 电机功率
    float & nkshpb; // 电机功率靠档
    QLabel * efficiencyLabel, *flowLabel, *liftLabel, *shaftPowerLabel, * motorPowerLabel, *kdLabel;
    widget_okcancel * buttonWidget;
    QLineEdit * efficiencyLineedt, *flowLineedt, *liftLineedt, *shaftPowerLineedt, * motorPowerLineedt;
    QGridLayout * layout;
    QComboBox * kdComboBox;
    void setKdComboBox(QComboBox * kdBox, const float &var);
};

#endif // CASO4EXTRACTPUMP_WINDOW_H
