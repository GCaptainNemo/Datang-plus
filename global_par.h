#ifndef GLOBAL_PAR_H
#define GLOBAL_PAR_H

#include <vector>
#include <iterator>
#include <regex>
#include <QSqlQuery>


//namespace Coal {
//static float Ap;    //系数
//static float coal;
//static float Water;
//static float Dust;
//static float S;
//static float H;
//static float C;
//static float N;
//static float O;
//static void setCoalPar(float ap, float coal, float water, float dust,
//                       float s, float h, float c, float n, float o){
//    Coal::Ap = ap;
//    Coal::coal = coal;
//    Coal::Water = water;
//    Coal::Dust = dust;
//    Coal::S = s;
//    Coal::H = h;
//    Coal::C = c;
//    Coal::N = n;
//    Coal::O = o;
//}
//}

class Equip
{
public:
    static std::string eq1, eq2, eq3, eq4, eq5, eq6, eq7, eq8, eq9, eq10;
    static std::string eq11, eq12, eq13, eq14, eq15, eq16, eq17, eq18, eq19;
    static std::string eq20, eq21, eq22, eq23, eq24, eq25, eq26, eq27, eq28, eq29, eq30, eq31, eq32;
    static void setEquipPar(std::string e1, std::string e2, std::string e3){
        Equip::eq1 = e1;
        Equip::eq2 = e2;
        Equip::eq3 = e3;
    }
    static std::vector<std::string> s_split(const std::string& in, const std::string& delim) {
            std::regex re{ delim };
            // 调用 std::vector::vector (InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type())
            // 构造函数,完成字符串分割
            return std::vector<std::string> {
                std::sregex_token_iterator(in.begin(), in.end(), re, -1),
                std::sregex_token_iterator()
            };
        }
};


//static void setEquipPar(std::string e1, std::string e2, std::string e3, std::string e4,
//                       std::string e5, std::string e6, std::string e7, std::string e8,
//                       std::string e9, std::string e10, std::string e11, std::string e12,
//                       std::string e13, std::string e14, std::string e15, std::string e16,
//                       std::string e17, std::string e18, std::string e19, std::string e20,
//                       std::string e21, std::string e22, std::string e23, std::string e24,
//                       std::string e25, std::string e26, std::string e27, std::string e28,
//                       std::string e29, std::string e30, std::string e31, std::string e32){
//    Equip::eq1 = e1;
//    Equip::eq2 = e2;
//    Equip::eq3 = e3;
//    Equip::eq4 = e4;
//    Equip::eq5 = e5;
//    Equip::eq6 = e6;
//    Equip::eq7 = e7;
//    Equip::eq8 = e8;
//    Equip::eq9 = e9;
//    Equip::eq10 = e10;
//    Equip::eq11 = e11;
//    Equip::eq12 = e12;
//    Equip::eq13 = e13;
//    Equip::eq14 = e14;
//    Equip::eq15 = e15;
//    Equip::eq16 = e16;
//    Equip::eq17 = e17;
//    Equip::eq18 = e18;
//    Equip::eq19 = e19;
//    Equip::eq20 = e20;
//    Equip::eq21 = e21;
//    Equip::eq22 = e22;
//    Equip::eq23 = e23;
//    Equip::eq24 = e24;
//    Equip::eq25 = e25;
//    Equip::eq26 = e26;
//    Equip::eq27 = e27;
//    Equip::eq28 = e28;
//    Equip::eq29 = e29;
//    Equip::eq30 = e30;
//    Equip::eq31 = e31;
//    Equip::eq32 = e32;
//}



class Coal
{
public:
    static float Ap;    //系数
    static float coal;
    static float Water;
    static float Dust;
    static float S;
    static float H;
    static float C;
    static float N;
    static float O;
    static void setCoalPar(float ap, float coal, float water, float dust,
                           float s, float h, float c, float n, float o){
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
};







#endif // GLOBAL_PAR_H
