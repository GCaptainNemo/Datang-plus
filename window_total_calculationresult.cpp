#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")

#endif
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
    this->setWindowTitle(tr("物料平衡计算结果"));

    this->initWidget1();
    this->initWidget3();
    this->initWidget4();
    font.setBold(true);


    widgetTotal = new QWidget(this);
    totalLayout = new QGridLayout(widgetTotal);
    totalLayout->addWidget(widget1, 0, 0, 1, 10);
    totalLayout->addWidget(widget3, 1, 0, 1, 5);
    totalLayout->addWidget(widget4, 1, 5, 1, 5);

    gongkuang = 0;

    totalTableSplitter = new QSplitter(Qt::Horizontal, this);
    tableWidgetGas = new QTableWidget(totalTableSplitter);
    tableWidgetLiquid = new QTableWidget(totalTableSplitter);
    totalTableSplitter ->addWidget(tableWidgetGas);
    totalTableSplitter ->addWidget(tableWidgetLiquid);
    vsplitter = new QSplitter(Qt::Vertical, this);
    vsplitter->addWidget(totalTableSplitter);
    vsplitter->addWidget(widgetTotal);
    this->initTableWidgetGas();
    this->initTableWidgetLiquid();

    layout = new QVBoxLayout(this);
    layout->addWidget(vsplitter);

    this->showMaximized();
    widgetTotal->setMaximumHeight(300);
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
    buttonGroup3 = new QButtonGroup(widget3);
    buttonGroup3->addButton(radiobutton311, 0);
    buttonGroup3->addButton(radiobutton312, 1);
    buttonGroup3->addButton(radiobutton313, 2);
    buttonGroup3->addButton(radiobutton314, 3);
    buttonGroup3->addButton(radiobutton321, 4);
    buttonGroup3->addButton(radiobutton322, 5);
    buttonGroup3->addButton(radiobutton323, 6);
    radiobutton314->setChecked(true);
    connect(buttonGroup3, SIGNAL(buttonClicked(int)), this, SLOT(chooseGongkuangSLOT(const int &)));

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
    buttonGroup4 = new QButtonGroup(widget4);
    buttonGroup4->addButton(radiobutton41, 0);
    buttonGroup4->addButton(radiobutton42, 1);
    radiobutton41->setChecked(true);
    connect(buttonGroup4, SIGNAL(buttonClicked(int)), this, SLOT(tableWidgetShowSLOT(const int&)));

    gridLayout4->addWidget(label4, 0, 0, 1, 3);
    gridLayout4->addWidget(radiobutton41, 0, 3, 1, 3);
    gridLayout4->addWidget(radiobutton42, 0, 6, 1, 3);

    qDebug() << "state2";

    label5 = new QLabel(tr("脱硫效率"), widget4);
    label5Value = new QLabel(tr(""), widget4);
    exportButton = new QPushButton(tr("导出Excel表"), widget4);
    connect(exportButton, SIGNAL(clicked(bool)), this, SLOT(exportExcelSLOT()));
    qDebug() << "state3";

    gridLayout4->addWidget(label5, 0, 9, 1, 3);
    gridLayout4->addWidget(label5Value, 0, 12, 1, 3);
    gridLayout4->addWidget(exportButton, 0, 15, 1, 3);
}



void window_total_calculationresult::chooseGongkuangSLOT(const int & id)
{

    qDebug() << "id = " << id;
    switch(id)
    {
    case 0:
        gongkuang = 3;
        break;
    case 1:
        gongkuang = 2;
        break;
    case 2:
        gongkuang = 1;
        break;
    case 3:
        gongkuang = 0;
        break;
    case 4:
        gongkuang = 6;
        break;
    case 5:
        gongkuang = 5;
        break;
    case 6:
        gongkuang = 4;
        break;
    default:
        break;
    }
    this->refreshTableWidget();
}


void window_total_calculationresult::refreshTableWidget()
{
    // 为tableWidgetGas表赋值
    tableWidgetGas->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    for(int row = 2; row < 25; row++){
        for(int column = 3; column < 11; column ++){
            qDebug() << gasResultPar::Gas[gongkuang][column - 3][row - 2];
            this->tableWidgetGas->item(row, column)->setText(QString("%1").arg(gasResultPar::Gas[gongkuang][column - 3][row - 2]));
        }
    }
    tableWidgetGas->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    // 为tableWidgetLiquid表赋值

    tableWidgetLiquid->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    for(int row = 2; row < 20; row++){
        for(int column = 2; column < 32; column ++){
            this->tableWidgetLiquid->item(row, column)->setText(QString("%1").arg(gslResultPar::GSL[gongkuang][column - 2][row - 2]));
        }
    }
    tableWidgetLiquid->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

}


void window_total_calculationresult::tableWidgetShowSLOT(const int & id)
{
    switch(id)
    {
    case 0:
        // 气相
        this->tableWidgetGas->show();
        this->tableWidgetLiquid->hide();
        break;
    case 1:
        // 液相
        this->tableWidgetLiquid->show();
        this->tableWidgetGas->hide();
        break;
    default:
        break;
    }
}

void window_total_calculationresult::initTableWidgetGas()
{
    verticalHeaderGas << "管线编号"<< "管线名称" <<"总流量(干态)" << "H2O(蒸汽)" << "H2O(液态)" << "总流量(湿)" << "总质量流量"<< "实际流量"
                   << "SO2"<< "SO3" << "O2"<< "CO2"<< "SO2"<< "SO3" << "HCl" << "HF" << "灰"<< "SO2 at 6% O2"
                   << "SOx as SO2 at 6% O2" << "SO3 at 6% O2" << "HCl at 6% O2" << "HF at 6% O2" << "Ash at 6% O2"
                   << "压力" << "温度";

    unitColumnGas <<"" << ""<<"Nm3/h" << "Nm3/h"<< "kg/h" << "Nm3/h"<< "kg/h"<< "Am3/h" << "kg/h" << "kg/h"
                << "Vol %" << "Vol %"  << "mg/Nm3"<< "mg/Nm3"<< "mg/Nm3"<< "mg/Nm3"<< "mg/Nm3"
                << "mg/Nm3"<< "mg/Nm3"<< "mg/Nm3"<< "mg/Nm3"<< "mg/Nm3"<< "mg/Nm3" << "mbar" << "°C";
    otherColumnGas << ""<< "" <<"" << ""<< "" << ""<< ""<< "" << "" << ""
                << "标态、干基、实际O2" << ""  << ""<< ""<< ""<< ""<< ""
                << ""<< ""<< ""<< ""<< ""<< "" << "" << "";

    tableWidgetGas->verticalHeader()->setHidden(true);
    tableWidgetGas->horizontalHeader()->setHidden(true);
    tableWidgetGas->setEditTriggers(QAbstractItemView::NoEditTriggers);


    this->tableWidgetGas->setRowCount(verticalHeaderGas.size());
    this->tableWidgetGas->setColumnCount(11);
    for(int i = 0; i <verticalHeaderGas.size(); i++)
    {
        if (i < 10 || i > 16){
            tableWidgetGas->setSpan(i, 0, 1, 2);

        }

        this->tableWidgetGas->setItem(i, 0, new QTableWidgetItem(verticalHeaderGas[i]));
        this->tableWidgetGas->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        this->tableWidgetGas->item(i, 0)->setFont(font);
        this->tableWidgetGas->setItem(i, 1, new QTableWidgetItem(otherColumnGas[i]));
        this->tableWidgetGas->item(i, 1)->setFont(font);
        this->tableWidgetGas->setItem(i, 2, new QTableWidgetItem(unitColumnGas[i]));
        this->tableWidgetGas->item(i, 2)->setFont(font);
        this->tableWidgetGas->item(i, 2)->setTextAlignment(Qt::AlignCenter);
    }
    tableWidgetGas->setSpan(10, 1, 7, 1);
    tableWidgetGas->setSpan(0, 0, 1, 3);
    tableWidgetGas->setSpan(1, 0, 1, 3);
    tubeidGas << "1" << "2" << "3" <<"4" << "5" << "6" << "15" << "16";
    tubeNameGas << "增压风机入口"<< "增压出口"<< "GGH原烟气出口"<< "出吸收塔的净烟气"
               << "出GGH的净烟气"<< "烟囱入口" << "氧化空气入口" << "氧化空气出口";

    for(int i=3; i<11; i++)
    {
        this->tableWidgetGas->setItem(1, i, new QTableWidgetItem(tubeNameGas[i - 3]));
        this->tableWidgetGas->item(1, i)->setFont(font);
        this->tableWidgetGas->item(1, i)->setTextAlignment(Qt::AlignCenter);
        this->tableWidgetGas->setItem(0, i, new QTableWidgetItem(tubeidGas[i - 3]));
        this->tableWidgetGas->item(0, i)->setFont(font);
        this->tableWidgetGas->item(0, i)->setTextAlignment(Qt::AlignCenter);
    }
    // 为tableWidgetGas表赋值

    for(int row = 2; row < 25; row++){
        for(int column = 3; column < 11; column ++){
            this->tableWidgetGas->setItem(row, column, new QTableWidgetItem(QString("%1").arg(gasResultPar::Gas[gongkuang][column - 3][row - 2])));
            this->tableWidgetGas->item(row, column)->setFont(font);
            this->tableWidgetGas->item(row, column)->setTextAlignment(Qt::AlignCenter);
        }
    }

    this->tableWidgetGas->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}





void window_total_calculationresult::initTableWidgetLiquid()
{
    verticalHeaderLiquid << "管线编号"<< "管线名称" <<"总质量流量" << "总体积流量" << "含可溶性盐分的H2O" << "总含固量" << "石膏"<< "亚硫酸钙"
                   << "CaCO3"<< "MgCO3" << "CaF2"<< "MgF2"<< "灰尘"<< "灰" << "惰性物质" << "溶解物质" << "氯化物含量"<< "密度"
                   << "总含固量" << "温度" ;

    unitColumnLiquid << "" << "" <<"kg/h" << "m3/h"<< "kg/h" << "kg/h"<< "kg/h"<< "kg/h" << "kg/h" << "kg/h"
                << "kg/h" << "kg/h"  << "kg/h"<< "kg/h"<< "kg/h"<< "kg/h"<< "ppm"
                << "kg/m3"<< "%"<< "°C";


    tableWidgetLiquid->setEditTriggers(QAbstractItemView::NoEditTriggers);

    tableWidgetLiquid->verticalHeader()->setHidden(true);
    tableWidgetLiquid->horizontalHeader()->setHidden(true);
    qDebug() << "size = " << verticalHeaderLiquid.size();

    this->tableWidgetLiquid->setRowCount(verticalHeaderLiquid.size());
    this->tableWidgetLiquid->setColumnCount(32);
    for(int i = 0; i <verticalHeaderLiquid.size(); i++)
    {
        this->tableWidgetLiquid->setItem(i, 0, new QTableWidgetItem(verticalHeaderLiquid[i]));
        this->tableWidgetLiquid->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        this->tableWidgetLiquid->item(i, 0)->setFont(font);
        this->tableWidgetLiquid->setItem(i, 1, new QTableWidgetItem(unitColumnLiquid[i]));
        this->tableWidgetLiquid->item(i, 1)->setFont(font);
        this->tableWidgetLiquid->item(i, 1)->setTextAlignment(Qt::AlignCenter);
    }
    this->tableWidgetLiquid->setSpan(0, 0, 1, 2);
    this->tableWidgetLiquid->setSpan(1, 0, 1, 2);

    tubeidLiquid << "20" << "22" << "23"<<"31" <<"32" << "33" <<
              "34" << "35" << "36" << "37" << "39" << "40" << "45" <<
              "46" << "50" << "55" << "56" << "58" << "59" << "60" << "61" << "63" <<
              "64" << "67" << "78" <<"84" << "85"  << "91" << "92" << "93";

    tubeNameLiquid << "石灰石仓的石灰石" << "到吸收塔的石灰石浆液" << "到石灰石浆液箱的石灰石量"
             << "从吸收塔出来的石膏浆液" << "到皮带脱水机的石膏浆液" << "石膏旋流器顶流"
             << "石膏" << "到石灰石浆液箱的滤液" << "到吸收塔的滤液" << "到废水旋流器/滤液箱的滤液"
             <<"废水旋流器底流到吸收塔" << "废水" << "废水旋流器顶流" << "废水旋流器顶流到滤液箱"
             <<"滤液" << "皮带脱水机上出来的滤液" << "皮带脱水机上出来的冲洗水" << "到除雾器的循环水"
             << "到吸收塔的循环水" << "工艺水" << "工艺水2" << "到石灰石浆液箱的工艺水"
             << "氧化空气冷却水" << "到除雾器的工艺水" << "到真空泵的工艺水" << "到皮带脱水机的冲洗水"
             << "从真空泵带走的蒸汽" << "到石灰石旋流器入口浆液" << "石灰石旋流器底流" << "石灰石旋流器顶流";

    for (int i = 0; i < 30 ; ++i)
    {
        this->tableWidgetLiquid->setItem(1, i + 2, new QTableWidgetItem(tubeNameLiquid[i]));
        this->tableWidgetLiquid->item(1, i + 2)->setFont(font);
        this->tableWidgetLiquid->item(1, i + 2)->setTextAlignment(Qt::AlignCenter);
        this->tableWidgetLiquid->setItem(0, i + 2, new QTableWidgetItem(tubeidLiquid[i]));
        this->tableWidgetLiquid->item(0, i + 2)->setFont(font);
        this->tableWidgetLiquid->item(0, i + 2)->setTextAlignment(Qt::AlignCenter);
    }

    // 为tableWidgetLiquid表赋值

    for(int row = 2; row < 20; row++){
        for(int column = 2; column < 32; column ++){
            this->tableWidgetLiquid->setItem(row, column, new QTableWidgetItem(QString("%1").arg(gslResultPar::GSL[gongkuang][column - 2][row - 2])));
            this->tableWidgetLiquid->item(row, column)->setFont(font);
            this->tableWidgetLiquid->item(row, column)->setTextAlignment(Qt::AlignCenter);
        }
    }

    this->tableWidgetLiquid->hide();
    this->tableWidgetLiquid->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}


window_total_calculationresult::~window_total_calculationresult()
{
    window_total_calculationresult::num -= 1;

}


void window_total_calculationresult::exportExcelSLOT()
{
    QString head;
    if(radiobutton311->isChecked())
    {
        head = "40%BMCR工况";
    }
    else if(radiobutton312->isChecked())
    {
        head = "50%BMCR工况";
    }
    else if(radiobutton313->isChecked())
    {
        head = "75%BMCR工况";
    }
    else if(radiobutton314->isChecked())
    {
        head = "100%BMCR工况";
    }
    else if(radiobutton321->isChecked())
    {
        head = radiobutton321->text() + "SO2浓度";
    }
    else if(radiobutton322->isChecked())
    {
        head = radiobutton322->text() + "SO2浓度";
    }
    else if(radiobutton323->isChecked())
    {
        head = radiobutton323->text() + "SO2浓度";
    }



    myexcel = new QAxObject("Excel.Application");
    //false显示窗体（看具体过程）
    myexcel->dynamicCall("SetVisible(bool)", true);
    //显示警告信息
    myexcel->setProperty("DisplayAlerts", true);
    mywork = myexcel->querySubObject("WorkBooks");
    mywork->dynamicCall("Add");
    workbook = myexcel->querySubObject("ActiveWorkBook");
    mysheet = workbook->querySubObject("Sheets");


    mysheet->dynamicCall("Add");
    QAxObject *sheet = workbook->querySubObject("ActiveSheet");
    sheet->setProperty("Name", "Sheet1");

    QAxObject *range;
    range = sheet->querySubObject("Range(QVariant, QVariant)", "A1");
    range->dynamicCall("SetValue(const QVariant&)", QVariant(head));
    range->querySubObject("Font")->setProperty("Bold", true);
    range->querySubObject("Font")->setProperty("Color", QColor(0, 0, 255));

    if (radiobutton41->isChecked())
    {
        // Gas
        for(int i = 0; i < verticalHeaderGas.size(); ++i)
        {
            range = sheet->querySubObject("Cells(int,int)", i + 2, 1);
            range->dynamicCall("SetValue(const QVariant&)", QVariant(verticalHeaderGas[i]));
            range->querySubObject("Font")->setProperty("Bold", true);

            range = sheet->querySubObject("Cells(int,int)", i + 2, 2);
            range->dynamicCall("SetValue(const QVariant&)", QVariant(otherColumnGas[i]));
            range->querySubObject("Font")->setProperty("Bold", true);

            range = sheet->querySubObject("Cells(int,int)", i + 2, 3);
            range->dynamicCall("SetValue(const QVariant&)", QVariant(unitColumnGas[i]));
            range->querySubObject("Font")->setProperty("Bold", true);

        }
        for(int i = 0; i < tubeidGas.size(); ++i)
        {
            range = sheet->querySubObject("Cells(int,int)", 2, i + 4);
            range->dynamicCall("SetValue(const QVariant&)", QVariant(tubeidGas[i]));
            range->querySubObject("Font")->setProperty("Bold", true);
            range->setProperty("HorizontalAlignment", -4108);


            range = sheet->querySubObject("Cells(int,int)", 3, i + 4);
            range->dynamicCall("SetValue(const QVariant&)", QVariant(tubeNameGas[i]));
            range->querySubObject("Font")->setProperty("Bold", true);
            range->setProperty("HorizontalAlignment", -4108);

        }
        for(int row = 4; row < 27; row++){
            for(int column = 4; column < 12; column ++){
                range = sheet->querySubObject("Cells(int,int)", row, column);
                range->dynamicCall("SetValue(const QVariant&)", QVariant(round(gasResultPar::Gas[gongkuang][column - 4][row - 3] * 100) / 100.0));
                range->setProperty("HorizontalAlignment", -4108);
                range->querySubObject("Font")->setProperty("Bold", true);

            }
        }

        QString merge_cell;

        merge_cell = "A2:C2";
        range = sheet->querySubObject("Range(const QString&)", merge_cell);
        range->setProperty("MergeCells", true);
        range->setProperty("WarpText", true);
        merge_cell = "A3:C3";
        range = sheet->querySubObject("Range(const QString&)", merge_cell);
        range->setProperty("MergeCells", true);
        range->setProperty("WarpText", true);

        for(int row = 4; row <27; row++)\
        {
            if (row < 12 || row > 18)
            {
                merge_cell = QString("A%1:B%2").arg(row).arg(row);
                range = sheet->querySubObject("Range(const QString&)", merge_cell);
                range->setProperty("MergeCells", true);
                range->setProperty("WarpText", true);
            }
        }
        merge_cell = "B12:B18";
        range = sheet->querySubObject("Range(const QString&)", merge_cell);
        range->setProperty("MergeCells", true);
        range->setProperty("WarpText", true);


    }
    else
    {
        // 液相

        for(int i = 0; i < verticalHeaderLiquid.size(); ++i)
        {
            range = sheet->querySubObject("Cells(int,int)", i + 2, 1);
            range->dynamicCall("SetValue(const QVariant&)", QVariant(verticalHeaderLiquid[i]));
            range->querySubObject("Font")->setProperty("Bold", true);


            range = sheet->querySubObject("Cells(int,int)", i + 2, 2);
            range->dynamicCall("SetValue(const QVariant&)", QVariant(unitColumnLiquid[i]));
            range->querySubObject("Font")->setProperty("Bold", true);

        }

        for(int i = 0; i < tubeidLiquid.size(); ++i)
        {
            range = sheet->querySubObject("Cells(int,int)", 2, i + 3);
            range->dynamicCall("SetValue(const QVariant&)", QVariant(tubeidLiquid[i]));
            range->querySubObject("Font")->setProperty("Bold", true);
            range->setProperty("HorizontalAlignment", -4108);

            range = sheet->querySubObject("Cells(int,int)", 3, i + 3);
            range->dynamicCall("SetValue(const QVariant&)", QVariant(tubeNameLiquid[i]));
            range->querySubObject("Font")->setProperty("Bold", true);
            range->setProperty("HorizontalAlignment", -4108);
        }

        for(int row = 4; row < 22; row++){
            for(int column = 3; column < 33; column ++){
                range = sheet->querySubObject("Cells(int,int)", row, column);
                range->dynamicCall("SetValue(const QVariant&)", QVariant(round(gslResultPar::GSL[gongkuang][column - 3][row - 4] * 100) / 100.0));
                range->setProperty("HorizontalAlignment", -4108);
                range->querySubObject("Font")->setProperty("Bold", true);
            }
        }
        QString merge_cell = "A2:B2";
        range = sheet->querySubObject("Range(const QString&)", merge_cell);
        range->setProperty("MergeCells", true);
        range->setProperty("WarpText", true);
        merge_cell = "A3:B3";
        range = sheet->querySubObject("Range(const QString&)", merge_cell);
        range->setProperty("MergeCells", true);
        range->setProperty("WarpText", true);
    }

    mysheet = workbook->querySubObject("Worksheets(int)",1);
    mysheet->querySubObject("UsedRange")->querySubObject("Columns")->dynamicCall("AutoFit");
    workbook->dynamicCall("Close()");
    myexcel->dynamicCall("Quit(void)");
    delete myexcel;

}






