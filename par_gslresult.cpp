#include "par_gslresult.h"
float gslResultPar::GSL[13][30][18] = {{{0, 0, 0, 0, 0, 0, 0, 0}}};

gslResultPar::gslResultPar(QSqlQuery * query)
{
    qDebug() << "in gsl ResultPar1";
    std::string s = query->value(1).toString().toStdString();
    int t = 0;
    std::vector<std::string> res = utils::Split(s, "[*]");
    for(int i=0;i <= 29; i++)
    {
        for(int j=0; j <= 17; j++){
            GSL[0][i][j] = std::atof(res[t].c_str()) ;
            t += 1;
        }
    }
    qDebug() << "GSL[0][1][16] = " << gslResultPar::GSL[0][1][16];
}
