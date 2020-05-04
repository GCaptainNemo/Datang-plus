#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "par_experience.h"

float experiencePar::GGHx = 0; //回转换热器泄露率
float experiencePar::so3x = 0; //GGH中SO3x脱除率
float experiencePar::hfx = 0; //GGH中HF脱除率
float experiencePar::ashx = 0; //GGH中h脱除率
float experiencePar::so3y = 0; //吸收塔内SO2吸收率
float experiencePar::hcly = 0; //吸收塔内SO2吸收率
float experiencePar::hfy = 0; //吸收塔内SO2吸收率
float  experiencePar::ashy = 0; //吸收塔内SO2吸收率
float experiencePar::VCas = 0; //Ca /s选择（mol/mol）
float experiencePar::CaSO3CaSO42H20 = 0; //为防止石膏结垢，采用mol(CaSO3/CaSO4·2H20)
float experiencePar::YMgCO3 = 0; //石灰石中可反应的 MgCO3设置
float experiencePar::Yh2o = 0; //工艺水的溶解物的含量
float experiencePar::LSF = 0; //循环浆液安全系数
float experiencePar::YSx = 0; //压损修正系数



experiencePar::experiencePar(QSqlQuery * query)
{
    experiencePar::GGHx = query->value(1).toFloat();
    experiencePar::so3x= query->value(2).toFloat();
    experiencePar::hfx = query->value(3).toFloat();
    experiencePar::ashx = query->value(4).toFloat();
    experiencePar::so3y = query->value(5).toFloat();
    experiencePar::hcly = query->value(6).toFloat();
    experiencePar::hfy = query->value(7).toFloat();
    experiencePar::ashy = query->value(8).toFloat();
    experiencePar::VCas = query->value(9).toFloat();
    experiencePar::CaSO3CaSO42H20 = query->value(10).toFloat();
    experiencePar::YMgCO3 = query->value(11).toFloat();
    experiencePar::Yh2o = query->value(12).toFloat();
    experiencePar::LSF = query->value(13).toFloat();
    experiencePar::YSx = query->value(14).toFloat();

}
