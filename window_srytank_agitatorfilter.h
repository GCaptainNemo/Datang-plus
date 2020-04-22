#ifndef WINDOW_SRYTANK_AGITATORFILTER_H
#define WINDOW_SRYTANK_AGITATORFILTER_H

#include <QWidget>
#include "window_srytank_agitatorcaco3_base.h"


class filterSryTankAndAgitatorWindow : public caco3SryTankAndAgitatorWindow
{
    Q_OBJECT
public:
    explicit filterSryTankAndAgitatorWindow(float & Qsj, int & FGDnum, float & Tsj, float & Dsj, float & Hsj, float & HDsj,  float & Vjsj, float & VTjsj, float & Ysj,
                                              float & Nbsj, float & Nfsj, float & Nesj, float & Nksj, QWidget *parent = nullptr)
        :caco3SryTankAndAgitatorWindow(Qsj, FGDnum, Tsj, Dsj, Hsj, HDsj,  Vjsj, VTjsj, Ysj,
                                           Nbsj, Nfsj, Nesj, Nksj, parent)
    {
        this->setWindowTitle(tr("滤液箱及搅拌器"));
        this->sryTankLabel->setText(tr("滤液箱"));
        this->agitatorLabel->setText(tr("搅拌器"));
    }

signals:

public slots:
    virtual void okSLOT();
};


#endif // WINDOW_SRYTANK_AGITATORFILTER_H
