#ifndef WINDOW_EQUIPMENT_PARAMETER_TOTAL_H
#define WINDOW_EQUIPMENT_PARAMETER_TOTAL_H

#include <QWidget>
#include <QDialog>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QHeaderView>
#include <QStringList>
#include <QAxObject>
#include <QMap>


#include "par_equip.h"
#include "widget_okcancel.h"
#include "par_pinf.h"

class window_total_equipment_parameter : public QDialog
{
    Q_OBJECT
public:
    explicit window_total_equipment_parameter(QWidget *parent = nullptr);
    static int num;
    ~window_total_equipment_parameter();

signals:

public slots:
    void exportSLOT();
protected:
    QTableWidget * tableWidget;
    QGridLayout * layout;
    widget_okcancel * buttonWidget;
    void initTableWidget();
    QStringList equipNameStringList;
    QStringList rowheadStringList;
    QStringList columnheadStringList;
    QStringList specificationStringList;
    QStringList equipNumStringList;
    QAxObject * myexcel, *mywork, *workbook, *mysheet;
    QMap <int, QString> excelMap = {
        {0, "A"}, {1, "B"}, {2, "C"}, {3, "D"}, {4, "E"}

    };
    void judgePop();
};

#endif // WINDOW_EQUIPMENT_PARAMETER_TOTAL_H
