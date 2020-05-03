#include "window_total_calculationresult.h"

int window_total_calculationresult::num = 0;

window_total_calculationresult::window_total_calculationresult(QWidget *parent) : QDialog(parent)
{
    qDebug() << "in window::";
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinMaxButtonsHint;
    flags |=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);
    window_total_calculationresult::num += 1;
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle(tr("设备参数汇总"));

    this->initWidget1();
    this->initWidget3();
    this->initWidget4();


    widgetTotal = new QWidget(this);
    totalLayout = new QGridLayout(widgetTotal);
    totalLayout->addWidget(widget1, 0, 0, 1, 10);
    totalLayout->addWidget(widget3, 1, 0, 1, 10);
    totalLayout->addWidget(widget4, 2, 0, 1, 10);

//    widgetTotal->setFixedSize(800, 200);



    totalTableWidget = new QWidget(this);
    tableWidgetGas = new QTableWidget(totalTableWidget);
    tableWidgetLiquid = new QTableWidget(totalTableWidget);
    tableWidgetLayout = new QGridLayout(totalTableWidget);
    tableWidgetLayout->addWidget(tableWidgetGas, 0, 0, 10, 10);
    tableWidgetLayout->addWidget(tableWidgetLiquid, 0, 10, 10, 10);
    vsplitter = new QSplitter(Qt::Vertical, this);
    vsplitter->addWidget(totalTableWidget);
    vsplitter->addWidget(widgetTotal);
    layout = new QVBoxLayout(this);
    layout->addWidget(vsplitter);

    this->showMaximized();
}

void window_total_calculationresult::initWidget1()
{
    widget1 = new QWidget(this);
    gridLayout1 = new QGridLayout(widget1);
    okButton1 = new QPushButton(tr("确定"), widget1);
    label1 = new QLabel(tr("不同工况温度输入:"), widget1);
    lineedit11 = new QLineEdit(widget1);
    lineedit12 = new QLineEdit(widget1);
    lineedit13 = new QLineEdit(widget1);
    label11 = new QLabel(tr("°C"), widget1);
    label12 = new QLabel(tr("°C"), widget1);
    label13 = new QLabel(tr("°C"), widget1);
    gridLayout1->addWidget(label1, 0, 0, 1, 3);
    gridLayout1->addWidget(lineedit11, 0, 3, 1, 3);
    gridLayout1->addWidget(label11, 0, 6, 1, 1);
    gridLayout1->addWidget(lineedit12, 0, 7, 1, 3);
    gridLayout1->addWidget(label12, 0, 10, 1, 1);
    gridLayout1->addWidget(lineedit13, 0, 11, 1, 3);
    gridLayout1->addWidget(label13, 0, 15, 1, 1);
    gridLayout1->addWidget(okButton1, 0, 16, 1, 3);

    okButton2 = new QPushButton(tr("确定"), widget1);
    label2 = new QLabel(tr("不同SO2浓度输入:"), widget1);
    lineedit21 = new QLineEdit(widget1);
    lineedit22 = new QLineEdit(widget1);
    lineedit23 = new QLineEdit(widget1);
    label21 = new QLabel(tr("%"), widget1);
    label22 = new QLabel(tr("%"), widget1);
    label23 = new QLabel(tr("%"), widget1);
    gridLayout1->addWidget(label2, 0, 19, 1, 3);
    gridLayout1->addWidget(lineedit21, 0, 22, 1, 3);
    gridLayout1->addWidget(label21, 0, 25, 1, 1);
    gridLayout1->addWidget(lineedit22, 0, 26, 1, 3);
    gridLayout1->addWidget(label22, 0, 29, 1, 1);
    gridLayout1->addWidget(lineedit23, 0, 30, 1, 3);
    gridLayout1->addWidget(label23, 0, 33, 1, 1);
    gridLayout1->addWidget(okButton2, 0, 34, 1, 3);

}


void window_total_calculationresult::initWidget3()
{
    qDebug() << "in widget3";
    widget3 = new QWidget(this);
    gridLayout3 = new QGridLayout(widget3);
    label31 = new QLabel(tr("不同工况:"), widget3);
    label32 = new QLabel(tr("不同SO2浓度:"), widget3);

    radiobutton311 = new QRadioButton(tr("40%"), widget3);
    radiobutton312 = new QRadioButton(tr("50%"), widget3);
    radiobutton313 = new QRadioButton(tr("75%"), widget3);
    radiobutton314 = new QRadioButton(tr("100%"), widget3);

    radiobutton321 = new QRadioButton(tr("30%"), widget3);
    radiobutton322 = new QRadioButton(tr("75%"), widget3);
    radiobutton323 = new QRadioButton(tr("150%"), widget3);

    gridLayout3->addWidget(label31, 0, 0, 1, 3);
    gridLayout3->addWidget(radiobutton311, 0, 3, 1, 3);
    gridLayout3->addWidget(radiobutton312, 0, 6, 1, 3);
    gridLayout3->addWidget(radiobutton313, 0, 9, 1, 3);
    gridLayout3->addWidget(label32, 1, 0, 1, 3);
    gridLayout3->addWidget(radiobutton321, 1, 3, 1, 3);
    gridLayout3->addWidget(radiobutton322, 1, 6, 1, 3);
    gridLayout3->addWidget(radiobutton323, 1, 9, 1, 3);
    gridLayout3->addWidget(radiobutton314, 0, 12, 2, 3);

}

void window_total_calculationresult::initWidget4()
{
    qDebug() << "state1";
    widget4 = new QWidget(this);
    gridLayout4 = new QGridLayout(widget4);
    label4 = new QLabel(tr("表格选择"), widget4);
    radiobutton41 = new QRadioButton(tr("气相"), widget4);
    radiobutton42 = new QRadioButton(tr("液相"), widget4);
    gridLayout4->addWidget(label4, 0, 0, 1, 3);
    gridLayout4->addWidget(radiobutton41, 0, 3, 1, 3);
    gridLayout4->addWidget(radiobutton42, 0, 6, 1, 3);

    qDebug() << "state2";

    label5 = new QLabel(tr("脱硫效率"), widget4);
    label5Value = new QLabel(tr(""), widget4);
    exportButton = new QPushButton(tr("导出Excel表"), widget4);

    qDebug() << "state3";

    gridLayout4->addWidget(label5, 0, 9, 1, 3);
    gridLayout4->addWidget(label5Value, 0, 12, 1, 3);
    gridLayout4->addWidget(exportButton, 0, 15, 1, 3);
}


//void window_total_calculationresult::initWidget5()
//{
//    widget5 = new QWidget(this);
//    gridLayout5 = new QGridLayout(widget5);
//    label5 = new QLabel(tr("脱硫效率"), widget5);
//    label5Value = new QLabel(tr(""), widget5);
//    exportButton = new QPushButton(tr("导出Excel表"), widget5);

//    gridLayout5->addWidget(label5, 0, 0, 1, 3);
//    gridLayout5->addWidget(label5Value, 0, 3, 1, 3);
//    gridLayout5->addWidget(exportButton, 0, 6, 1, 3);
//}

window_total_calculationresult::~window_total_calculationresult()
{
    window_total_calculationresult::num -= 1;

}


void window_total_calculationresult::exportSLOT()
{


}






