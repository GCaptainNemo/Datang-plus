#ifndef WINDOW_AIRBLOWERPRESSURE_H
#define WINDOW_AIRBLOWERPRESSURE_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QDialog>

#include <QComboBox>
#include "utils.h"
#include "par_equip.h"
#include "par_gasresult.h"
#include "par_gslresult.h"
#include "widget_okcancel.h"

class pressureAirBlowerWindow : public QDialog
{
    Q_OBJECT
public:
    explicit pressureAirBlowerWindow(QWidget *parent = nullptr);
    static int num ;
    ~pressureAirBlowerWindow();

signals:

public slots:
    void okSLOT();

protected:
    QLabel *efficiencyLabel, *flowLabel, *pressureUpLabel, *shaftPowerLabel,
    *tbFlowLabel, *tbPressureUpLabel, *tbShaftPowerLabel, *motorPowerLabel, *kdLabel;
    QLineEdit * efficiencyLineedit, *flowLineedit, *pressureUpLineedit, *shaftPowerLineedit,
    *tbFlowLineedit,*tbPressureUpLineedit, *tbShaftPowerLineedit, *motorPowerLineedit;

    QComboBox * kdComboBox;
    QGridLayout * gridLayout;
    widget_okcancel * buttonWidget;
};

#endif // WINDOW_AIRBLOWERPRESSURE_H
