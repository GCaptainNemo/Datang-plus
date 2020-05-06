#ifndef PINF_PAR_H
#define PINF_PAR_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif

#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <iostream>
#include "par_gslresult.h"
#include "par_gasresult.h"
#include "window_parameter_input.h"

class pinfPar
{
public:
    static void setPinfPar(QSqlQuery * query);
    static float VCaCO3 ; //CaCO3含量
    static float VMgCO3 ; //MgCO3含量
    static float Vother ; //其它
    static float yS ; //脱硫效率
    static float zysh ; //增压风机温升计算百分比
    static float Pcaco3 ; //CaCO3 in%
    static float PP1 ; //入口合流三通
    static float PP2 ; //原烟气入口挡板阻力
    static float PP3 ; //原烟气入口挡板阻力至增压风机烟道阻力
    static float PP4 ; //增压风机至GGH原烟气烟道阻力
    static float PP5 ; //GGH原烟气侧阻力
    static float PP6 ; //GGH至吸收塔原烟气烟道阻力
    static float PP7 ; //吸收塔至GGH净烟气烟道阻力
    static float PP8 ; //GGH净烟气侧阻力
    static float PP9 ; //GGH至净烟气出口挡板烟道阻力
    static float PP10 ; //净烟气出口挡板阻力
    static float PP11 ; //出口阻力
    static float PP12 ; //烟囱阻力
    static float PP13 ; //局部总阻力
    static QString ss ; //系统配置（七个数）
    static int Expid ; //设备ID

    static int huanre ; //换热
    static int feishui ; //废水
    static int zhengong ; //真空皮带脱水机
    static int shihui ; //石灰
    static int shuibeng ; //水泵
    static int gongyi ; //工艺水制浆
    static int tianjia ; //添加废水制浆
    static int zengya ; //增压


private:


};

#endif // PINF_PAR_H
