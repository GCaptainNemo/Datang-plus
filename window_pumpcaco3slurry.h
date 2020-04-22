#ifndef WINDOW_CACO3SLURRYPUMP_H
#define WINDOW_CACO3SLURRYPUMP_H

#include "window_pumpcaso4discharge_base.h"
#include "utils.h"

class caco3SlurryPumpWindow:public caso4DischargePumpWindow
{
    Q_OBJECT
public:
    explicit caco3SlurryPumpWindow(float & yshpb, float & qshpb, float & hshpb, float & nfshpb,
                                   float & neshpb, float & nkshpb, QWidget *parent = nullptr):
        caso4DischargePumpWindow(yshpb, qshpb, hshpb, nfshpb, neshpb, nkshpb, parent)
    {
        this->setWindowTitle(tr("石灰石浆液泵"));
    }
    virtual void okSLOT();

};





#endif // WINDOW_CACO3SLURRYPUMP_H
