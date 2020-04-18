#ifndef DATABASE_UTILS_H
#define DATABASE_UTILS_H

# include <QProcess>
#include <QMessageBox>
#include<QSqlError>
#include<QSqlDatabase>
# include "login_window.h"

namespace dbUtils{

int ping(QString ip);
QSqlQuery executeSQL(QString sql, int&res);
QString getIPV4address();
}


#endif // DATABASE_UTILS_H
