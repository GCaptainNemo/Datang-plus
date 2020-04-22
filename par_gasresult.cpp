#include "par_gasresult.h"






float gasResultPar::Gas[13][8][23] = {{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                        0,0, 0, 0}}};


gasResultPar::gasResultPar(QSqlQuery * query)
{
    qDebug() << "in gas ResultPar1";
    std::string s =  query->value(1).toString().toStdString();
    int t = 0;
    std::vector<std::string> res = utils::Split(s, "[*]");
    for(int i=0;i <= 7; i++)
    {
        for(int j=0; j <= 22; j++){
            Gas[0][i][j] = std::atof(res[t].c_str()) ;
            t += 1;
        }
    }
}
