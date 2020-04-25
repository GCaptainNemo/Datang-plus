#ifndef WINDOW_PROJECT_SAVE_H
#define WINDOW_PROJECT_SAVE_H

#include <QObject>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStringList>
#include <QThread>
#include "utils.h"
#include "par_others.h"
#include <QMessageBox>
#include "par_equip.h"
#include "par_gasresult.h"
#include "par_pinf.h"
#include "par_gslresult.h"
#include "window_project_login.h"
#include "utils.h"
#include <QDateTime>

class saveObjectThread : public QObject
{
    Q_OBJECT
public:
    explicit saveObjectThread(QObject *parent = nullptr);

signals:
    void messageboxShowSIGNAL(int);

public slots:
    void start();

private:
    QSqlDatabase db;
    QString sqlVerifyPj ;
    QString sqlSaveCoal;
    QString sqlSavePinf;
    QString sqlSaveGas;
    QString sqlSaveGSL;
    QString sqlSaveEquip;
    QString sqlInsertRecord;
    QSqlQuery * query;

    void commandSave();

};

#endif // WINDOW_PROJECT_SAVE_H
