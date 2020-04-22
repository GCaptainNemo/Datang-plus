#ifndef WINDOW_PUMPCACO3SLURRYCURCULANT_H
#define WINDOW_PUMPCACO3SLURRYCURCULANT_H

#include "window_pumpcaso4discharge_base.h"
#include "utils.h"

class caco3SlurryCurculantPumpWindow:public caso4DischargePumpWindow
{
    Q_OBJECT
public:
    caco3SlurryCurculantPumpWindow(float & yshpb, float & qshpb, float & hshpb, float & nfshpb,
                                   float & neshpb, float & nkshpb, QWidget *parent = nullptr):
        caso4DischargePumpWindow(yshpb, qshpb, hshpb, nfshpb, neshpb, nkshpb, parent)
    {
        this->setWindowTitle(tr("石灰石浆液循环泵"));
    };
    virtual void okSLOT();
};

#endif // WINDOW_PUMPCACO3SLURRYCURCULANT_H
