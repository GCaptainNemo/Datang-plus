#ifndef WINDOW_PUMPFILTER_H
#define WINDOW_PUMPFILTER_H

#include <QWidget>
#include "window_pump_caso4discharge_base.h"
#include "utils.h"

class filterPumpWindow: public caso4DischargePumpWindow
{
    Q_OBJECT
public:
    filterPumpWindow(float & yshpb, float & qshpb, float & hshpb, float & nfshpb,
                     float & neshpb, float & nkshpb, QWidget *parent = nullptr):
    caso4DischargePumpWindow(yshpb, qshpb, hshpb, nfshpb, neshpb, nkshpb, parent)
    {
        this->setWindowTitle(tr("滤液泵"));
    }
    virtual void okSLOT();

};

#endif // WINDOW_PUMPFILTER_H
