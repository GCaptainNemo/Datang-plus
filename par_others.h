#ifndef PAR_OTHERS_H
#define PAR_OTHERS_H

#include <QString>
#include <QDebug>


class otherPar
{
public:
    static QString name;
    static QString password;
    static QString ip;
    static QString version;
    static QString prid;
    static QString userLimit;
    static void setGloabalvar(QString name, QString p, QString ip){
        otherPar::name = name;
        otherPar::password = p;
        otherPar::ip = ip;
        qDebug() << "name = "<<name << "password = "<<password << ip;
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
