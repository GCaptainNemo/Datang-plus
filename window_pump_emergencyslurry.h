#ifndef WINDOW_PUMPEMERGENCYSLURRY_H
#define WINDOW_PUMPEMERGENCYSLURRY_H
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "window_pump_caso4discharge_base.h"
#include "utils.h"

class emergencySlurryPumpWindow:public caso4DischargePumpWindow
{
public:
    emergencySlurryPumpWindow(float & yshpb, float & qshpb, float & hshpb, float & nfshpb,
                              float & neshpb, float & nkshpb, QWidget *parent = nullptr):
   caso4DischargePumpWindow(yshpb, qshpb, hshpb, nfshpb, neshpb, nkshpb, parent)
{
   this->setWindowTitle(tr("事故浆液箱泵"));
}

virtual void okSLOT();
};

#endif // WINDOW_PUMPEMERGENCYSLURRY_H
