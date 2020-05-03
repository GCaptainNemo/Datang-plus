#ifndef WINDOW_CHECKING_ASKFOR_H
#define WINDOW_CHECKING_ASKFOR_H

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



class askForCheckingObject : public QObject
{
    Q_OBJECT
public:
    explicit askForCheckingObject(QWidget *parent = nullptr);
    void start();

signals:
    void messageboxShowSIGNAL(int num);

public slots:

protected:

    QSqlDatabase db;
    QSqlQuery * query;
    QString sqlUpdateProject, sqlInsertRecords;

};

#endif // WINDOW_CHECKING_ASKFOR_H
