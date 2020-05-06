#ifndef GSLRESULT_PAR_H
#define GSLRESULT_PAR_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif

#include <iostream>
#include <QSqlQuery>
#include <QVariant>
#include <QStringList>
#include "utils.h"



class gslResultPar
{
public:
    gslResultPar(QSqlQuery * query);
    static float GSL[13][30][18]; //浆液数组

};

#endif // GSLRESULT_PAR_H
