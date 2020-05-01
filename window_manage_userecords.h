#ifndef WINDOW_MANAGE_USERECORES_H
#define WINDOW_MANAGE_USERECORES_H

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
//    void deleteProjectSLOT();
//    void setLineeditTextSLOT(int row);
    void nextPageSLOT();
    void previousPageSLOT();
    void firstPageSLOT();
    void lastPageSLOT();

protected:
    QLabel * passwordLabel, *dateLabel, *currentPageLabel, *totalPageLabel, *eachPageRecordsLabel, *totalRecordsLabel;

    QLineEdit * passwordLineedit, *initDateLineedit, *lastDateLineedit;
    QPushButton * deleteButton, *exportButton, *previousPageButton, *nextPageButton, *firstPageButton, *lastPageButton;
    QHBoxLayout * layout;
    QGridLayout * gridLayout;
    QTableWidget * tableWidget;
    QWidget * widget;
    QSqlDatabase db;
    QSqlQuery * query;
    int totalRecordsNum;
    void initSqlStatement(QString prid);
    void setRecordsModel();
    void start(QString prid);
private:
    QString sqlPinf, sqlEquip, sqlGas, sqlGSL, sqlCoal, sqlProject;
    void loadModel();
};

#endif // WINDOW_MANAGE_USERECORES_H
