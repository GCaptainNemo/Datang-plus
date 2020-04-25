#ifndef OPENWINDOW_H
#define OPENWINDOW_H

#include <QWidget>
#include <QTableWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QDateTime>

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
#include "par_others.h"


class setParObject: public QObject
{
    Q_OBJECT
signals:
//    void msgboxShowSIGNAL(const int &res);
    void finishedSIGNAL();

public slots:
    void start();

public:
//    explicit setParThread(QObject *parent=0);
    setParObject(const int &prid);


private:
    int prid;
    QSqlDatabase db;
    QSqlQuery * query;

    absorberSystem * absorberPtr;
    Equip * equipPtr;
    Coal * coalPtr;
    gasResultPar * gasResultPtr;
    gslResultPar * gslResultPtr;
//    pinfPar * pinfPtr;

    QString sqlPinf;
    QString sqlGasResult;
    QString sqlGSLResult;
    QString sqlEquip;
    QString sqlCoal;
    QString sqlExp;
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
    

public slots:
    void setLineeditTextSLOT(const QModelIndex &index);
    void openPjSLOT();


private:

    QLabel * pjLabel;
    QLineEdit * pjLineedit;
    QPushButton * openButton;
    QVBoxLayout * layout;
    QHBoxLayout * hlayout;
    QSqlTableModel * projectModel;
    QTableView * tableView;
    QSqlDatabase db;
    QSqlQueryModel * pjModel;
    void setPjModel();
    setParObject * setparTHREAD;
    QThread * myThread;
};




#endif // OPENWINDOW_H
