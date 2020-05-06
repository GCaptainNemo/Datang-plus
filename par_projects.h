#ifndef PAR_PROJECTS_H
#define PAR_PROJECTS_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif

#include <iostream>
#include <QString>

class projectPar
{
public:
    static QString pj_name;

    static int preditnum;
    static QString prstate;
    static QString prid;
    static void setPar(const QString &name, const QString &state, const int &num){
        projectPar::pj_name = name;
        projectPar::prstate = state;
        projectPar::preditnum = num;

    }
};



#endif // PAR_PROJECTS_H
