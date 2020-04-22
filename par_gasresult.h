#ifndef GASRESULT_PAR_H
#define GASRESULT_PAR_H

#include <QWidget>
#include <QSqlQuery>
#include <QVariant>
#include "utils.h"


class gasResultPar
{

public:
    gasResultPar(QSqlQuery * query);
    static float Gas[13][8][23] ;
};





#endif // GASRESULT_PAR_H
