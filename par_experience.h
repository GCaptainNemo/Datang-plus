#ifndef PAR_EXPERIENCE_H
#define PAR_EXPERIENCE_H

#include <QSqlQuery>
#include <QVariant>

class experiencePar
{
public:
    experiencePar(QSqlQuery * query);
    static float GGHx ; //回转换热器泄露率
    static float so3x ; //GGH中SO3x脱除率
    static float hfx ; //GGH中HF脱除率
    static float ashx ; //GGH中h脱除率
    static float so3y ; //吸收塔内SO2吸收率
    static float hcly ; //吸收塔内SO2吸收率
    static float hfy ; //吸收塔内SO2吸收率
    static float  ashy; //吸收塔内SO2吸收率
    static float VCas ; //Ca /s选择（mol/mol）
    static float CaSO3CaSO42H20; //为防止石膏结垢，采用mol(CaSO3/CaSO4·2H20)
    static float YMgCO3; //石灰石中可反应的 MgCO3设置
    static float Yh2o ; //工艺水的溶解物的含量
    static float LSF ; //循环浆液安全系数
    static float YSx ; //压损修正系数



};

#endif // PAR_EXPERIENCE_H
