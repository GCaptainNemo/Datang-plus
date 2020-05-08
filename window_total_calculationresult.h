#ifndef WINDOW_TOTAL_CALCULATIONRESULT_H
#define WINDOW_TOTAL_CALCULATIONRESULT_H
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
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
#include <QHeaderView>


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
    void exportExcelSLOT();
    void tableWidgetShowSLOT(const int & id);
    void chooseGongkuangSLOT(const int & id);
protected:
    QVBoxLayout * layout;
    QSplitter * totalTableSplitter;
    QTableWidget * tableWidgetGas, *tableWidgetLiquid;

    QWidget *widgetTotal, *widget11, *widget12, *widget3, *widget4;
    QPushButton * okButton1, *okButton2, *okButton3;


    QLabel * label1, * label11, * label12, * label13, *label2, *label21, *label22,*label23;
    QLineEdit * lineedit11, *lineedit12,* lineedit13, * lineedit21, *lineedit22, *lineedit23;

    QLabel * label31, *label32;
    QRadioButton * radiobutton311, *radiobutton312, *radiobutton313, *radiobutton314;
    QRadioButton * radiobutton321, *radiobutton322, *radiobutton323;
    QButtonGroup * buttonGroup3;


    QLabel *  label4;
    QRadioButton * radiobutton41, *radiobutton42;
    QButtonGroup * buttonGroup4;

    QLabel * label5, *label5Value;
    QPushButton * exportButton;

    QSplitter * vsplitter;

    QGridLayout  *totalLayout, *gridLayout11, *gridLayout12, *gridLayout3, *gridLayout4;

    QStringList tubeidLiquid;
    QStringList tubeNameLiquid;
    QStringList verticalHeaderLiquid;
    QStringList unitColumnLiquid;

    QStringList tubeidGas;
    QStringList tubeNameGas;
    QStringList verticalHeaderGas;
    QStringList unitColumnGas;
    QStringList otherColumnGas;

    QFont font ;//定义一个字体变量
    int gongkuang;

    QAxObject * myexcel, *mywork, *workbook, *mysheet;
    QMap <int, QString> excelMap = {
        {0, "A"}, {1, "B"}, {2, "C"}, {3, "D"}, {4, "E"}
    };
    void initWidget1();
    void initWidget3();
    void initWidget4();

    void initTableWidgetGas();
    void initTableWidgetLiquid();
    void refreshTableWidget();
};


#endif // WINDOW_TOTAL_CALCULATIONRESULT_H
