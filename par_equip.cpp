#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "par_equip.h"


float Coal::Ap = 0;
float Coal::C = 0;
float Coal::bj = 0;
float Coal::A = 0;
float Coal::H = 0;
float Coal::N = 0;
float Coal::O = 0;
float Coal::S = 0;
float Coal::W = 0;

Coal::Coal(const float &ap, const float &coal, const float &water, const float &dust,
               const float &s, const float &h, const float &c, const float &n, const float &o)
{
    Coal::Ap = ap;
    Coal::bj = coal;
    Coal::W = water;
    Coal::A = dust;
    Coal::S = s;
    Coal::H = h;
    Coal::C = c;
    Coal::N = n;
    Coal::O = o;
}





equipPar::equipPar(QSqlQuery * query):
    eq1(query->value(1).toString()), eq2(query->value(2).toString()), eq3(query->value(3).toString()), eq4(query->value(4).toString()),
    eq5(query->value(5).toString()), eq6(query->value(6).toString()), eq7(query->value(7).toString()), eq8(query->value(8).toString()),
    eq9(query->value(9).toString()), eq10(query->value(10).toString()), eq11(query->value(11).toString()), eq12(query->value(12).toString()),
    eq13(query->value(13).toString()), eq14(query->value(14).toString()), eq15(query->value(15).toString()),
    eq16(query->value(16).toString()), eq17(query->value(17).toString()), eq18(query->value(18).toString()), eq19(query->value(19).toString()),
    eq20(query->value(20).toString()), eq21(query->value(21).toString()), eq22(query->value(22).toString()), eq23(query->value(23).toString()),
    eq24(query->value(24).toString()), eq25(query->value(25).toString()), eq26(query->value(26).toString()), eq27(query->value(27).toString()),
    eq28(query->value(28).toString()), eq29(query->value(29).toString()), eq30(query->value(30).toString()), eq31(query->value(31).toString()), eq32(query->value(32).toString())
{
    absorberSystem::setAbsorberSystemPar(this->eq1);
    qDebug() << "successful sys0";

    flueGasSystem::setFlueGasSystemPar(this->eq2, this->eq3);
    qDebug() << "successful sys1";

    so2AbsorbSystem::setSO2AbsorbSystemPar(this->eq4, this->eq5, this->eq6, this->eq7);
    qDebug() << "successful sys2";

    caso4ExtractH2Osystem::setcaso4ExtractH2OsystemPar(this->eq8, this->eq9, this->eq10, this->eq11, this->eq12, this->eq13, this->eq14, this->eq15);
    qDebug() << "successful sys3";

    slurryPreSystem::setSlurryPreSystemPar(this->eq16, this->eq17, this->eq18, this->eq19,
                         this->eq20, this->eq21, this->eq22, this->eq23, this->eq24);
    qDebug() << "successful sys4";

    processH2Osystem::setProcessH2OsystemPar(this->eq25, this->eq26,this->eq27);
    qDebug() << "successful sys5";


    emergencySlurrySystem::setEmergencySlurrySystemPar(this->eq28, this->eq29,this->eq30);
    qDebug() << "successful sys6";

    wasteH2OproSystem::setWasteH2OproSystemPar(this->eq31, this->eq32);
    qDebug() << "successful sys7";

}


// 系统0 - 1 吸收塔系统



int absorberSystem::FGDnum = 0; //吸收塔数量
double absorberSystem::vin = 0; //入口烟气流速 目标
double absorberSystem::vout = 0; //出口烟气流速  目标
double absorberSystem::u = 0; //烟气流速 目标
double absorberSystem::bc = 0; //入口顶到第一层喷淋层
double absorberSystem::cd = 0; //烟气进口底部之浆液面
double absorberSystem::D = 0; //最上层喷淋层到至第一级除雾器高度差
int absorberSystem::pc = 0; //喷淋层数量
double absorberSystem::E = 0; //喷淋层间距
double absorberSystem::g = 0; //除雾器高度
double absorberSystem::k = 0; //除雾器距顶部烟气出口
double absorberSystem::hx = 0; //烟道宽度 %
int absorberSystem::NUMjb = 0; //个数
double absorberSystem::V = 0 ; //浆池容量

float absorberSystem::B = 0; //氧化空气管距正常液面高度差
float absorberSystem::Bb = 0; //计算最小氧化高度
int absorberSystem::Bx = 0; //氧化风布置方式  喷枪式
int absorberSystem::wx = 0; //外形
double absorberSystem::vin1 = 0; //入口烟气流速 选择



void absorberSystem::setAbsorberSystemPar(const QString &s){
    qDebug() << "in absorber succ";
    QStringList res = s.split("*");
    absorberSystem::FGDnum = res[0].toInt();
    absorberSystem::vin = res[1].toFloat();
    absorberSystem::vout = res[2].toFloat();
    absorberSystem::u = res[3].toFloat();
    absorberSystem::bc = res[4].toFloat();
    absorberSystem::cd = res[5].toFloat();
    absorberSystem::D = res[6].toFloat();
    absorberSystem::pc = res[7].toInt();
    so2AbsorbSystem::xg = res[8].toInt();
    absorberSystem::E = res[9].toFloat();
    absorberSystem::g = res[10].toFloat();
    absorberSystem::k = res[11].toFloat();
    absorberSystem::hx = res[12].toFloat();
    absorberSystem::NUMjb= res[13].toInt();
    absorberSystem::V= res[14].toFloat();
}

// 系统1 - 2 增压风机


float flueGasSystem::Yfan = 0; //效率
float flueGasSystem::Qfan = 0; //BMCR流量
float flueGasSystem::Qfand = 0; //TB流量
float flueGasSystem::Pfan = 0; //BMCR压升
float flueGasSystem::Pfand = 0; //TB压升
float flueGasSystem::Nffan = 0; //BMCR轴功率
float flueGasSystem::Ndfan = 0; //TB轴功率
float flueGasSystem::Nefan = 0; //电机功率
float flueGasSystem::Nkfan = 0 ; //电机功率靠档
float flueGasSystem::Pfans = 0; //设计BMCR压升


// 系统1 - 3 换热器
//

void flueGasSystem::setFlueGasSystemPar(const QString &s2, const QString &s3)
{
    QStringList res = s2.split("*");

    // 系统1 - 2 增压风机

    flueGasSystem::Yfan= res[0].toFloat();
    flueGasSystem::Qfan= res[1].toFloat();
    flueGasSystem::Qfand = res[2].toFloat();
    flueGasSystem::Pfan = res[3].toFloat();
    flueGasSystem::Pfand = res[4].toFloat();
    flueGasSystem::Nffan = res[5].toFloat();
    flueGasSystem::Ndfan = res[6].toFloat();
    flueGasSystem::Nefan = res[7].toFloat();
    flueGasSystem::Nkfan = res[8].toFloat();

    // 系统1 - 3 换热器
    res = s3.split("*");
    gasResultPar::Gas[0][1][22] = res[0].toFloat();
    gasResultPar::Gas[0][4][22] = res[1].toFloat();
    gasResultPar::Gas[0][1][4] = res[2].toFloat();

}









// 系统2 - 4 氧化风机


float so2AbsorbSystem::Yyang = 0; //效率
float so2AbsorbSystem::Qyang = 0; //湿基标态流量
float so2AbsorbSystem::QXyang = 0; //风机选型流量
float so2AbsorbSystem::Pyang = 0; //压升
float so2AbsorbSystem::Nfyang = 0; //轴功率
float so2AbsorbSystem::Neyang = 0; //电机功率
float so2AbsorbSystem::Nkyang = 0; //电机功率靠档



// 系统2 - 5浆液循环泵

float so2AbsorbSystem::Yjxb =0; //效率
float so2AbsorbSystem::Qjxb = 0; //流量
int so2AbsorbSystem::xg = 0; //循环泵数量
float so2AbsorbSystem::Hjxb[6] = {0, 0, 0, 0, 0, 0}; //扬程
float so2AbsorbSystem::Nfjxb[6] = {0, 0, 0, 0, 0, 0}; //轴功率
float so2AbsorbSystem::Nejxb[6] = {0, 0, 0, 0, 0, 0}; //电机功率
float so2AbsorbSystem::Nkjxb[6] = {0, 0, 0, 0, 0, 0}; //电机功率靠档

// 系统2 - 6吸收塔搅拌器

float so2AbsorbSystem::Nbxsh = 0;
float so2AbsorbSystem::Nfxsh = 0;
float so2AbsorbSystem::Nexsh = 0;
float so2AbsorbSystem::Nkxsh = 0;


// 系统2 - 7石膏排除泵

    float so2AbsorbSystem::Yshpb = 0; //效率
    float so2AbsorbSystem::Qshpb = 0; //流量
    float so2AbsorbSystem::Hshpb = 0; //扬程
    float so2AbsorbSystem::Nfshpb = 0; //轴功率
    float so2AbsorbSystem::Neshpb = 0; //电机功率
    float so2AbsorbSystem::Nkshpb = 0; //电机功率靠档


void so2AbsorbSystem::setSO2AbsorbSystemPar(const QString &s4, const QString &s5, const QString &s6, const QString &s7)
{

    // 系统2 - 4 氧化风机

    QStringList res = s4.split("*");
    so2AbsorbSystem::Yyang= res[0].toFloat();
    so2AbsorbSystem::Qyang = res[1].toFloat();
    so2AbsorbSystem::QXyang = res[2].toFloat();
    so2AbsorbSystem::Pyang = res[3].toFloat();
    so2AbsorbSystem::Nfyang = res[4].toFloat();
    so2AbsorbSystem::Neyang = res[5].toFloat();
    so2AbsorbSystem::Nkyang = res[6].toFloat();

    // 系统2 - 5.浆液循环泵

    res = s5.split("*");
    so2AbsorbSystem::Yjxb= res[0].toFloat();
    so2AbsorbSystem::Qjxb = res[1].toFloat();
    so2AbsorbSystem::xg = res[2].toInt();

    so2AbsorbSystem::Hjxb[0] = res[3].toFloat();
    so2AbsorbSystem::Nfjxb[0] = res[4].toFloat();
    so2AbsorbSystem::Nejxb[0] = res[5].toFloat();
    so2AbsorbSystem::Nkjxb[0] = res[6].toFloat();

    so2AbsorbSystem::Hjxb[1] = res[7].toFloat();
    so2AbsorbSystem::Nfjxb[1] = res[8].toFloat();
    so2AbsorbSystem::Nejxb[1] = res[9].toFloat();
    so2AbsorbSystem::Nkjxb[1] = res[10].toFloat();

    so2AbsorbSystem::Hjxb[2] = res[11].toFloat();
    so2AbsorbSystem::Nfjxb[2] = res[12].toFloat();
    so2AbsorbSystem::Nejxb[2] = res[13].toFloat();
    so2AbsorbSystem::Nkjxb[2] = res[14].toFloat();

    so2AbsorbSystem::Hjxb[3] = res[15].toFloat();
    so2AbsorbSystem::Nfjxb[3] = res[16].toFloat();
    so2AbsorbSystem::Nejxb[3] = res[17].toFloat();
    so2AbsorbSystem::Nkjxb[3] = res[18].toFloat();

    so2AbsorbSystem::Hjxb[4] = res[19].toFloat();
    so2AbsorbSystem::Nfjxb[4] = res[20].toFloat();
    so2AbsorbSystem::Nejxb[4] = res[21].toFloat();
    so2AbsorbSystem::Nkjxb[4] = res[22].toFloat();

    so2AbsorbSystem::Hjxb[5] = res[23].toFloat();
    so2AbsorbSystem::Nfjxb[5] = res[24].toFloat();
    so2AbsorbSystem::Nejxb[5] = res[25].toFloat();
    so2AbsorbSystem::Nkjxb[5] = res[26].toFloat();

    // 系统2 - 6. 吸收塔搅拌器

    res = s6.split("*");
    so2AbsorbSystem::Nbxsh = res[0].toFloat();
    so2AbsorbSystem::Nfxsh = res[1].toFloat();
    so2AbsorbSystem::Nexsh = res[2].toFloat();
    so2AbsorbSystem::Nkxsh = res[3].toFloat();

    // 系统2 - 7. 石膏排除泵

    res = s7.split("*");
    so2AbsorbSystem::Yshpb = res[0].toFloat();
    so2AbsorbSystem::Qshpb = res[1].toFloat();
    so2AbsorbSystem::Hshpb = res[2].toFloat();
    so2AbsorbSystem::Nfshpb = res[3].toFloat();
    so2AbsorbSystem::Neshpb = res[4].toFloat();
    so2AbsorbSystem::Nkshpb = res[5].toFloat();

}



//    系统3 - 石膏旋流器


float caso4ExtractH2Osystem::Qshgx = 0;
float caso4ExtractH2Osystem::XZshgx = 0;

//    系统3 - 真空皮带脱水机

float caso4ExtractH2Osystem::Qzhk = 0;
float caso4ExtractH2Osystem::Szhk = 0;
float caso4ExtractH2Osystem::Nezhk = 0;


//    系统3 - 10 真空泵

float caso4ExtractH2Osystem::Qzhb = 0 ; //真空泵出力
float caso4ExtractH2Osystem::Nfzhb = 0; //轴功率
float caso4ExtractH2Osystem::Nezhb = 0; //电机功率

//    系统3 - 11 滤布冲洗水箱

float caso4ExtractH2Osystem::Dlb = 0; //直径
float caso4ExtractH2Osystem::Hlb = 0; //高度
float caso4ExtractH2Osystem::Vjlb = 0; //计算有效容积


//    系统3 - 12 滤布冲洗水泵


float caso4ExtractH2Osystem::Qlbb = 0; //流量
float caso4ExtractH2Osystem::Hlbb = 0; //扬程
float caso4ExtractH2Osystem::Nelbb = 0; //功率

//    系统3 - 13 滤液箱

float caso4ExtractH2Osystem::Qlx = 0; //单台炉耗量
float caso4ExtractH2Osystem::Tlx = 0; //缓冲时间
float caso4ExtractH2Osystem::Dlx = 0; //直径
float caso4ExtractH2Osystem::Hlx = 0; //高度
float caso4ExtractH2Osystem::HDlx = 0; //高径比
float caso4ExtractH2Osystem::VTjlx = 0; //计算总容积
float caso4ExtractH2Osystem::Vjlx = 0; //计算有效容积
float caso4ExtractH2Osystem::Ylx = 0; //有效 总容积


//    系统3 - 14 滤液箱搅拌器

float caso4ExtractH2Osystem::Nblx = 0; // 比功率
float caso4ExtractH2Osystem::Nflx = 0; // 轴功率
float caso4ExtractH2Osystem::Nelx = 0; // 电机功率
float caso4ExtractH2Osystem::Nklx = 0; // 电机功率靠档



//    系统3 - 15 滤液泵

float caso4ExtractH2Osystem::Ylyb= 0;
float caso4ExtractH2Osystem::Qlyb = 0;
float caso4ExtractH2Osystem::Hlyb = 0;
float caso4ExtractH2Osystem::Nflyb = 0;
float caso4ExtractH2Osystem::Nelyb = 0;
float caso4ExtractH2Osystem::Nklyb = 0;






void caso4ExtractH2Osystem::setcaso4ExtractH2OsystemPar(const QString & s8, const QString & s9, const QString & s10,
                                             const QString & s11, const QString & s12, const QString & s13,
                                             const QString & s14, const QString & s15)
{

    //    系统3 - 10 石膏旋流器


    QStringList res = s8.split("*");
    caso4ExtractH2Osystem::Qshgx = res[0].toFloat();
    caso4ExtractH2Osystem::XZshgx = res[1].toFloat();

    //    系统3 - 9 真空皮带脱水机

    res = s9.split("*");
    caso4ExtractH2Osystem::Qzhk = res[0].toFloat();
    caso4ExtractH2Osystem::Szhk = res[1].toFloat();
    caso4ExtractH2Osystem::Nezhk = res[2].toFloat();

    //    系统3 - 10 真空泵

    res = s10.split("*");
    caso4ExtractH2Osystem::Qzhb = res[0].toFloat();
    caso4ExtractH2Osystem::Nfzhb = res[1].toFloat();
    caso4ExtractH2Osystem::Nezhb = res[2].toFloat();

    //    系统3 - 11 滤布冲洗水箱

    res = s11.split("*");
    caso4ExtractH2Osystem::Dlb = res[0].toFloat();
    caso4ExtractH2Osystem::Hlb = res[1].toFloat();
    caso4ExtractH2Osystem::Vjlb = res[2].toFloat();

    //    系统3 - 12 滤布冲洗水泵

    res = s12.split("*");
    caso4ExtractH2Osystem::Qlbb = res[0].toFloat();
    caso4ExtractH2Osystem::Hlbb = res[1].toFloat();
    caso4ExtractH2Osystem::Nelbb = res[2].toFloat();

    //    系统3 - 13 滤液箱

    res = s13.split("*");
    caso4ExtractH2Osystem::Qlx = res[0].toFloat();
    caso4ExtractH2Osystem::Tlx = res[1].toFloat();
    caso4ExtractH2Osystem::Dlx = res[2].toFloat();//直径
    caso4ExtractH2Osystem::Hlx =res[3].toFloat(); //高度
    caso4ExtractH2Osystem::HDlx = res[4].toFloat(); //高径比
    caso4ExtractH2Osystem::VTjlx = res[5].toFloat(); //计算总容积
    caso4ExtractH2Osystem::Vjlx = res[6].toFloat(); //计算有效容积
    caso4ExtractH2Osystem::Ylx = res[7].toFloat(); //有效 总容积

    //    系统3 - 14 滤液箱搅拌器

    res = s14.split("*");
    caso4ExtractH2Osystem::Nblx = res[0].toFloat();
    caso4ExtractH2Osystem::Nflx = res[1].toFloat();
    caso4ExtractH2Osystem::Nelx = res[2].toFloat();//直径
    caso4ExtractH2Osystem::Nklx =res[3].toFloat(); //高度


    //    系统3 - 15 滤液泵

    res = s15.split("*");
    caso4ExtractH2Osystem::Ylyb = res[0].toFloat();
    caso4ExtractH2Osystem::Qlyb = res[1].toFloat();
    caso4ExtractH2Osystem::Hlyb = res[2].toFloat();
    caso4ExtractH2Osystem::Nflyb =res[3].toFloat();
    caso4ExtractH2Osystem::Nelyb = res[4].toFloat();
    caso4ExtractH2Osystem::Nklyb = res[5].toFloat();


}



//    系统4 - 16 石灰石仓

float slurryPreSystem::Qshc = 0; //单台炉耗量
float slurryPreSystem::Tshc = 0; //缓冲时间
float slurryPreSystem::NUMshc = 0; //仓数量
QString slurryPreSystem::CXshc = "" ; //仓体形式 方 园
QString slurryPreSystem::ZXshc = ""; //锥斗形式  方  园
float slurryPreSystem::Dshc = 0; //直径
float slurryPreSystem::Ashc = 0; //锥体角度
float slurryPreSystem::H1shc = 0; //筒段高度
float slurryPreSystem::H2shc = 0; //追段高度
float slurryPreSystem::VTjshc = 0; //计算总容积
float slurryPreSystem::Vjshc = 0; //计算有效容积
float slurryPreSystem::Yshc = 0; //有效 总容积

//    系统4 - 17 磨机

float slurryPreSystem::Qmj = 0; //最大出力
float slurryPreSystem::Nfmj = 0; //轴功率
float slurryPreSystem::Nemj = 0; //电机功率


//    系统4 - 18 石灰石浆液循环箱

float slurryPreSystem::Qsjx = 0; //单台炉耗量
float slurryPreSystem::Tsjx = 0; //缓冲时间
float slurryPreSystem::Dsjx = 0; //直径
float slurryPreSystem::Hsjx = 0; //高度
float slurryPreSystem::HDsjx = 0; //高径比
float slurryPreSystem::VTjsjx = 0; //计算总容积
float slurryPreSystem::Vjsjx = 0; //计算有效容积
float slurryPreSystem::VTsjx = 0; //总容积
float slurryPreSystem::Ysjx = 0; //有效 总容积

//    系统4 - 19 石灰石浆液循环箱搅拌器

float slurryPreSystem::Nbsjx = 0; //比功率
float slurryPreSystem::Nfsjx = 0; //轴功率
float slurryPreSystem::Nesjx = 0; //电机功率
float slurryPreSystem::Nksjx = 0; //电机功率靠档


//    系统4 - 20 石灰石浆液循环泵

float slurryPreSystem::Yshjxb = 0; //效率
float slurryPreSystem::Qshjxb = 0; //流量
float slurryPreSystem::Hshjxb = 0; //扬程
float slurryPreSystem::Nfshjxb = 0; //轴功率
float slurryPreSystem::Neshjxb = 0; //电机功率
float slurryPreSystem::Nkshjxb = 0; //电机功率靠档


//    系统4 - 21 石灰石旋流器

float slurryPreSystem::Qshhx = 0; //流量
float slurryPreSystem::XZshhx = 0; //旋流子个数


//    系统4 - 22 石灰石浆液箱


float slurryPreSystem::Qsj = 0; //单台炉耗量
float slurryPreSystem::Tsj = 0; //缓冲时间
float slurryPreSystem::Dsj = 0; //直径
float slurryPreSystem::Hsj = 0; //高度
float slurryPreSystem::HDsj = 0; //高径比
float slurryPreSystem::VTjsj = 0; //计算总容积
float slurryPreSystem::Vjsj = 0; //计算有效容积
float slurryPreSystem::Ysj = 0; //有效 总容积


//    系统4 - 23 石灰石浆液箱搅拌器

float slurryPreSystem::Nbsj = 0; //比功率
float slurryPreSystem::Nfsj = 0; //轴功率
float slurryPreSystem::Nesj = 0; //电机功率
float slurryPreSystem::Nksj  = 0; //电机功率
float slurryPreSystem::Vsj = 0; //有效容积
float slurryPreSystem::VTsj = 0; //总容积


//    系统4 - 24 石灰石浆液泵

float slurryPreSystem::Yshjb = 0; //效率
float slurryPreSystem::Qshjb = 0; //流量
float slurryPreSystem::Hshjb = 0; //扬程
float slurryPreSystem::Nfshjb = 0; //轴功率
float slurryPreSystem::Neshjb = 0; //电机功率
float slurryPreSystem::Nkshjb = 0; //电机功率靠档



void slurryPreSystem::setSlurryPreSystemPar(const QString &s16, const QString &s17, const QString &s18, const QString &s19,
                                 const QString &s20, const QString &s21, const QString &s22, const QString &s23, const QString &s24)
{

    //    系统4 - 16 石灰石仓

    QStringList res = s16.split("*");

    slurryPreSystem::Qshc = res[0].toFloat(); //单台炉耗量
    slurryPreSystem::Tshc = res[1].toFloat(); //缓冲时间
    slurryPreSystem::NUMshc = res[2].toFloat(); //仓数量
    slurryPreSystem::CXshc = res[3]; //仓体形式 方 园
    slurryPreSystem::ZXshc = res[4]; //锥斗形式  方  园
    slurryPreSystem::Dshc = res[5].toFloat(); //直径
    slurryPreSystem::Ashc = res[6].toFloat(); //锥体角度
    slurryPreSystem::H1shc = res[7].toFloat(); //筒段高度
    slurryPreSystem::H2shc = res[8].toFloat(); //追段高度
    slurryPreSystem::VTjshc = res[9].toFloat(); //计算总容积
    slurryPreSystem::Vjshc = res[10].toFloat(); //计算有效容积
    slurryPreSystem::Yshc = res[11].toFloat(); //有效 总容积


    //    系统4 - 17 磨机

    res = s17.split("*");
    slurryPreSystem::Qmj = res[0].toFloat(); //最大出力
    slurryPreSystem::Nfmj = res[1].toFloat(); //轴功率
    slurryPreSystem::Nemj = res[2].toFloat(); //电机功率

    //    系统4 - 18 石灰石浆液循环箱

    res = s18.split("*");
    slurryPreSystem::Qsjx = res[0].toFloat();  //单台炉耗量
    slurryPreSystem::Tsjx = res[1].toFloat();  //缓冲时间
    slurryPreSystem::Dsjx = res[2].toFloat();  //直径
    slurryPreSystem::Hsjx = res[3].toFloat();  //高度
    slurryPreSystem::HDsjx = res[4].toFloat();  //高径比
    slurryPreSystem::VTjsjx = res[5].toFloat();  //计算总容积
    slurryPreSystem::Vjsjx = res[6].toFloat();  //计算有效容积
    slurryPreSystem::VTsjx = res[7].toFloat();  //总容积
    slurryPreSystem::Ysjx = res[8].toFloat();  //有效 / 总容积

    //    系统4 - 19 石灰石浆液循环箱搅拌器

    qDebug() << "in sys 19";

    res = s19.split("*");
    slurryPreSystem::Nbsjx = res[0].toFloat();  //比功率
    slurryPreSystem::Nfsjx = res[1].toFloat();   //轴功率
    slurryPreSystem::Nesjx = res[2].toFloat();   //电机功率
    slurryPreSystem::Nksjx = res[3].toFloat();   //电机功率靠档


    //    系统4 - 20 石灰石浆液循环泵

    res = s20.split("*");

    slurryPreSystem::Yshjxb = res[0].toFloat(); //效率
    slurryPreSystem::Qshjxb = res[1].toFloat(); //流量
    slurryPreSystem::Hshjxb = res[2].toFloat(); //扬程
    slurryPreSystem::Nfshjxb = res[3].toFloat(); //轴功率
    slurryPreSystem::Neshjxb = res[4].toFloat();   //电机功率
//    slurryPreSystem::Nkshjxb = std::atof(res[5].c_str()); //电机功率靠档


    //    系统4 - 21 石灰石旋流器

    res = s21.split("*");
    slurryPreSystem::Qshhx = res[0].toFloat(); //流量
    slurryPreSystem::XZshhx = res[1].toFloat(); //旋流子个数

    //    系统4 - 22 石灰石浆液箱

    res = s22.split("*");

    slurryPreSystem::Qsj = res[0].toFloat();  //单台炉耗量
    slurryPreSystem::Tsj = res[1].toFloat();  //缓冲时间
    slurryPreSystem::Dsj = res[2].toFloat();  //直径
    slurryPreSystem::Hsj = res[3].toFloat();  //高度
    slurryPreSystem::HDsj = res[4].toFloat();  //高径比
    slurryPreSystem::VTjsj = res[5].toFloat();  //计算总容积
    slurryPreSystem::Vjsj = res[6].toFloat();  //计算有效容积
    slurryPreSystem::Ysj = res[7].toFloat();  //有效 总容积


    //    系统4 - 23 石灰石浆液箱搅拌器

    res = s23.split("*");
    slurryPreSystem::Nbsj = res[0].toFloat(); //比功率
    slurryPreSystem::Nfsj = res[1].toFloat(); //轴功率
    slurryPreSystem::Nesj = res[2].toFloat(); //电机功率
    slurryPreSystem::Nksj  = res[3].toFloat(); //电机功率


    //    系统4 - 24 石灰石浆液泵

    res = s24.split("*");
    slurryPreSystem::Yshjb = res[0].toFloat();  //效率
    slurryPreSystem::Qshjb = res[1].toFloat(); //流量
    slurryPreSystem::Hshjb = res[2].toFloat(); //扬程
    slurryPreSystem::Nfshjb = res[3].toFloat(); //轴功率
    slurryPreSystem::Neshjb = res[4].toFloat(); //电机功率
    slurryPreSystem::Nkshjb = res[5].toFloat(); //电机功率靠档

}



//  系统5
//    系统5 - 25 工艺水箱

float processH2Osystem::Qgy = 0; //单台炉耗量
float processH2Osystem::Tgy = 0; //缓冲时间
float processH2Osystem::Dgy = 0; //直径
float processH2Osystem::Hgy = 0; //高度
float processH2Osystem::HDgy = 0; //高径比
float processH2Osystem::VTjgy = 0 ; //计算总容积
float processH2Osystem::Vjgy = 0; //计算有效容积
float processH2Osystem::VTgy = 0; //总容积
float processH2Osystem::Ygy = 0; //有效/总容积

//    系统5 - 26 工艺水泵

float processH2Osystem::Ygyb = 0; //效率
float processH2Osystem::Qgyb = 0; //流量
float processH2Osystem::Hgyb = 0; //扬程
float processH2Osystem::Nfgyb = 0; //轴功率
float processH2Osystem::Negyb = 0; //电机功率
float processH2Osystem::Nkgyb = 0; //电机功率靠档


//    系统5 - 27  除雾器冲洗水泵

float processH2Osystem::Yccb = 0; //效率
float processH2Osystem::Qccb = 0; //流量
float processH2Osystem::Hccb = 0; //扬程
float processH2Osystem::Nfccb = 0; //轴功率
float processH2Osystem::Neccb = 0; //电机功率
float processH2Osystem::Nkccb = 0; //电机功率靠档



void processH2Osystem::setProcessH2OsystemPar(const QString &s25, const QString &s26, const QString &s27)
{

    //    系统5 - 25 工艺水箱
    QStringList res = s25.split("*");

    processH2Osystem::Qgy = res[0].toFloat();   //单台炉耗量
    processH2Osystem::Tgy = res[1].toFloat(); //缓冲时间
    processH2Osystem::Dgy = res[2].toFloat(); //直径
    processH2Osystem::Hgy = res[3].toFloat(); //高度
    processH2Osystem::HDgy = res[4].toFloat(); //高径比
    processH2Osystem::VTjgy = res[5].toFloat(); //计算总容积
    processH2Osystem::Vjgy = res[6].toFloat(); //计算有效容积
    processH2Osystem::VTgy = res[7].toFloat(); //总容积
    processH2Osystem::Ygy = res[8].toFloat(); //有效容积 / 总容积

    //    系统5 - 26 工艺水泵
    res = s26.split("*");
    processH2Osystem::Ygyb = res[0].toFloat();    //效率
    processH2Osystem::Qgyb = res[1].toFloat();    //流量
    processH2Osystem::Hgyb = res[2].toFloat();    //扬程
    processH2Osystem::Nfgyb = res[3].toFloat();    //轴功率
    processH2Osystem::Negyb = res[4].toFloat();    //电机功率
    processH2Osystem::Nkgyb = res[5].toFloat();    //电机功率靠档

    //    系统5 - 27 除雾器冲洗水泵
    res = s27.split("*");
    processH2Osystem::Yccb = res[0].toFloat();     //效率
    processH2Osystem::Qccb = res[1].toFloat();     //流量
    processH2Osystem::Hccb = res[2].toFloat();     //扬程
    processH2Osystem::Nfccb = res[3].toFloat();     //轴功率
    processH2Osystem::Neccb = res[4].toFloat();     //电机功率
    processH2Osystem::Nkccb = res[5].toFloat();     //电机功率靠档
}



//    系统 6 - 28. 事故浆液箱

float emergencySlurrySystem::Dshg = 0; //直径
float emergencySlurrySystem::Hshg = 0; //高度
float emergencySlurrySystem::HDshg = 0; //高径比
float emergencySlurrySystem::VTshg = 0; //总容积
float emergencySlurrySystem::Vshg = 0; //有效容积
float emergencySlurrySystem::Yshg = 0; //有效 总容积


//    系统 6 - 29. 事故浆液搅拌器

float emergencySlurrySystem::Nbshg = 0; //比功率
float emergencySlurrySystem::Nfshg = 0; //轴功率
float emergencySlurrySystem::Neshg = 0; //电机功率
float emergencySlurrySystem::Nkshg = 0; //电机功率
int emergencySlurrySystem::BGL(const float & JN)
{
    if(JN > 0.3)
        return 80;
    else if(JN > 0.2 && JN <= 0.3)
        return 50;
    else if(JN > 0 && JN <= 0.2)
        return 25;
    return -1;
}



//    系统 6 - 29. 事故浆液箱泵

float emergencySlurrySystem::Yshgb = 0; //效率
float emergencySlurrySystem::Qshgb = 0; //流量
float emergencySlurrySystem::Hshgb = 0; //扬程
float emergencySlurrySystem::Nfshgb = 0; //轴功率
float emergencySlurrySystem::Neshgb = 0; //电机功率
float emergencySlurrySystem::Nkshgb = 0; //电机功率靠档
float emergencySlurrySystem::Vjshg = 0; //计算有效容积
float emergencySlurrySystem::VTjshg = 0; //计算总容积


void emergencySlurrySystem::setEmergencySlurrySystemPar(const QString &s28, const QString &s29, const QString &s30)
{

    //    系统 6 - 28. 事故浆液箱

    QStringList res = s28.split("*");
    emergencySlurrySystem::Dshg = res[0].toFloat();      //直径
    emergencySlurrySystem::Hshg = res[1].toFloat();      //高度
    emergencySlurrySystem::HDshg = res[2].toFloat();     //高径比
    emergencySlurrySystem::VTshg = res[3].toFloat();     //总容积
    emergencySlurrySystem::Vshg = res[4].toFloat();     //有效容积
    emergencySlurrySystem::Yshg = res[5].toFloat();     //有效 总容积


    //    系统 6 - 29. 事故浆液箱搅拌器

    res = s29.split("*");
    emergencySlurrySystem::Nbshg = res[0].toFloat(); //比功率
    emergencySlurrySystem::Nfshg = res[1].toFloat(); //轴功率
    emergencySlurrySystem::Neshg = res[2].toFloat(); //电机功率
    emergencySlurrySystem::Nkshg = res[3].toFloat(); //电机功率


    //    系统 6 - 30. 事故浆液箱泵

    res = s30.split("*");
    emergencySlurrySystem::Yshgb = res[0].toFloat(); //效率
    emergencySlurrySystem::Qshgb = res[1].toFloat(); //流量
    emergencySlurrySystem::Hshgb = res[2].toFloat(); //扬程
    emergencySlurrySystem::Nfshgb = res[3].toFloat(); //轴功率
    emergencySlurrySystem::Neshgb = res[4].toFloat(); //电机功率
    emergencySlurrySystem::Nkshgb = res[5].toFloat(); //电机功率靠档

}



//    系统7 - 31. 废水泵

float wasteH2OproSystem::Yfshb = 0; //效率
float wasteH2OproSystem::Qfshb = 0; //流量
float wasteH2OproSystem::Hfshb = 0; //扬程
float wasteH2OproSystem::Nffshb = 0; //轴功率
float wasteH2OproSystem::Nefshb = 0; //电机功率
float wasteH2OproSystem::Nkfshb = 0; //电机功率靠档


//    系统7 - 32. 废水旋流器

float wasteH2OproSystem::Qfx = 0; //流量
float wasteH2OproSystem::XZfx = 0; //旋流子个数



void wasteH2OproSystem::setWasteH2OproSystemPar(const QString & s31, const QString & s32)
{

    //    系统7 - 31. 废水泵
    QStringList res = s31.split("*");
    wasteH2OproSystem::Yfshb = res[0].toFloat();  //效率
    wasteH2OproSystem::Qfshb = res[1].toFloat();  //流量
    wasteH2OproSystem::Hfshb = res[2].toFloat();  //扬程
    wasteH2OproSystem::Nffshb = res[3].toFloat();  //轴功率
    wasteH2OproSystem::Nefshb = res[4].toFloat();  //电机功率
    wasteH2OproSystem::Nkfshb = res[5].toFloat();  //电机功率靠档


    //    系统7 - 32. 废水旋流器
    res = s32.split("*");

    wasteH2OproSystem::Qfx = res[0].toFloat();   //流量
    wasteH2OproSystem::XZfx = res[1].toFloat();   //旋流子个数

}


