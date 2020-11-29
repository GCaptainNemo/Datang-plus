#ifndef WINDOW_PUMPWASTEH2OFEED_H
#define WINDOW_PUMPWASTEH2OFEED_H
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif

#include "window_pump_caso4discharge_base.h"
#include "utils.h"

class wasteh2ofeedPumpWindow:public caso4DischargePumpWindow
{
public:
    wasteh2ofeedPumpWindow(float & yshpb, float & qshpb, float & hshpb, float & nfshpb,
                           float & neshpb, float & nkshpb, QWidget *parent = nullptr):
        caso4DischargePumpWindow(yshpb, qshpb, hshpb, nfshpb, neshpb, nkshpb, parent)
    {
      this->setWindowTitle(tr("废水旋流器给料泵"));
    }
    virtual void okSLOT();

};

#endif // WINDOW_PUMPWASTEH2OFEED_H
