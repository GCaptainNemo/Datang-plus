#ifndef WINDOW_TOTAL_CALCULATIONRESULT_H
#define WINDOW_TOTAL_CALCULATIONRESULT_H

#include <QWidget>
#include <QDialog>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QHeaderView>
#include <QStringList>
#include <QRadioButton>
#include <QButtonGroup>
#include <QLabel>
#include <QLineEdit>
#include <QAxObject>
#include <QMap>
#include <QSplitter>
#include <QDebug>

#include "par_equip.h"
#include "widget_okcancel.h"
#include "par_pinf.h"




class window_total_calculationresult : public QDialog
{
    Q_OBJECT
public:
    explicit window_total_calculationresult(QWidget *parent = nullptr);
    static int num;
    ~window_total_calculationresult();

signals:

public slots:
    void exportSLOT();
protected:
    QVBoxLayout * layout;
    QWidget * totalTableWidget;
    QTableWidget * tableWidgetGas, *tableWidgetLiquid;

    QWidget *widgetTotal, *widget1, *widget3, *widget4;
    QPushButton * okButton1, *okButton2, *okButton3;

    QLabel * label1, * label11, * label12, * label13, *label2, *label21, *label22,*label23;
    QLineEdit * lineedit11, *lineedit12,* lineedit13, * lineedit21, *lineedit22, *lineedit23;

    QLabel * label31, *label32;
    QRadioButton * radiobutton311, *radiobutton312, *radiobutton313, *radiobutton314;
    QRadioButton * radiobutton321, *radiobutton322, *radiobutton323;

    QLabel *  label4;
    QRadioButton * radiobutton41, *radiobutton42;
    QButtonGroup * buttonGroup4;

    QLabel * label5, *label5Value;
    QPushButton * exportButton;

    QSplitter * vsplitter;

    QGridLayout * tableWidgetLayout, *totalLayout, *gridLayout1, *gridLayout3, *gridLayout4;
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
    void initWidget1();
    void initWidget2();
    void initWidget3();
    void initWidget4();
    void initWidget5();


};


#endif // WINDOW_TOTAL_CALCULATIONRESULT_H
