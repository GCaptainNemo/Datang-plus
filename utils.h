#ifndef DATABASE_UTILS_H
#define DATABASE_UTILS_H

# include <QProcess>
#include <QMessageBox>
#include<QSqlError>
#include<QSqlDatabase>

#include <vector>
#include <iterator>
#include <regex>
#include <QComboBox>
# include "window_project_login.h"

namespace utils{

    int ping(QString ip);
    QSqlQuery executeSQL(QString sql, int&res);
    QString getIPV4address();
    std::vector<std::string> Split(const std::string& in, const std::string& delim);
    float YL(const float &DJ);
    void setKdComboBox(QComboBox * kdComboBox, const float &nkshpb);
    float KD(float & power);



}


#endif // DATABASE_UTILS_H