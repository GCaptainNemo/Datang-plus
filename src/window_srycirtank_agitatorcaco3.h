#ifndef WINDOW_SRYCIRTANK_AGITATOR_CACO3_H
#define WINDOW_SRYCIRTANK_AGITATOR_CACO3_H
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include <QWidget>
#include "window_srytank_agitatorcaco3_base.h"

class caco3SryCirTankAndAgitatorWindow : public caco3SryTankAndAgitatorWindow
{
    Q_OBJECT
public:
    explicit caco3SryCirTankAndAgitatorWindow(float & Qsj, int & FGDnum, float & Tsj, float & Dsj, float & Hsj, float & HDsj,  float & Vjsj, float & VTjsj, float & Ysj,
                                              float & Nbsj, float & Nfsj, float & Nesj, float & Nksj, QWidget *parent = nullptr)
        :caco3SryTankAndAgitatorWindow(Qsj, FGDnum, Tsj, Dsj, Hsj, HDsj,  Vjsj, VTjsj, Ysj,
                                           Nbsj, Nfsj, Nesj, Nksj, parent)
    {
        this->setWindowTitle(tr("石灰石浆液循环箱及搅拌器"));
        this->sryTankLabel->setText(tr("石灰石浆液循环箱"));
        this->agitatorLabel->setText(tr("搅拌器"));
    }

signals:

public slots:
    virtual void okSLOT();
};

#endif // WINDOW_SRYCIRTANK_AGITATOR_CACO3_H
