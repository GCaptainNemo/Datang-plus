#include "par_equip.h"


float Coal::Ap = 0;
float Coal::C = 0;
float Coal::coal = 0;
float Coal::Dust = 0;
float Coal::H = 0;
float Coal::N = 0;
float Coal::O = 0;
float Coal::S = 0;
float Coal::Water = 0;

Coal::Coal(const float &ap, const float &coal, const float &water, const float &dust,
               const float &s, const float &h, const float &c, const float &n, const float &o)
{
    Coal::Ap = ap;
    Coal::coal = coal;
    Coal::Water = water;
    Coal::Dust = dust;
    Coal::S = s;
    Coal::H = h;
    Coal::C = c;
    Coal::N = n;
    Coal::O = o;
}





Equip::Equip(QSqlQuery * query):
    eq1(query->value(1).toString().toStdString()), eq2(query->value(2).toString().toStdString()), eq3(query->value(3).toString().toStdString()), eq4(query->value(4).toString().toStdString()),
    eq5(query->value(5).toString().toStdString()), eq6(query->value(6).toString().toStdString()), eq7(query->value(7).toString().toStdString()), eq8(query->value(8).toString().toStdString()),
    eq9(query->value(9).toString().toStdString()), eq10(query->value(10).toString().toStdString()), eq11(query->value(11).toString().toStdString()), eq12(query->value(12).toString().toStdString()),
    eq13(query->value(13).toString().toStdString()), eq14(query->value(14).toString().toStdString()), eq15(query->value(15).toString().toStdString()),
    eq16(query->value(16).toString().toStdString()), eq17(query->value(17).toString().toStdString()), eq18(query->value(18).toString().toStdString()), eq19(query->value(19).toString().toStdString()),
    eq20(query->value(20).toString().toStdString()), eq21(query->value(21).toString().toStdString()), eq22(query->value(22).toString().toStdString()), eq23(query->value(23).toString().toStdString()),
    eq24(query->value(24).toString().toStdString()), eq25(query->value(25).toString().toStdString()), eq26(query->value(26).toString().toStdString()), eq27(query->value(27).toString().toStdString()),
    eq28(query->value(28).toString().toStdString()), eq29(query->value(29).toString().toStdString()), eq30(query->value(30).toString().toStdString()), eq31(query->value(31).toString().toStdString()), eq32(query->value(32).toString().toStdString()){
    absorberSystem * sys0 = new absorberSystem(this->eq1);
    qDebug() << "successful sys0";
    delete sys0;
    flueGasSystem * sys1 = new flueGasSystem(this->eq2, this->eq3);
    qDebug() << "successful sys1";
    delete sys1;

    so2AbsorbSystem * sys2 = new so2AbsorbSystem(this->eq4, this->eq5, this->eq6, this->eq7);
    qDebug() << "successful sys2";
    delete sys2;
    caso4ExtractH2Osystem * sys3 = new caso4ExtractH2Osystem(this->eq8, this->eq9, this->eq10, this->eq11, this->eq12, this->eq13, this->eq14, this->eq15);
    qDebug() << "successful sys3";

    delete sys3;
    slurryPreSystem * sys4 = new slurryPreSystem(this->eq16, this->eq17, this->eq18, this->eq19,
                         this->eq20, this->eq21, this->eq22, this->eq23, this->eq24);
    qDebug() << "successful sys4";

    delete sys4;
    processH2Osystem * sys5 = new processH2Osystem(this->eq25, this->eq26,this->eq27);
    qDebug() << "successful sys5";

    delete sys5;
    emergencySlurrySystem * sys6 = new emergencySlurrySystem(this->eq28, this->eq29,this->eq30);
    qDebug() << "successful sys6";

    delete sys6;

    qDebug() << "successful sys7";

    wasteH2OproSystem * sys7 = new wasteH2OproSystem(this->eq31, this->eq32);
    delete sys7;
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



absorberSystem::absorberSystem(const std::string &s){
    qDebug() << "in absorber succ";
    qDebug() << QString::fromStdString(s);
    std::vector<std::string> res = utils::Split(s, "[*]");
    for(auto i = res.begin(); i != res.end(); i ++ ){
        qDebug() << QString::fromStdString(*i);
    }

//    qDebug() << "res[0] = " << QString("").arg(std::atof(res[0]));
    absorberSystem::FGDnum = std::atoi(res[0].c_str());
    absorberSystem::vin = std::atof(res[1].c_str());
    absorberSystem::vout = std::atof(res[2].c_str());
    absorberSystem::u = std::atof(res[3].c_str());
    absorberSystem::bc = std::atof(res[4].c_str());
    absorberSystem::cd = std::atof(res[5].c_str());
    absorberSystem::D = std::atof(res[6].c_str());
    absorberSystem::pc = std::atoi(res[7].c_str());
    absorberSystem::E = std::atof(res[9].c_str());
    absorberSystem::g = std::atof(res[10].c_str());
    absorberSystem::k = std::atof(res[11].c_str());
    absorberSystem::hx = std::atof(res[12].c_str());
    absorberSystem::NUMjb= std::atoi(res[13].c_str());
    absorberSystem::V= std::atof(res[14].c_str());

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

flueGasSystem::flueGasSystem(const std::string &s2, const std::string &s3)
{
    std::vector<std::string> res = utils::Split(s2, "[*]");

    // 系统1 - 2 增压风机

    flueGasSystem::Yfan= std::atof(res[0].c_str());
    flueGasSystem::Qfan= std::atof(res[1].c_str());
    flueGasSystem::Qfand = std::atof(res[2].c_str());
    flueGasSystem::Pfan = std::atof(res[3].c_str());
    flueGasSystem::Pfand = std::atof(res[4].c_str());
    flueGasSystem::Nffan = std::atof(res[5].c_str());
    flueGasSystem::Ndfan = std::atof(res[6].c_str());
    flueGasSystem::Nefan = std::atof(res[7].c_str());
    flueGasSystem::Nkfan = std::atof(res[8].c_str());

    // 系统1 - 3 换热器
    res = utils::Split(s3, "[*]");
    gasResultPar::Gas[0][1][22] = std::atof(res[0].c_str());
    gasResultPar::Gas[0][4][22] = std::atof(res[1].c_str());
    gasResultPar::Gas[0][1][4] = std::atof(res[2].c_str());

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


so2AbsorbSystem::so2AbsorbSystem(std::string &s4, std::string &s5, std::string &s6, std::string &s7)
{

    // 系统2 - 4 氧化风机

    std::vector<std::string> res = utils::Split(s4, "[*]");
    so2AbsorbSystem::Yyang= std::atof(res[0].c_str());
    so2AbsorbSystem::Qyang = std::atof(res[1].c_str());
    so2AbsorbSystem::QXyang = std::atof(res[2].c_str());
    so2AbsorbSystem::Pyang = std::atof(res[3].c_str());
    so2AbsorbSystem::Nfyang = std::atof(res[4].c_str());
    so2AbsorbSystem::Neyang = std::atof(res[5].c_str());
    so2AbsorbSystem::Nkyang = std::atof(res[6].c_str());

    // 系统2 - 5.浆液循环泵

    res = utils::Split(s5, "[*]");
    so2AbsorbSystem::Yjxb= std::atof(res[0].c_str());
    so2AbsorbSystem::Qjxb = std::atof(res[1].c_str());
    so2AbsorbSystem::xg = std::atoi(res[2].c_str());

    so2AbsorbSystem::Hjxb[0] = std::atof(res[3].c_str());
    so2AbsorbSystem::Nfjxb[0] = std::atof(res[4].c_str());
    so2AbsorbSystem::Nejxb[0] = std::atof(res[5].c_str());
    so2AbsorbSystem::Nkjxb[0] = std::atof(res[6].c_str());

    so2AbsorbSystem::Hjxb[1] = std::atof(res[7].c_str());
    so2AbsorbSystem::Nfjxb[1] = std::atof(res[8].c_str());
    so2AbsorbSystem::Nejxb[1] = std::atof(res[9].c_str());
    so2AbsorbSystem::Nkjxb[1] = std::atof(res[10].c_str());

    so2AbsorbSystem::Hjxb[2] = std::atof(res[11].c_str());
    so2AbsorbSystem::Nfjxb[2] = std::atof(res[12].c_str());
    so2AbsorbSystem::Nejxb[2] = std::atof(res[13].c_str());
    so2AbsorbSystem::Nkjxb[2] = std::atof(res[14].c_str());

    so2AbsorbSystem::Hjxb[3] = std::atof(res[15].c_str());
    so2AbsorbSystem::Nfjxb[3] = std::atof(res[16].c_str());
    so2AbsorbSystem::Nejxb[3] = std::atof(res[17].c_str());
    so2AbsorbSystem::Nkjxb[3] = std::atof(res[18].c_str());

    so2AbsorbSystem::Hjxb[4] = std::atof(res[19].c_str());
    so2AbsorbSystem::Nfjxb[4] = std::atof(res[20].c_str());
    so2AbsorbSystem::Nejxb[4] = std::atof(res[21].c_str());
    so2AbsorbSystem::Nkjxb[4] = std::atof(res[22].c_str());

    so2AbsorbSystem::Hjxb[5] = std::atof(res[23].c_str());
    so2AbsorbSystem::Nfjxb[5] = std::atof(res[24].c_str());
    so2AbsorbSystem::Nejxb[5] = std::atof(res[25].c_str());
    so2AbsorbSystem::Nkjxb[5] = std::atof(res[26].c_str());

    // 系统2 - 6. 吸收塔搅拌器

    res = utils::Split(s6, "[*]");
    so2AbsorbSystem::Nbxsh = std::atof(res[0].c_str());
    so2AbsorbSystem::Nfxsh = std::atof(res[1].c_str());
    so2AbsorbSystem::Nexsh = std::atof(res[2].c_str());
    so2AbsorbSystem::Nkxsh = std::atof(res[3].c_str());
    
    // 系统2 - 7. 石膏排除泵

    res = utils::Split(s7, "[*]");
    so2AbsorbSystem::Yshpb = std::atof(res[0].c_str());
    so2AbsorbSystem::Qshpb = std::atof(res[1].c_str());
    so2AbsorbSystem::Hshpb = std::atof(res[2].c_str());
    so2AbsorbSystem::Nfshpb = std::atof(res[3].c_str());
    so2AbsorbSystem::Neshpb = std::atof(res[4].c_str());
    so2AbsorbSystem::Nkshpb = std::atof(res[5].c_str());
        
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






caso4ExtractH2Osystem::caso4ExtractH2Osystem(std::string & s8, std::string & s9, std::string & s10,
                                             std::string & s11, std::string & s12, std::string & s13,
                                             std::string & s14, std::string & s15)
{    

    //    系统3 - 10 石膏旋流器
    
    std::vector<std::string> res = utils::Split(s8, "[*]");
    caso4ExtractH2Osystem::Qshgx = std::atof(res[0].c_str());
    caso4ExtractH2Osystem::XZshgx = std::atof(res[1].c_str());
    
    //    系统3 - 9 真空皮带脱水机
    
    res = utils::Split(s9, "[*]");
    caso4ExtractH2Osystem::Qzhk = std::atof(res[0].c_str());
    caso4ExtractH2Osystem::Szhk = std::atof(res[1].c_str());
    caso4ExtractH2Osystem::Nezhk = std::atof(res[2].c_str());

    //    系统3 - 10 真空泵

    res = utils::Split(s10, "[*]");
    caso4ExtractH2Osystem::Qzhb = std::atof(res[0].c_str());
    caso4ExtractH2Osystem::Nfzhb = std::atof(res[1].c_str());
    caso4ExtractH2Osystem::Nezhb = std::atof(res[2].c_str());

    //    系统3 - 11 滤布冲洗水箱

    res = utils::Split(s11, "[*]");
    caso4ExtractH2Osystem::Dlb = std::atof(res[0].c_str());
    caso4ExtractH2Osystem::Hlb = std::atof(res[1].c_str());
    caso4ExtractH2Osystem::Vjlb = std::atof(res[2].c_str());

    //    系统3 - 12 滤布冲洗水泵

    res = utils::Split(s12, "[*]");
    caso4ExtractH2Osystem::Qlbb = std::atof(res[0].c_str());
    caso4ExtractH2Osystem::Hlbb = std::atof(res[1].c_str());
    caso4ExtractH2Osystem::Nelbb = std::atof(res[2].c_str());

    //    系统3 - 13 滤液箱

    res = utils::Split(s13, "[*]");
    caso4ExtractH2Osystem::Qlx = std::atof(res[0].c_str());
    caso4ExtractH2Osystem::Tlx = std::atof(res[1].c_str());
    caso4ExtractH2Osystem::Dlx = std::atof(res[2].c_str());//直径
    caso4ExtractH2Osystem::Hlx =std::atof(res[3].c_str()); //高度
    caso4ExtractH2Osystem::HDlx = std::atof(res[4].c_str()); //高径比
    caso4ExtractH2Osystem::VTjlx = std::atof(res[5].c_str()); //计算总容积
    caso4ExtractH2Osystem::Vjlx = std::atof(res[6].c_str()); //计算有效容积
    caso4ExtractH2Osystem::Ylx = std::atof(res[7].c_str()); //有效 总容积

    //    系统3 - 14 滤液箱搅拌器

    res = utils::Split(s14, "[*]");
    caso4ExtractH2Osystem::Nblx = std::atof(res[0].c_str());
    caso4ExtractH2Osystem::Nflx = std::atof(res[1].c_str());
    caso4ExtractH2Osystem::Nelx = std::atof(res[2].c_str());//直径
    caso4ExtractH2Osystem::Nklx =std::atof(res[3].c_str()); //高度


    //    系统3 - 15 滤液泵

    res = utils::Split(s15, "[*]");
    caso4ExtractH2Osystem::Ylyb = std::atof(res[0].c_str());
    caso4ExtractH2Osystem::Qlyb = std::atof(res[1].c_str());
    caso4ExtractH2Osystem::Hlyb = std::atof(res[2].c_str());
    caso4ExtractH2Osystem::Nflyb =std::atof(res[3].c_str());
    caso4ExtractH2Osystem::Nelyb = std::atof(res[4].c_str());
    caso4ExtractH2Osystem::Nklyb = std::atof(res[5].c_str());


}



//    系统4 - 16 石灰石仓

float slurryPreSystem::Qshc = 0; //单台炉耗量
float slurryPreSystem::Tshc = 0; //缓冲时间
float slurryPreSystem::NUMshc = 0; //仓数量
std::string slurryPreSystem::CXshc = "" ; //仓体形式 方 园
std::string slurryPreSystem::ZXshc = ""; //锥斗形式  方  园
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



slurryPreSystem::slurryPreSystem(std::string &s16, std::string &s17, std::string &s18, std::string &s19,
                                 std::string &s20, std::string &s21, std::string &s22, std::string &s23, std::string &s24)
{

    //    系统4 - 16 石灰石仓

    std::vector<std::string> res = utils::Split(s16, "[*]");

    slurryPreSystem::Qshc = std::atof(res[0].c_str()); //单台炉耗量
    slurryPreSystem::Tshc = std::atof(res[1].c_str()); //缓冲时间
    slurryPreSystem::NUMshc = std::atof(res[2].c_str()); //仓数量
    slurryPreSystem::CXshc = res[3]; //仓体形式 方 园
    slurryPreSystem::ZXshc = res[4]; //锥斗形式  方  园
    slurryPreSystem::Dshc = std::atof(res[5].c_str()); //直径
    slurryPreSystem::Ashc = std::atof(res[6].c_str()); //锥体角度
    slurryPreSystem::H1shc = std::atof(res[7].c_str()); //筒段高度
    slurryPreSystem::H2shc = std::atof(res[8].c_str()); //追段高度
    slurryPreSystem::VTjshc = std::atof(res[9].c_str()); //计算总容积
    slurryPreSystem::Vjshc = std::atof(res[10].c_str()); //计算有效容积
    slurryPreSystem::Yshc = std::atof(res[11].c_str()); //有效 总容积


    //    系统4 - 17 磨机

    res = utils::Split(s17, "[*]");
    slurryPreSystem::Qmj = std::atof(res[0].c_str()); //最大出力
    slurryPreSystem::Nfmj = std::atof(res[1].c_str()); //轴功率
    slurryPreSystem::Nemj = std::atof(res[2].c_str()); //电机功率

    //    系统4 - 18 石灰石浆液循环箱

    res = utils::Split(s18, "[*]");
    slurryPreSystem::Qsjx = std::atof(res[0].c_str());  //单台炉耗量
    slurryPreSystem::Tsjx = std::atof(res[1].c_str());  //缓冲时间
    slurryPreSystem::Dsjx = std::atof(res[2].c_str());  //直径
    slurryPreSystem::Hsjx = std::atof(res[3].c_str());  //高度
    slurryPreSystem::HDsjx = std::atof(res[4].c_str());  //高径比
    slurryPreSystem::VTjsjx = std::atof(res[5].c_str());  //计算总容积
    slurryPreSystem::Vjsjx = std::atof(res[6].c_str());  //计算有效容积
    slurryPreSystem::VTsjx = std::atof(res[7].c_str());  //总容积
    slurryPreSystem::Ysjx = std::atof(res[8].c_str());  //有效 / 总容积

    //    系统4 - 19 石灰石浆液循环箱搅拌器

    qDebug() << "in sys 19";

    res = utils::Split(s19, "[*]");
    slurryPreSystem::Nbsjx = std::atof(res[0].c_str());  //比功率
    slurryPreSystem::Nfsjx = std::atof(res[1].c_str());   //轴功率
    slurryPreSystem::Nesjx = std::atof(res[2].c_str());   //电机功率
    slurryPreSystem::Nksjx = std::atof(res[3].c_str());   //电机功率靠档


    //    系统4 - 20 石灰石浆液循环泵

    res = utils::Split(s20, "[*]");

    slurryPreSystem::Yshjxb = std::atof(res[0].c_str()); //效率
    slurryPreSystem::Qshjxb = std::atof(res[1].c_str()); //流量
    slurryPreSystem::Hshjxb = std::atof(res[2].c_str()); //扬程
    slurryPreSystem::Nfshjxb = std::atof(res[3].c_str()); //轴功率
    slurryPreSystem::Neshjxb = std::atof(res[4].c_str());   //电机功率
//    slurryPreSystem::Nkshjxb = std::atof(res[5].c_str()); //电机功率靠档


    //    系统4 - 21 石灰石旋流器

    res = utils::Split(s21, "[*]");
    slurryPreSystem::Qshhx = std::atof(res[0].c_str()); //流量
    slurryPreSystem::XZshhx = std::atof(res[1].c_str()); //旋流子个数

    //    系统4 - 22 石灰石浆液箱

    res = utils::Split(s22, "[*]");

    slurryPreSystem::Qsj = std::atof(res[0].c_str());  //单台炉耗量
    slurryPreSystem::Tsj = std::atof(res[1].c_str());  //缓冲时间
    slurryPreSystem::Dsj = std::atof(res[2].c_str());  //直径
    slurryPreSystem::Hsj = std::atof(res[3].c_str());  //高度
    slurryPreSystem::HDsj = std::atof(res[4].c_str());  //高径比
    slurryPreSystem::VTjsj = std::atof(res[5].c_str());  //计算总容积
    slurryPreSystem::Vjsj = std::atof(res[6].c_str());  //计算有效容积
    slurryPreSystem::Ysj = std::atof(res[7].c_str());  //有效 总容积


    //    系统4 - 23 石灰石浆液箱搅拌器

    res = utils::Split(s23, "[*]");
    slurryPreSystem::Nbsj = std::atof(res[0].c_str()); //比功率
    slurryPreSystem::Nfsj = std::atof(res[1].c_str()); //轴功率
    slurryPreSystem::Nesj = std::atof(res[2].c_str()); //电机功率
    slurryPreSystem::Nksj  = std::atof(res[3].c_str()); //电机功率


    //    系统4 - 24 石灰石浆液泵

    res = utils::Split(s24, "[*]");
    slurryPreSystem::Yshjb = std::atof(res[0].c_str());  //效率
    slurryPreSystem::Qshjb = std::atof(res[1].c_str()); //流量
    slurryPreSystem::Hshjb = std::atof(res[2].c_str()); //扬程
    slurryPreSystem::Nfshjb = std::atof(res[3].c_str()); //轴功率
    slurryPreSystem::Neshjb = std::atof(res[4].c_str()); //电机功率
    slurryPreSystem::Nkshjb = std::atof(res[5].c_str()); //电机功率靠档

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



processH2Osystem::processH2Osystem(std::string &s25, std::string &s26, std::string &s27)
{

    //    系统5 - 25 工艺水箱
    std::vector<std::string> res = utils::Split(s25, "[*]");

    processH2Osystem::Qgy = std::atof(res[0].c_str());   //单台炉耗量
    processH2Osystem::Tgy = std::atof(res[1].c_str()); //缓冲时间
    processH2Osystem::Dgy = std::atof(res[2].c_str()); //直径
    processH2Osystem::Hgy = std::atof(res[3].c_str()); //高度
    processH2Osystem::HDgy = std::atof(res[4].c_str()); //高径比
    processH2Osystem::VTjgy = std::atof(res[5].c_str()); //计算总容积
    processH2Osystem::Vjgy = std::atof(res[6].c_str()); //计算有效容积
    processH2Osystem::VTgy = std::atof(res[7].c_str()); //总容积
    processH2Osystem::Ygy = std::atof(res[8].c_str()); //有效容积 / 总容积

    //    系统5 - 26 工艺水泵
    res = utils::Split(s26, "[*]");
    processH2Osystem::Ygyb = std::atof(res[0].c_str());    //效率
    processH2Osystem::Qgyb = std::atof(res[1].c_str());    //流量
    processH2Osystem::Hgyb = std::atof(res[2].c_str());    //扬程
    processH2Osystem::Nfgyb = std::atof(res[3].c_str());    //轴功率
    processH2Osystem::Negyb = std::atof(res[4].c_str());    //电机功率
    processH2Osystem::Nkgyb = std::atof(res[5].c_str());    //电机功率靠档

    //    系统5 - 27 除雾器冲洗水泵
    res = utils::Split(s27, "[*]");
    processH2Osystem::Yccb = std::atof(res[0].c_str());     //效率
    processH2Osystem::Qccb = std::atof(res[1].c_str());     //流量
    processH2Osystem::Hccb = std::atof(res[2].c_str());     //扬程
    processH2Osystem::Nfccb = std::atof(res[3].c_str());     //轴功率
    processH2Osystem::Neccb = std::atof(res[4].c_str());     //电机功率
    processH2Osystem::Nkccb = std::atof(res[5].c_str());     //电机功率靠档
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


emergencySlurrySystem::emergencySlurrySystem(std::string &s28, std::string &s29,std::string &s30)
{

    //    系统 6 - 28. 事故浆液箱

    std::vector<std::string> res = utils::Split(s28, "[*]");
    emergencySlurrySystem::Dshg = std::atof(res[0].c_str());      //直径
    emergencySlurrySystem::Hshg = std::atof(res[1].c_str());      //高度
    emergencySlurrySystem::HDshg = std::atof(res[2].c_str());     //高径比
    emergencySlurrySystem::VTshg = std::atof(res[3].c_str());     //总容积
    emergencySlurrySystem::Vshg = std::atof(res[4].c_str());     //有效容积
    emergencySlurrySystem::Yshg = std::atof(res[5].c_str());     //有效 总容积


    //    系统 6 - 29. 事故浆液箱搅拌器

    res = utils::Split(s29, "[*]");
    emergencySlurrySystem::Nbshg = std::atof(res[0].c_str()); //比功率
    emergencySlurrySystem::Nfshg = std::atof(res[1].c_str()); //轴功率
    emergencySlurrySystem::Neshg = std::atof(res[2].c_str()); //电机功率
    emergencySlurrySystem::Nkshg = std::atof(res[3].c_str()); //电机功率


    //    系统 6 - 30. 事故浆液箱泵

    res = utils::Split(s30, "[*]");
    emergencySlurrySystem::Yshgb = std::atof(res[0].c_str()); //效率
    emergencySlurrySystem::Qshgb = std::atof(res[1].c_str()); //流量
    emergencySlurrySystem::Hshgb = std::atof(res[2].c_str()); //扬程
    emergencySlurrySystem::Nfshgb = std::atof(res[3].c_str()); //轴功率
    emergencySlurrySystem::Neshgb = std::atof(res[4].c_str()); //电机功率
    emergencySlurrySystem::Nkshgb = std::atof(res[5].c_str()); //电机功率靠档


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



wasteH2OproSystem::wasteH2OproSystem(std::string & s31, std::string & s32)
{

    //    系统7 - 31. 废水泵
    std::vector<std::string> res = utils::Split(s31, "[*]");
    wasteH2OproSystem::Yfshb = std::atof(res[0].c_str());  //效率
    wasteH2OproSystem::Qfshb = std::atof(res[1].c_str());  //流量
    wasteH2OproSystem::Hfshb = std::atof(res[2].c_str());  //扬程
    wasteH2OproSystem::Nffshb = std::atof(res[3].c_str());  //轴功率
    wasteH2OproSystem::Nefshb = std::atof(res[4].c_str());  //电机功率
    wasteH2OproSystem::Nkfshb = std::atof(res[5].c_str());  //电机功率靠档


    //    系统7 - 32. 废水旋流器
    res = utils::Split(s32, "[*]");

    wasteH2OproSystem::Qfx = std::atof(res[0].c_str());   //流量
    wasteH2OproSystem::XZfx = std::atof(res[1].c_str());   //旋流子个数

}


