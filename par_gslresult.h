#ifndef GSLRESULT_PAR_H
#define GSLRESULT_PAR_H

#include <iostream>
#include <QSqlQuery>
#include <QVariant>
#include "utils.h"



class gslResultPar
{
public:
    gslResultPar(QSqlQuery * query);
    static float GSL[13][30][18]; //浆液数组

};

#endif // GSLRESULT_PAR_H
