#ifndef WINDOW_PUMPWATERWINDOW_H
#define WINDOW_PUMPWATERWINDOW_H
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif



#include "window_pump_caso4discharge_base.h"
#include "utils.h"

class waterPumpWindow:public caso4DischargePumpWindow
{
public:
    waterPumpWindow(float & yshpb, float & qshpb, float & hshpb, float & nfshpb,
                           float & neshpb, float & nkshpb, QWidget *parent = nullptr):
        caso4DischargePumpWindow(yshpb, qshpb, hshpb, nfshpb, neshpb, nkshpb, parent)
    {
      this->setWindowTitle(tr("除雾器冲洗水泵"));
    }
    virtual void okSLOT();
};

#endif // WINDOW_PUMPWATERWINDOW_H
