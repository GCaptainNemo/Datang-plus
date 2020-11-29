#ifndef GLOBAL_PAR_H
#define GLOBAL_PAR_H
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QSqlQuery>
#include "utils.h"
#include "par_gasresult.h"


class equipPar
{
public:
    equipPar(QSqlQuery * query);


private:
    QString eq1, eq2, eq3, eq4, eq5, eq6, eq7, eq8, eq9, eq10, eq11, eq12, eq13, eq14, eq15;
    QString eq16, eq17, eq18, eq19, eq20, eq21, eq22, eq23, eq24, eq25, eq26, eq27, eq28, eq29, eq30;
    QString eq31, eq32;

};


//系统0.吸收塔系统
class absorberSystem
{
public:

    static int FGDnum ; //吸收塔数量
    static double vin ; //入口烟气流速 目标
    static double vout ; //出口烟气流速  目标
    static double u ; //烟气流速 目标
    static double bc ; //入口顶到第一层喷淋层
    static double cd ; //烟气进口底部之浆液面
    static double D ; //最上层喷淋层到至第一级除雾器高度差
    static int pc ; //喷淋层数量
    static double E ; //喷淋层间距
    static double g ; //除雾器高度
    static double k ; //除雾器距顶部烟气出口
    static double hx ; //烟道宽度 %
    static int NUMjb ; //个数
    static double V ; //浆池容量
    static void setAbsorberSystemPar(const QString &s);

    static float B ; //氧化空气管距正常液面高度差
    static float Bb ; //计算最小氧化高度
    static int Bx ; //氧化风布置方式  喷枪式
    static int wx ; //外形
    static double vin1 ; //入口烟气流速 选择

};




// 系统1.烟气系统
//unfinished
class flueGasSystem{
public:
//    2. 增压风机选型
    static float Yfan ; //效率
    static float Qfan ; //BMCR流量
    static float Qfand ; //TB流量
    static float Pfan ; //BMCR压升
    static float Pfand ; //TB压升
    static float Nffan ; //BMCR轴功率
    static float Ndfan ; //TB轴功率
    static float Nefan ; //电机功率
    static float Nkfan ; //电机功率靠档
    static float Pfans ; //设计BMCR压升

//  3. 换热器


    static void setFlueGasSystemPar(const QString &s1, const QString &s2);

};



//系统2.SO2吸收系统
class so2AbsorbSystem
{
public:
//  4. 氧化风机
    static float Yyang ; //效率
    static float Qyang ; //湿基标态流量
    static float QXyang ; //风机选型流量
    static float Pyang ; //压升
    static float Nfyang ; //轴功率
    static float Neyang ; //电机功率
    static float Nkyang ; //电机功率靠档




//    5. 浆液循环泵

    static float Yjxb ; //效率
    static float Qjxb ; //流量
    static int xg ; //循环泵数量
    static float Hjxb[6]; //扬程
    static float Nfjxb[6]; //轴功率
    static float Nejxb[6]; //电机功率
    static float Nkjxb[6]; //电机功率靠档

//    6. 吸收塔搅拌器

    static float Nbxsh ; //比功率
    static float Nfxsh ; //轴功率
    static float Nexsh ; //电机功率
    static float Nkxsh ; //电机功率靠档

//    7. 石膏排除泵

    static float Yshpb ; //效率
    static float Qshpb ; //流量
    static float Hshpb ; //扬程
    static float Nfshpb ; //轴功率
    static float Neshpb ; //电机功率
    static float Nkshpb ; //电机功率靠档



    static void setSO2AbsorbSystemPar(const QString &s4, const QString &s5, const QString &s6, const QString &s7);



};

//系统3.石膏脱水系统
class caso4ExtractH2Osystem
{

public:

//    8.石膏旋流器

    static float Qshgx ; //流量
    static float XZshgx ; //旋流子个数

//    9.真空皮带脱水机

    static float Qzhk ; //最大出力
    static float Szhk ; //过滤面积
    static float Nezhk ; //主驱动电机功率

//    10.真空泵

    static float Qzhb ; //真空泵出力
    static float Nfzhb ; //轴功率
    static float Nezhb ; //电机功率

 //    11. 滤布冲洗水箱

    static float Dlb ; //直径
    static float Hlb ; //高度
    static float Vjlb ; //计算有效容积

 //    12. 滤布冲洗水泵

    static float Qlbb ; //流量
    static float Hlbb ; //扬程
    static float Nelbb ; //功率

//    13. 滤液箱

    static float Qlx ; //单台炉耗量
    static float Tlx ; //缓冲时间
    static float Dlx ; //直径
    static float Hlx ; //高度
    static float HDlx ; //高径比
    static float VTjlx ; //计算总容积
    static float Vjlx ; //计算有效容积
    static float Ylx ; //有效 总容积


//   14. 滤液箱搅拌器

    static float Nblx ; //比功率
    static float Nflx ; //轴功率
    static float Nelx ; //电机功率
    static float Nklx ; //电机功率

//   15. 滤液泵

    static float Ylyb ; //效率
    static float Qlyb ; //流量
    static float Hlyb ; //扬程
    static float Nflyb ; //轴功率
    static float Nelyb ; //电机功率
    static float Nklyb ; //电机功率靠档


    static void setcaso4ExtractH2OsystemPar(const QString &s8, const QString &s9, const QString &s10, const QString &s11,
                          const QString & s12, const QString & s13, const QString & s14, const QString & s15);

};


//系统4.浆液制备系统
class  slurryPreSystem
{
public:

    //   16. 石灰石仓

    static float Qshc ; //单台炉耗量
    static float Tshc ; //缓冲时间
    static float NUMshc ; //仓数量
    static QString CXshc ; //仓体形式 方 园
    static QString ZXshc ; //锥斗形式  方  园
    static float Dshc ; //直径
    static float Ashc ; //锥体角度
    static float H1shc ; //筒段高度
    static float H2shc ; //追段高度
    static float VTjshc ; //计算总容积
    static float Vjshc ; //计算有效容积
    static float Yshc ; //有效 总容积



    //   17. 磨机

    static float Qmj ; //最大出力
    static float Nfmj ; //轴功率
    static float Nemj ; //电机功率

    //    18. 石灰石浆液循环箱

    static float Qsjx ; //单台炉耗量
    static float Tsjx ; //缓冲时间
    static float Dsjx ; //直径
    static float Hsjx ; //高度
    static float HDsjx ; //高径比
    static float VTjsjx ; //计算总容积
    static float Vjsjx ; //计算有效容积
    static float VTsjx ; //总容积
    static float Ysjx ; //有效 总容积


    //    19. 石灰石浆液循环箱搅拌器

    static float Nbsjx ; //比功率
    static float Nfsjx ; //轴功率
    static float Nksjx ; //电机功率靠档
    static float Nesjx ; //电机功率


    //    20. 石灰石浆液循环泵

    static float Yshjxb ; //效率
    static float Qshjxb ; //流量
    static float Hshjxb ; //扬程
    static float Nfshjxb ; //轴功率
    static float Nkshjxb ; //电机功率靠档
    static float Neshjxb ; //功率


    //    21. 石灰石旋流器

    static float Qshhx ; //流量
    static float XZshhx ; //旋流子个数

    //    22. 石灰石浆液箱


    static float Qsj ; //单台炉耗量
    static float Tsj ; //缓冲时间
    static float Dsj ; //直径
    static float Hsj ; //高度
    static float HDsj ; //高径比
    static float VTjsj ; //计算总容积
    static float Vjsj ; //计算有效容积
    static float Ysj ; //有效 总容积


    //    23. 石灰石浆液箱搅拌器

    static float Nbsj ; //比功率
    static float Nfsj ; //轴功率
    static float Nesj ; //电机功率
    static float Nksj ; //电机功率
    static float Vsj ; //有效容积
    static float VTsj ; //总容积


    //    24. 石灰石浆液泵

    static float Yshjb ; //效率
    static float Qshjb ; //流量
    static float Hshjb ; //扬程
    static float Nfshjb ; //轴功率
    static float Neshjb ; //电机功率
    static float Nkshjb ; //电机功率靠档




   static void setSlurryPreSystemPar(const QString &s16, const QString &s17, const QString &s18, const QString &s19,
                    const QString &s20, const QString &s21, const QString &s22, const QString &s23, const QString &s24);

};


//系统5.工艺水系统
class  processH2Osystem
{
public:


    //    25. 工艺水箱

    static float Qgy ; //单台炉耗量
    static float Tgy ; //缓冲时间
    static float Dgy ; //直径
    static float Hgy ; //高度
    static float HDgy ; //高径比
    static float VTjgy ; //计算总容积
    static float Vjgy ; //计算有效容积
    static float VTgy ; //总容积
    static float Ygy ; //有效容积


    //    26. 工艺水泵

    static float Ygyb ; //效率
    static float Qgyb ; //流量
    static float Hgyb ; //扬程
    static float Nfgyb ; //轴功率
    static float Negyb ; //电机功率
    static float Nkgyb ; //电机功率靠档



    //    27. 除雾器冲洗水泵


    static float Yccb ; //效率
    static float Qccb ; //流量
    static float Hccb ; //扬程
    static float Nfccb ; //轴功率
    static float Neccb ; //电机功率
    static float Nkccb ; //电机功率靠档

    static void setProcessH2OsystemPar(const QString &s25, const QString &s26, const QString &s27);


};
//系统6.事故浆液系统
class  emergencySlurrySystem
{
public:

    //    28. 事故浆液箱

    static float Dshg ; //直径
    static float Hshg ; //高度
    static float HDshg ; //高径比
    static float VTshg ; //总容积
    static float Vshg ; //有效容积
    static float Yshg ; //有效 总容积

    //    29. 事故浆液搅拌器

    static float Nbshg ; //比功率
    static float Nfshg ; //轴功率
    static float Neshg ; //电机功率
    static float Nkshg ; //电机功率
    static float Vjshg ; //计算有效容积
    static float VTjshg ; //计算总容积
    static int BGL(const float & JN);




    //    30. 事故浆液箱泵

    static float Yshgb ; //效率
    static float Qshgb ; //流量
    static float Hshgb ; //扬程
    static float Nfshgb ; //轴功率
    static float Neshgb ; //电机功率
    static float Nkshgb ; //电机功率靠档

    static void setEmergencySlurrySystemPar(const QString &s28, const QString &s29, const QString &s30);


};

//系统7.废水处理系统
class  wasteH2OproSystem
{
public:

    //    31. 废水泵

    static float Yfshb ; //效率
    static float Qfshb ; //流量
    static float Hfshb ; //扬程
    static float Nffshb ; //轴功率
    static float Nefshb ; //电机功率
    static float Nkfshb ; //电机功率靠档

    //    32. 废水旋流器

    static float Qfx ; //流量
    static float XZfx ; //旋流子个数

    static void setWasteH2OproSystemPar(const QString & s31, const QString & s32);

};





class Coal
{
public:
    static float Ap;    //系数
    static float bj;
    static float W;
    static float A;
    static float S;
    static float H;
    static float C;
    static float N;
    static float O;
    Coal(const float &ap, const float &bj, const float &water, const float &dust,
                           const float &s, const float &h, const float &c, const float &n, const float &o);

};



//声明变量
//static std::string version; //版本号
//static int gk ; //工况
//static std::string P ; //项目编号
//static std::string Pname ; //标题
//static std::string Peditnum ; //版次





//static int first ; //传递参数
//static int frm1 ; //窗口参数


//static int meidao ; //煤道




//static double vout1 ; //出口烟气流速  选择
//static double u1 ; //烟气流速 选择
//static double f ; //除雾器冲洗水喷嘴距除雾器间距
//static double M ; //搅拌器高度
//static double Q ; //原烟气实际流量
//static double Vn ; //净烟气总流量(湿)
//static double LG ; //L/g 液气比
//static double L ; //循环浆液量
//static double Lb ; //循环泵浆液量
//static double Lb1 ; //循环泵浆液量 取整的
//static double PD ; //喷淋塔直径
//static double PD1 ; //喷淋塔直径 圆整
//static double PZn ; //每层喷嘴数量
//static double PZl ; //喷嘴流量
//static double PDj ; //浆池直径
//static double Aj1 ; //高度1
//static double Aj2 ; //高度2
//static double A0 ; //浆液池高度min
//static double A1 ; //浆液池高度
//static double hin ; //入口高度 目标
//static double hin1 ; //入口高度 选择
//static double hout ; //出口高度 目标
//static double hout1 ; //出口高度 选择
//static double Th ; //塔的总高
//static double Tah ; //吸收区高度
//static double Ptotal ; //吸收塔总压损
//static double PPtotal ; //100%吸收塔总压损
//static double houtd ; //!!！！出口宽度 增加！！
//static double hin2 ; //！！图1为吸收塔入口高度差


//static double Duand [2]; //断点值
//static double Gas[13][8][23]; //烟气参数数组
//static double G2 [2][11]; //节点1，2 ，第一个为Nm3/h，kg/h
//static double G3 [2][11];//节点3 进吸收塔的原烟气
//static double G4 [2][11]; //节点4  出吸收塔的原烟气
//static double G5 [2][11];//节点  进GG的净烟气 ，节点6关联
//static double G6 [2][11]; //节点16 进吸收塔的氧化空气，节点15
//static double tt[4]; //不同工况温度值
//static double Xso2[3];//不同工况的SO2比例
//static double Yso2[13];//不同工况的SO2吸收率
//static double Pt[13];//不同工况的压降
//static double LG[13];//不同工况的液气比
//static int Xgas ; //数组下标值
//static int Ygas ; //节点实际值
//static int Xgsl ; //数组下标值
//static int Ygsl ; //节点实际值





//static float so2y ; //吸收塔内SO2吸收率






















//static float Vshc ; //有效容积
//static float VTshc ; //总容积

//static float Vlx ; //有效容积
//static float VTlx ; //总容积

//static float Vsjx ; //有效容积

//static float Qshg ; //单台炉耗量
//static float Tshg ; //缓冲时间







//static float VTgy ; //总容积
//static float Ygy ; //有效 总容积




//static std::string iploc ; //本机ip
//static std::string ip ; //数据库ip
//static std::string time ; //时间参数
//static std::string does ; //操作过程参数
//static std::string recid ; //记录ID
//static std::string useid ; //用户ID
//static std::string usecode ; //操作过程
//static std::string usename ; //用户名称
//static std::string uselimit ; //用户权限
//static std::string CONN ; //数据库连接字段









#endif // GLOBAL_PAR_H
