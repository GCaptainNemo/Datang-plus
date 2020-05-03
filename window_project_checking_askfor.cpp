#include "window_project_checking_askfor.h"

askForCheckingObject::askForCheckingObject(QWidget *parent) : QObject(parent)
{
    sqlUpdateProject = QString("UPDATE projects SET prstate = '提交校审' WHERE prid = '%1'").arg(otherPar::prid);
}

void askForCheckingObject::start()
{
    if (utils::ping(otherPar::ip)==0)
    {
        if (QSqlDatabase::contains("SQLserver"))
            this->db = QSqlDatabase::database("SQLserver");
        else{
            this->db = QSqlDatabase::addDatabase("QODBC", "SQLserver");   //数据库驱动类型为SQL Server
            QString dsn = "DRIVER={SQL SERVER};SERVER=" + otherPar::ip + ";DATABASE=p;"
                    "UID=sa;PWD=123456;";
            db.setDatabaseName(dsn);
        }

        if(!db.open())                                      //打开数据库
        {
            qDebug() << "数据库连接失败";
            emit messageboxShowSIGNAL(1);
        }
        else
        {
            qDebug() << "in";
            this->query = new QSqlQuery(this->db);
            this->query->exec(this->sqlUpdateProject);

            QString ipv4 = utils::getIPV4address();
            QDateTime curDateTime = QDateTime::currentDateTime();
            QString date = curDateTime.toString("yyyy-MM-dd hh:mm:ss");
            QString sqlMax = "SELECT MAX(recid) FROM records";
            query->exec(sqlMax);
            query->next();
            int recid = query->value(0).toInt() + 1;
            sqlInsertRecords = QString ("INSERT INTO records VALUES(%1, '%2', '%3', '%4', '提交校审项目%5')").arg(recid).
            arg(otherPar::userid).arg(ipv4).arg(date).arg(otherPar::prid);

            query->exec(sqlInsertRecords);
            emit messageboxShowSIGNAL(5);
            delete query;
        }
    }
    else
    {
         emit messageboxShowSIGNAL(3);
    }
}



