#ifndef WINDOW_MANAGE_USERECORES_H
#define WINDOW_MANAGE_USERECORES_H
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDateTime>
#include <QStringList>
#include <math.h>
#include <QCalendarWidget>
#include <QButtonGroup>
#include <QDate>
#include <QAxobject>
#include <QMap>
#include <string>

#include "utils.h"
#include "par_others.h"


class manageaRecordsWindow : public QDialog
{
    Q_OBJECT
public:
    explicit manageaRecordsWindow(QWidget *parent = nullptr);
    static int num;

    ~manageaRecordsWindow();

signals:

public slots:

    void deleteSLOT();
    void nextPageSLOT();
    void previousPageSLOT();
    void firstPageSLOT();
    void lastPageSLOT();
    void calenderShowSLOT(const int & id);
    void initDateLineeditSLOT(const QDate &initDate);
    void lastDateLineeditSLOT(const QDate &lastDate);
    void exportExcelSLOT();

protected:
    QLabel * passwordLabel, *dateLabel, *currentPageLabel, *totalPageLabel, *eachPageRecordsLabel, *totalRecordsLabel;
    myCalender * calenderWidget;
    QLineEdit * passwordLineedit, *initDateLineedit, *lastDateLineedit;
    QPushButton * deleteButton, *exportButton, *previousPageButton, *nextPageButton, *firstPageButton, *lastPageButton;
    QPushButton * calenderButton1, *calenderButton2;
    QButtonGroup * buttonGroup;
    QHBoxLayout * layout;
    QGridLayout * gridLayout;
    QTableWidget * tableWidget;
    QWidget * widget;
    QSqlDatabase db;
    QSqlQuery * query;


    QAxObject * myexcel;
    QAxObject * mywork;
    QAxObject * workbook;
    QAxObject * mysheet;
    int totalRecordsNum;
    void initSqlStatement(QString prid);
    void setRecordsModel();
    void start(QString prid);
private:
    QString sqlPinf, sqlEquip, sqlGas, sqlGSL, sqlCoal, sqlProject;
    QMap <int, QString> excelMap = {
        {0, "A"}, {1, "B"}, {2, "C"}, {3, "D"}, {4, "E"}
    };

    void loadModel();


};











#endif // WINDOW_MANAGE_USERECORES_H
