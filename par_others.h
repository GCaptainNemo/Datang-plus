#ifndef PAR_OTHERS_H
#define PAR_OTHERS_H

#include <QString>
#include <QDebug>


class otherPar
{
public:
    static QString userid;
    static QString usercode;
    static QString username;
    static QString ip;
    static QString version;
    static QString prid;
    static QString userLimit;
    static void setGloabalvar(QString name, QString p, QString ip){
        otherPar::userid = name;
        otherPar::usercode = p;
        otherPar::ip = ip;
        qDebug() << "name = "<<name << "password = "<<usercode << ip;
    }
    static void setVersion(QString vs)
    {
        otherPar::version = vs;
    }
    static void setUsrLimit(QString usrlimit){
        otherPar::userLimit = usrlimit;
        qDebug() << "usrlimit = " << otherPar::userLimit;
    }


};



#endif // PAR_OTHERS_H
