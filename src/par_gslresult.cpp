#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "par_gslresult.h"
float gslResultPar::GSL[13][30][18] = {{{0, 0, 0, 0, 0, 0, 0, 0}}};

gslResultPar::gslResultPar(QSqlQuery * query)
{
    qDebug() << "in gsl ResultPar1";
    int t = 0;
    QStringList res =  query->value(1).toString().split("*");
    for(int i=0; i < 30; i++)
    {
        for(int j=0; j < 18; j++){
            GSL[0][i][j] = res[t].toFloat();
            t += 1;
        }
    }
    qDebug() << "GSL[0][1][16] = " << gslResultPar::GSL[0][1][16];
}
