#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "par_pinf.h"

float pinfPar::VCaCO3 = 0 ; //CaCO3含量
float pinfPar::VMgCO3 = 0; //MgCO3含量
float pinfPar::Vother  = 0; //其它
float pinfPar::yS  = 0; //脱硫效率
float pinfPar::zysh  = 0; //增压风机温升计算百分比
float pinfPar::Pcaco3  = 0; //CaCO3 in%
float pinfPar::PP1  = 0; //入口合流三通
float pinfPar::PP2  = 0; //原烟气入口挡板阻力
float pinfPar::PP3  = 0; //原烟气入口挡板阻力至增压风机烟道阻力
float pinfPar::PP4  = 0; //增压风机至GGH原烟气烟道阻力
float pinfPar::PP5  = 0; //GGH原烟气侧阻力
float pinfPar::PP6  = 0; //GGH至吸收塔原烟气烟道阻力
float pinfPar::PP7  = 0; //吸收塔至GGH净烟气烟道阻力
float pinfPar::PP8  = 0; //GGH净烟气侧阻力
float pinfPar::PP9  = 0; //GGH至净烟气出口挡板烟道阻力
float pinfPar::PP10  = 0; //净烟气出口挡板阻力
float pinfPar::PP11  = 0; //出口阻力
float pinfPar::PP12  = 0; //烟囱阻力
float pinfPar::PP13  = 0; //局部总阻力
QString pinfPar::ss = ""; //系统配置（七个数）
int pinfPar::Expid  = 0; //设备ID

int pinfPar::huanre = 0; //换热
int pinfPar::feishui = 0; //废水
int pinfPar::zhengong = 0; //真空皮带脱水机
int pinfPar::shihui = 0; //石灰
int pinfPar::shuibeng = 0; //水泵
int pinfPar::gongyi = 0; //工艺水制浆
int pinfPar::tianjia = 0 ; //添加废水制浆
int pinfPar::zengya = 0; //增压



void pinfPar::setPinfPar(QSqlQuery * query)
{

//    std::string pinput = query->value(1).toString().toStdString();   // pinput
    QString pinput = query->value(1).toString();
    pinfPar::ss = query->value(2).toString();   // pequip
    pinfPar::Expid = query->value(3).toString().toInt();      // eid

    pinfPar::huanre = pinfPar::ss[0] == '1'? 1 : 0; //换热
    pinfPar::feishui = pinfPar::ss[1] == '1'? 1 : 0; //废水
    pinfPar::zhengong = pinfPar::ss[2] == '1'? 1 : 0; //真空皮带脱水机
    pinfPar::shihui = pinfPar::ss[3] == '1'? 1 : 0; //石灰
    pinfPar::shuibeng = pinfPar::ss[4] == '1'? 1 : 0; //水泵
    pinfPar::gongyi = pinfPar::ss[5] == '1'? 1 : 0; //工艺水制浆
    pinfPar::tianjia = pinfPar::ss[6] == '1'? 1 : 0; //添加废水制浆
    pinfPar::zengya = 1; //增压
    qDebug() << "ss = " << ss;

    QStringList pinput_res = pinput.split("*");
    inputParameterWindow::bz1 = pinput_res[0].toInt();
    inputParameterWindow::bz2 = pinput_res[1].toInt();
    pinfPar::VCaCO3 = pinput_res[25].toFloat();
    pinfPar::VCaCO3 = pinput_res[25].toFloat();
    pinfPar::VMgCO3 =  pinput_res[26].toFloat();
    pinfPar::Vother = pinput_res[27].toFloat();
    gslResultPar::GSL[0][19][14] = pinput_res[28].toFloat();
    pinfPar::yS = pinput_res[29].toFloat();
    gslResultPar::GSL[0][11][14] = pinput_res[30].toFloat();
    gslResultPar::GSL[0][5][16] = pinput_res[31].toFloat();
    pinfPar::zysh = pinput_res[32].toFloat();

    for(int i = 0; i <=22; i++){
         gasResultPar::Gas[0][0][i] = pinput_res[2 + i].toFloat();
    }
    gasResultPar::Gas[0][4][22] = pinput_res[33].toFloat();
    pinfPar::Pcaco3 = pinput_res[34].toFloat();
    pinfPar::PP1 = pinput_res[35].toFloat();
    pinfPar::PP2 = pinput_res[36].toFloat();
    pinfPar::PP3 = pinput_res[37].toFloat();
    pinfPar::PP4 = pinput_res[38].toFloat();
    pinfPar::PP5 = pinput_res[39].toFloat();
    pinfPar::PP6 = pinput_res[40].toFloat();
    pinfPar::PP7 = pinput_res[41].toFloat();
    pinfPar::PP8 = pinput_res[42].toFloat();
    pinfPar::PP9 = pinput_res[43].toFloat();
    pinfPar::PP10 = pinput_res[44].toFloat();
    pinfPar::PP11 = pinput_res[45].toFloat();
    pinfPar::PP12 = pinput_res[46].toFloat();
    pinfPar::PP13 = pinput_res[47].toFloat();
}

