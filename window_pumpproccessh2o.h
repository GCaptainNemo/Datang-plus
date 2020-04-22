#ifndef WINDOW_PUMPPROCCESSH2O_H
#define WINDOW_PUMPPROCCESSH2O_H

#include "window_pumpcaso4discharge_base.h"
#include "utils.h"

class processH2OpumpWindow:public caso4DischargePumpWindow
{
    Q_OBJECT
public:
    processH2OpumpWindow(float & yshpb, float & qshpb, float & hshpb, float & nfshpb,
                          float & neshpb, float & nkshpb, QWidget *parent = nullptr):
     caso4DischargePumpWindow(yshpb, qshpb, hshpb, nfshpb, neshpb, nkshpb, parent)
     {
         this->setWindowTitle(tr("工艺水泵"));
     }
     virtual void okSLOT();

};

#endif // WINDOW_PUMPPROCCESSH2O_H
