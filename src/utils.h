﻿#ifndef DATABASE_UTILS_H
#define DATABASE_UTILS_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif

# include <QProcess>
#include <QMessageBox>
#include<QSqlError>
#include<QSqlDatabase>

#include <vector>
#include <iterator>
#include <regex>
#include <QComboBox>
#include <QHostInfo>
#include <QHBoxLayout>
#include <QPushButton>
#include <QCalendarWidget>
#include <QAxObject>
#include <QFile>
#include <QDir>

#include "par_users.h"


class myCalender :public QCalendarWidget
{
public:
    static int calenderNum;
    explicit myCalender(QWidget * parent=nullptr);
    ~myCalender();

};

class ExcelExport
{
public:
    ExcelExport();
    ~ExcelExport();

    void newExcel(const QString &fileName);
    void setCellValue(int row, int column, const QString &value);
    void setCellValue(int row, int column, const int &value);

    void saveExcel(const QString &fileName);


    QAxObject *pApplication;
    QAxObject *pWorkBooks;
    QAxObject *pWorkBook;
    QAxObject *pSheets;
    QAxObject *pSheet;

};



namespace utils{

    int ping(QString ip);
    QString getIPV4address();
    float YL(const float &DJ);
    void setKdComboBox(QComboBox * kdComboBox, const float &nkshpb);
    float KD(float & power);
}




#endif // DATABASE_UTILS_H
