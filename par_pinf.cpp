#include "par_pinf.h"

float pinf::VCaCO3 = 0 ; //CaCO3含量
float pinf::VMgCO3 = 0; //MgCO3含量
float pinf::Vother  = 0; //其它
float pinf::yS  = 0; //脱硫效率
float pinf::zysh  = 0; //增压风机温升计算百分比
float pinf::Pcaco3  = 0; //CaCO3 in%
float pinf::PP1  = 0; //入口合流三通
float pinf::PP2  = 0; //原烟气入口挡板阻力
float pinf::PP3  = 0; //原烟气入口挡板阻力至增压风机烟道阻力
float pinf::PP4  = 0; //增压风机至GGH原烟气烟道阻力
float pinf::PP5  = 0; //GGH原烟气侧阻力
float pinf::PP6  = 0; //GGH至吸收塔原烟气烟道阻力
float pinf::PP7  = 0; //吸收塔至GGH净烟气烟道阻力
float pinf::PP8  = 0; //GGH净烟气侧阻力
float pinf::PP9  = 0; //GGH至净烟气出口挡板烟道阻力
float pinf::PP10  = 0; //净烟气出口挡板阻力
float pinf::PP11  = 0; //出口阻力
float pinf::PP12  = 0; //烟囱阻力
float pinf::PP13  = 0; //局部总阻力
std::string pinf::ss = ""; //系统配置（七个数）
int pinf::Expid  = 0; //设备ID

int pinf::huanre = 0; //换热
int pinf::feishui = 0; //废水
int pinf::zhengong = 0; //真空皮带脱水机
int pinf::shihui = 0; //石灰
int pinf::shuibeng = 0; //水泵
int pinf::gongyi = 0; //工艺水制浆
int pinf::tianjia = 0 ; //添加废水制浆
int pinf::zengya = 0; //增压



void pinf::pinfPar(QSqlQuery * query)
{

    std::string pinput = query->value(1).toString().toStdString();   // pinput
    pinf::ss = query->value(2).toString().toStdString();   // pequip
    pinf::Expid = query->value(3).toString().toInt();      // eid

    pinf::huanre = pinf::ss[0] == '1'? 1 : 0; //换热
    pinf::feishui = pinf::ss[1] == '1'? 1 : 0; //废水
    pinf::zhengong = pinf::ss[2] == '1'? 1 : 0; //真空皮带脱水机
    pinf::shihui = pinf::ss[3] == '1'? 1 : 0; //石灰
    pinf::shuibeng = pinf::ss[4] == '1'? 1 : 0; //水泵
    pinf::gongyi = pinf::ss[5] == '1'? 1 : 0; //工艺水制浆
    pinf::tianjia = pinf::ss[6] == '1'? 1 : 0; //添加废水制浆
    pinf::zengya = 1; //增压
    qDebug() << "ss = " << QString::fromStdString(ss);

    std::vector<std::string> pinput_res = utils::Split(pinput, "[*]");
    inputParameterWindow::bz1 = atoi(pinput_res[0].c_str());
    inputParameterWindow::bz2 = atoi(pinput_res[1].c_str());
//    std::atof(res[0].c_str());

    pinf::VCaCO3 = atof(pinput_res[25].c_str());
    pinf::VMgCO3 =  atof(pinput_res[26].c_str());
    pinf::Vother = atof(pinput_res[27].c_str());
    gslResultPar::GSL[0][19][14] = atof(pinput_res[28].c_str());
    pinf::yS = atof(pinput_res[29].c_str());
    gslResultPar::GSL[0][11][14] = atof(pinput_res[30].c_str());
    gslResultPar::GSL[0][5][16] = atof(pinput_res[31].c_str());
    pinf::zysh = atof(pinput_res[32].c_str());

    for(int i = 0; i <=22; i++){
         gasResultPar::Gas[0][0][i] = atof(pinput_res[2 + i].c_str());
    }
    gasResultPar::Gas[0][4][22] = atof(pinput_res[33].c_str());
    pinf::Pcaco3 = atof(pinput_res[34].c_str());
    pinf::PP1 = atof(pinput_res[35].c_str());
    pinf::PP2 = atof(pinput_res[36].c_str());
    pinf::PP3 = atof(pinput_res[37].c_str());
    pinf::PP4 = atof(pinput_res[38].c_str());
    pinf::PP5 = atof(pinput_res[39].c_str());
    pinf::PP6 = atof(pinput_res[40].c_str());
    pinf::PP7 = atof(pinput_res[41].c_str());
    pinf::PP8 = atof(pinput_res[42].c_str());
    pinf::PP9 = atof(pinput_res[43].c_str());
    pinf::PP10 = atof(pinput_res[44].c_str());
    pinf::PP11 = atof(pinput_res[45].c_str());
    pinf::PP12 = atof(pinput_res[46].c_str());
    pinf::PP13 = atof(pinput_res[47].c_str());


}

