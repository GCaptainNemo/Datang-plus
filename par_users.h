#ifndef PAR_USERS_H
#define PAR_USERS_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif

#include <QString>
#include <QDebug>


class userPar
{
public:
    static QString userid;
    static QString usercode;
    static QString username;
    static QString userip;
    static QString version;
    static QString userLimit;
    static void setGloabalvar(QString name, QString p, QString ip){
        userPar::userid = name;
        userPar::usercode = p;
        userPar::userip = ip;
        qDebug() << "name = "<<name << "password = "<<usercode << ip;
    }

};



#endif // PAR_USERS_H
