#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include "par_gasresult.h"






float gasResultPar::Gas[13][8][23] = {{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                        0,0, 0, 0}}};


gasResultPar::gasResultPar(QSqlQuery * query)
{
    qDebug() << "in gas ResultPar1";
    int t = 0;
    QStringList res = query->value(1).toString().split("*");
    for(int i=0;i <= 7; i++)
    {
        for(int j=0; j <= 22; j++){
            Gas[0][i][j] = res[t].toFloat();
            t += 1;
        }
    }
}
