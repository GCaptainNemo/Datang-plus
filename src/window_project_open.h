﻿#ifndef OPENWINDOW_H
#define OPENWINDOW_H
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include <QWidget>
#include <QTableWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QDateTime>
#include <QHeaderView>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QTableView>
#include <QThread>

#include "par_equip.h"
#include "par_gasresult.h"
#include "par_gslresult.h"
#include "par_pinf.h"
#include "par_projects.h"
#include "par_experience.h"
#include "par_users.h"


class mySqlQueryModel: public QSqlQueryModel
{
public:
    explicit mySqlQueryModel(QObject * parent = nullptr);
    QVariant data(const QModelIndex & index, int role) const;

};




class openPjWindow : public QDialog
{
    Q_OBJECT
public:
    static int num;
    explicit openPjWindow(QWidget *parent = nullptr);
    ~openPjWindow();


signals:
    void threadStart(int p);
    void finishedSIGNAL();


public slots:
    void setLineeditTextSLOT(const QModelIndex &index);
    void openPjSLOT();


private:

    // sql statment


    QString sqlPinf;
    QString sqlGasResult;
    QString sqlGSLResult;
    QString sqlEquip;
    QString sqlCoal;
    QString sqlExp;

    // parameter

    absorberSystem * absorberPtr;
    equipPar * equipPtr;
    Coal * coalPtr;
    gasResultPar * gasResultPtr;
    gslResultPar * gslResultPtr;

    // layout

    QLabel * pjLabel;
    QLineEdit * pjLineedit;
    QPushButton * openButton;
    QVBoxLayout * layout;
    QHBoxLayout * hlayout;
    QSqlTableModel * projectModel;
    QTableView * tableView;
    QSqlDatabase db;
    QSqlQueryModel * pjModel;
    QWidget * widget;
    QThread * myThread;

    QSqlQuery * query;
    void initSqlStatement(QString prid);
    void setPjModel();
    void start(QString prid);
};




#endif // OPENWINDOW_H
