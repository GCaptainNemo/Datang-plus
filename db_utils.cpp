# include "db_utils.h"

int dbUtils::ping(QString ip)
{
    QString strArg = "ping " + ip + " -n 1 -w 1000";
    return QProcess::execute(strArg);
}

QString dbUtils::getIPV4address()
{
    QString localHostName = QHostInfo::localHostName();
    QHostInfo info = QHostInfo::fromName(localHostName);
    QString ipv4 = "";
    foreach(QHostAddress address, info.addresses())
        {
            if(address.protocol()==QAbstractSocket::IPv4Protocol)
            {
                ipv4 = address.toString();
                qDebug() <<"My localhost IPv4 address: "<< address.toString();
                return ipv4;
            }
        }
    return ipv4;
}


//QSqlQuery dbUtils::executeSQL(QString sql, QSqlDatabase db)
QSqlQuery dbUtils::executeSQL(QString sql, int & res)

{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");   //数据库驱动类型为SQL Server
    QString dsn = "DRIVER={SQL SERVER};SERVER=" + Login_window::ip + ";DATABASE=p;"
            "UID=sa;PWD=123456;";
    db.setDatabaseName(dsn);
    QSqlQuery query(db); //查询Card表并输出，测试能否正常操作数据库
    query.exec(sql);
//    db.close();
    if (db.open())
        res = 1;
    else
        res = 0;
    return query;
}







